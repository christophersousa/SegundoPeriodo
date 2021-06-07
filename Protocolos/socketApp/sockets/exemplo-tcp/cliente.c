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
	struct sockaddr_in serv_addr;
	char *hostServer;

	if (argc == 1) hostServer = "localhost";
	else hostServer = argv[1];
	puts("Cliente TCP do servico de Echo...");
	/* Abrir um socket TCP (an Internet Stream socket) */
	if ((sockConexao = socket(AF_INET, SOCK_STREAM, 0)) < 0)
		erro("Erro no socket");
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
	serv_addr.sin_port = htons(SERVER_TCP_PORT);
	puts("Estabelecendo a ligacao ...");
	if (connect(sockConexao, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0)
		erro("Erro em connect");
	puts("Ligacao estabelecida com o servidor...");
	for(;;) {
		printf("Mensagem a enviar (CTRL-D para terminar): ");
		if (fgets(msgServ, sizeof(msgServ) - 1, stdin) == NULL) break;
		msgServ[strlen(msgServ)-1] = '\0'; // Descarta new-line
		printf("Enviando mensagem \"%s\"\n", msgServ);
		if (send(sockConexao, msgServ, strlen(msgServ), 0) < 0)
			erro("Erro no envio");
		if ((n_bytes = recv(sockConexao, msgRec, sizeof(msgRec), 0)) > 0) {
			msgRec[n_bytes] = '\0';
			printf("Mensagem retornada: %s\n", msgRec);
		} else if (n_bytes == 0) {
			fprintf(stderr, "Nada recebido. Servidor pode estar inativo...\n");
		} else {
			erro("Erro na recepcao");
		}
	} 
	puts("\nCliente terminou\n");
	close(sockConexao);
}
