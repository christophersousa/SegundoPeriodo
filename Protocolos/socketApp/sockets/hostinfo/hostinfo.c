#include <stdio.h>
#include <stdlib.h>
#include <netdb.h>
#include <ctype.h>
#include <arpa/inet.h>

void erro(char *erromsg)
{
	fprintf(stderr, "%s: %s\n", erromsg, hstrerror(h_errno));
	exit(1);
}

int main(int argc, char * argv[])
{
	struct hostent *shost; 
	struct in_addr haddr; 
	char *hostname, **p; int i;

	if (argc == 1) hostname = "localhost";
	else hostname = argv[1];
	printf("Host: %s\n", hostname);
 	if (inet_aton(hostname, &haddr)) {
		if ((shost = gethostbyaddr(&haddr, sizeof(haddr), AF_INET)) == NULL) 
			erro("Erro no gethostbyaddr");
	} else if ((shost = gethostbyname(hostname)) == NULL) 
		erro("Erro no gethostbyname");
	printf("Nome oficial: %s\n", shost->h_name);
	printf("Aliases: ");
	p = shost->h_aliases;
	for (i = 0; p[i] != NULL; ++i) 
		printf("%s ", p[i]);
	printf("\nTipo do endereco: %d %s\n", shost->h_addrtype,
				 shost->h_addrtype == AF_INET? "(IP addr)": NULL);
	printf("Dimensao do endereco: %d\n", shost->h_length);
	if (shost->h_addrtype == AF_INET) {
		printf("Lista de enderecos IP: ");
		for(i = 0; shost->h_addr_list[i] != NULL; ++i)
			printf("%s ", inet_ntoa(*(struct in_addr*)shost->h_addr_list[i]));
	}
	putchar('\n');
	return 0;
}
