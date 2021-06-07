#include <signal.h>
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
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
			if (errno != EINTR)
				fprintf(stderr, "Erro na recepcao: %s\n", strerror(errno));
			break;
		}
		printf("[Processo %d] Recebi \"%s\"\n", getpid(), msgServer);
		if (send(sockfd, msgServer, strlen(msgServer)+1, 0) < 0)
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
	int sockAcesso;
 	socklen_t tam_addr = sizeof(serv_addr);
	struct sigaction sa;

	/* Coloca o handler de SIGINT ativo */
	memset(&sa, 0, sizeof(sa));
	sa.sa_handler = sigHandler;
	sigaction(SIGINT, &sa, NULL);

	puts("Servidor de Echo (UDP) ...");
	/* Cria sockect UDP ----------------------------------------------------- */
	if ((sockAcesso = socket(AF_INET, SOCK_DGRAM, 0)) < 0) erro("Erro no socket");
	/* Regista endereco local de modo a que os clientes nos possam contactar  */
	serv_addr.sin_family = AF_INET; 								/* Endereco da familia IP */
	serv_addr.sin_addr.s_addr = htonl(INADDR_ANY); 	/* de qualquer endereco   */
	serv_addr.sin_port = htons(SERVER_TCP_PORT); 		/* Porta do servico       */
	/* Regista endereco remoto de modo a enviar dados para os clientes  	    */
	cli_addr.sin_family = AF_INET; 									/* Endereco da familia IP */
	cli_addr.sin_addr.s_addr = htonl(INADDR_ANY); 	/* de qualquer endereco   */
	cli_addr.sin_port = htons(SERVER_TCP_PORT+100); /* Porta do servico       */
	/* Bind do socket ------------------------------------------------------- */
	if (bind(sockAcesso, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0)
		erro("Erro no bind");
	printf("[Processo %d] Aguardando cliente... (CTRL-C para terminar)\n", getpid());
 	if (connect(sockAcesso, (struct sockaddr *)&cli_addr, sizeof(cli_addr)) < 0)
		erro("Erro em connect");

	processar_cliente(sockAcesso);
	close(sockAcesso);
	puts("Fim do servidor...");
}
