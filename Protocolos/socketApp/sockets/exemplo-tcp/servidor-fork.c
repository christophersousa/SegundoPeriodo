#include <signal.h>
#include <errno.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/wait.h>
#include "sockets.h"

void erro(char *erromsg)
{
	fprintf(stderr, "%s: %s\n", erromsg, strerror(errno));
	exit(1);
}

void processar_cliente(int sockfd)
{
	char msgServer[MAX_MSG];
	int n_bytes;

	while ((n_bytes = recv(sockfd, msgServer, sizeof(msgServer), 0)) != 0) {
		if (n_bytes < 0) {
			fprintf(stderr, "Erro na recepcao: %s\n", strerror(errno));
			break;
		}
		msgServer[n_bytes] = '\0';	// Adiciona terminador de string
		printf("[Processo %d] Recebi \"%s\"\n", getpid(), msgServer);
		if (send(sockfd, msgServer, n_bytes, 0) < 0)
			erro("Erro no envio");
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
	int pid;
	int status;

	/* Coloca o handler de SIGINT ativo */
	memset(&sa, 0, sizeof(sa));
	sa.sa_handler = sigHandler;
	sigaction(SIGINT, &sa, NULL);

	puts("Servidor de Echo (TCP) ...");
	/* Cria sockect TCP ----------------------------------------------------- */
	if ((sockAcesso = socket(AF_INET, SOCK_STREAM, 0)) < 0) erro("Erro no socket");
	/* Regista endereco local de modo a que os clientes nos possam contactar  */
	serv_addr.sin_family = AF_INET; 								/* Endereco da familia IP */
	serv_addr.sin_addr.s_addr = htonl(INADDR_ANY); 	/* de qualquer endereco   */
	serv_addr.sin_port = htons(SERVER_TCP_PORT); 		/* Porta do servico       */
	/* Bind do socket ------------------------------------------------------- */
	if (bind(sockAcesso, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0)
		erro("Erro no bind");
	/* Listen - Ativa socket com fila de espera de dimensao 50 -------------- */
	if (listen(sockAcesso, 50) < 0) erro("Erro no listen");
	for (;;) {
		printf("[Processo %d] Aguardando cliente... (CTRL-C para terminar)\n", getpid());
		sockConexao = accept(sockAcesso, (struct sockaddr *)&cli_addr, &tam_addr);
		if (sockConexao < 0) {
			if (errno == EINTR) break; /* CTRL-C recebido */
			else erro("Erro no accept");
		}
		if ((pid = fork()) == 0) {
			/* Processo Filho */
			close(sockAcesso);
			processar_cliente(sockConexao);
			exit(0);
		} else if (pid < 0) {
			fprintf(stderr, "Impossível criar processo filho para tratar conexão\n");
		} else {
			/* Processo Pai */
			printf("Ligacao estabelecida. Processo %d...\n", pid);
		}
		close(sockConexao);
	} /* End for */
	close(sockAcesso);
	puts("Aguarda fim dos processos filhos...");
	waitpid(0, &status, 0);
	puts("Fim do servidor...");
}
