#include <signal.h>
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <string.h>
#include "sockets.h"

#define MAX_THREAD 100

int clientesConectados[MAX_THREAD];
int nClientes = 0;
int nThreads = 0;

void erro(char *erromsg)
{
	fprintf(stderr, "%s: %s\n", erromsg, strerror(errno));
	exit(1);
}

void *processar_cliente(void *psockfd)
{
	char msgServer[MAX_MSG];
	int n_bytes;
	int sockfd = *(int *)psockfd;
	int c;

	while ((n_bytes = recv(sockfd, msgServer, sizeof(msgServer), 0)) != 0) {
		if (n_bytes < 0) {
			fprintf(stderr, "Erro na recepcao: %s\n", strerror(errno));
			break;
		}
		msgServer[n_bytes] = '\0';	// Adiciona terminador de string
		printf("[Processo %d] Recebi \"%s\"\n", getpid(), msgServer);
		for (c = 0; c < nClientes; ++c) {
			if (send(clientesConectados[c], msgServer, n_bytes, 0) < 0)
				erro("Erro no envio");
		}
	}
	/* Elimina socket do vetor */
	for (c = 0; c < nClientes; ++c) {
		if (clientesConectados[c] == sockfd) {
			while (c < nClientes-1) {
				clientesConectados[c] = clientesConectados[c+1];
				++c;
			}
			--nClientes;
		}
	}
	printf("[Processo %d] Tarefas Concluidas...\n",  getpid());
	close(sockfd);
}

void sigHandler(int signum)
{
}

int main( )
{
	struct sockaddr_in serv_addr, cli_addr;
	int sockAcesso, sockConexao;
 	socklen_t tam_addr = sizeof(serv_addr);
	struct sigaction sa;
	pthread_t vth[MAX_THREAD];
	pthread_t th;
	int i;

	/* Colocar o handler de SIGINT activo */
	memset(&sa, 0, sizeof(sa));
	sa.sa_handler = sigHandler;
	sigaction(SIGINT, &sa, NULL);

	puts("Servidor de Echo (TCP) ...");
	/* Criar sockect TCP --------------------------------------------------- */
	if ((sockAcesso = socket(AF_INET, SOCK_STREAM, 0)) < 0) erro("Erro no socket");
	/* Registar endereco local de modo a que os clientes nos possam contactar */
	serv_addr.sin_family = AF_INET;                 /* Endereco da familia IP */
	serv_addr.sin_addr.s_addr = htonl(INADDR_ANY);  /* de qualquer endereco   */
	serv_addr.sin_port = htons(SERVER_TCP_PORT);    /* Porta do servico       */
	/* Bind do socket --------------------------------------------------- */
	if (bind(sockAcesso, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0)
		erro("Erro no bind");
	/* Listen - Ativar socket com fila de espera de dimensao 50 --------- */
	if (listen(sockAcesso, 50) < 0) erro("Erro no listen");
	for (;;) {
		printf("[Processo %d] Aguardando cliente... (CTRL-C para terminar)\n", getpid());
		sockConexao = accept(sockAcesso, (struct sockaddr *)&cli_addr, &tam_addr);
		if (sockConexao < 0) {
			if (errno == EINTR) break; /* CTRL-C recebido */
			else erro("Erro no accept");
		}
		puts("Ligacao estabelecida...");
		if (pthread_create(&th, NULL, processar_cliente, &sockConexao) == 0)
			vth[nThreads++] = th;
			clientesConectados[nClientes++] = sockConexao;
	} /* End for */
	close(sockAcesso);
	puts("Aguardando termino das threads....");
	for (i = 0; i < nThreads; ++i) {
		pthread_join(vth[i], NULL);
	}
	puts("Fim do servidor....");
}
