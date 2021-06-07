#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include "sockets.h"

void erro(char *erromsg)
{
	fprintf(stderr, "%s: %s\n", erromsg, strerror(errno));
	exit(1);
}

int main (int argc, char *argv[])
{
	int n_bytes, sockConexao;
	char msgRec[MAX_MSG];
	char msgServ[MAX_MSG];
	struct sockaddr_in serv_addr, cli_addr;
	socklen_t tam_addr = sizeof(cli_addr);
	char *hostServer;

	if (argc == 1) hostServer = "localhost";
	else hostServer = argv[1];
	puts("Cliente UDP do servico de Echo...");
	/* Abrir um socket UDP */
	if ((sockConexao = socket(AF_INET, SOCK_DGRAM, 0)) < 0)
		erro("Erro no socket");
	
	/* Preencher a estrutura cli_addr com o endereco do cliente */
	cli_addr.sin_family = AF_INET;                 		/* Endereco da familia IP */
	cli_addr.sin_addr.s_addr = htonl(INADDR_ANY);  		/* de qualquer endereco   */
	//cli_addr.sin_port = htons(SERVER_UDP_PORT+100); /* Porta do servico       */
	cli_addr.sin_port = htons(INADDR_ANY); 						/* Porta do servico       */
	/* Bind do socket --------------------------------------------------------- */
	if (bind(sockConexao, (struct sockaddr *)&cli_addr, sizeof(cli_addr)) < 0)
		erro("Erro no bind");
	
	/* Preencher a estrutura serv_addr com o endereco do
	   servidor que pretendemos contactar */
	serv_addr.sin_family = AF_INET;
	if (inet_aton(hostServer, &serv_addr.sin_addr) == 0) {
		struct hostent *he;
		if ((he = gethostbyname(hostServer)) == NULL) {
			fprintf(stderr, "%s: Host nao acessivel\n", hostServer);
			exit(1);
		}
		serv_addr.sin_addr = *(struct in_addr *)he->h_addr;
	}
	serv_addr.sin_port = htons(SERVER_UDP_PORT);

	for(;;) {
		printf("Mensagem a enviar (CTRL-D para terminar): ");
		if (fgets(msgServ, sizeof(msgServ) - 1, stdin) == NULL) break;
		msgServ[strlen(msgServ)-1] = '\0'; // Descarta new-line
		printf("Enviando mensagem \"%s\"\n", msgServ);
		if (sendto(sockConexao, msgServ, strlen(msgServ), 0, 
		    (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0)
			erro("Erro no envio");
		if ((n_bytes = recvfrom(sockConexao, msgRec, sizeof(msgRec), 0, 
		    (struct sockaddr *)&serv_addr, &tam_addr)) < 0)
			erro("Erro na recepcao");
		if (n_bytes > 0) {
			msgRec[n_bytes] = '\0'; // Adiciona terminador de string
			printf("Mensagem retornada: %s\n", msgRec);
		} else {
			fprintf(stderr, "Nada recebido. Servidor pode estar inativo...\n");
		}
	} 
	puts("\nCliente terminou\n");
	close(sockConexao);
}
