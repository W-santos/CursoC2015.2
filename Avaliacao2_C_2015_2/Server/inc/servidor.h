#ifndef servidor_h
#define servidor_h
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <curses.h>
#include <string.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <errno.h>

#define PORTA 9090

#define INVALID_SOCKET -1
#define CLIENTES 20

typedef struct{
	int socket;
	char nome[30];
}User;
int criarSocket();
int vincularSocket(int socket, int porta);
int esperarConexao(int socket,int max_sockets);
int lerMensagemCliente(int socket, char *buffer, int len);
int enviarMensagemCliente(int socket, char *buffer, int len);
void desconectarSocket(int socket);
#endif
