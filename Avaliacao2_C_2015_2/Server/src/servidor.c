#include "servidor.h"

int criarSocket()
{

	int s = socket(AF_INET, SOCK_STREAM,0);

	if(s == -1){
		puts("Sem socket");
		return 0;
	}
	return s;
}
	
int vincularSocket(int socket, int port)
{
	int c = 0;
	struct sockaddr_in conexao;
	struct timeval tv = {0};
  	tv.tv_usec = 100;
	setsockopt(socket, SOL_SOCKET, SO_RCVTIMEO, (char*) &tv, sizeof(struct timeval));
	
	conexao.sin_family = AF_INET;
	conexao.sin_port = (in_port_t) htons(port);
	conexao.sin_addr.s_addr = htonl(INADDR_ANY);
	int reuse = 1;
	if (setsockopt(socket,SOL_SOCKET,SO_REUSEADDR, (char *)&reuse, sizeof(int) == -1))
	c = bind(socket, (struct sockaddr *) &conexao, sizeof(conexao));
		if(c==-1){
			puts("Não é possível criar conexão");
			exit(0);
		}
	return c;

}

int esperarConexao(int socket,int max_sockets){

	int novo_socket = INVALID_SOCKET;
	if(socket != INVALID_SOCKET)
	{
		int tamcliente;
		struct sockaddr_in end_cliente;
		listen(socket,max_sockets);
		tamcliente = sizeof(end_cliente);
		
		novo_socket =accept(socket, (struct sockaddr *) &end_cliente, (socklen_t*) &tamcliente);
		if(novo_socket != INVALID_SOCKET)
		{
			struct timeval tv = {0};
  			tv.tv_usec = 100;
  			 setsockopt(novo_socket, SOL_SOCKET, SO_RCVTIMEO, (char*) &tv, sizeof(struct timeval));
            printf("New connection incoming: %s:%d\n", inet_ntoa(end_cliente.sin_addr),ntohs(end_cliente.sin_port));
        }
		

	}
	return novo_socket;

}

int lerMensagemCliente(int socket, char *buffer, int len)
{

	
    int lidos = 0;

    if (socket && buffer && (len > 0))
    {
			lidos = recv(socket, buffer, len, 0);
    }
    return lidos;
}

int enviarMensagemCliente(int socket, char *buffer, int len)
{

	int enviados = 0;

    if ((socket != INVALID_SOCKET) && buffer && (len > 0))
        enviados = send(socket, buffer, len, 0);
    return enviados;

}

void desconectarSocket(int socket)
{
	if(socket != INVALID_SOCKET)
		close(socket);

}
	

