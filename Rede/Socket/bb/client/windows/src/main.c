#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <windows.h>
#include <winsock2.h>
#include <ws2tcpip.h>

#define IP_ADDR "192.168.150.28"
#define PORT_NO 666

SOCKET create_socket(void);
int connect_socket(SOCKET* sock, char* ip, int port, int timeout_recv);
void disconnect_socket(SOCKET* sock);
void destroy_socket(SOCKET* sock);
int send_socket(SOCKET* sock, char* buffer, int to_send);
int recv_socket(SOCKET* sock, char* buffer, int to_read);
int keyboard_read(char* message, char* buffer, int to_read);
void menu(char *header,char *buffer,SOCKET *SOCK);
char escolhe_lampada(int lampada);

int main(int argc, char *argv[])
{
    SOCKET sock = create_socket();

    if (sock != INVALID_SOCKET)
    {
        if (connect_socket(&sock, IP_ADDR, PORT_NO, 10))
        {
			char header[]={0x02,0x00};
            char buffer[256] = {0};
			menu(header,buffer,&sock);
          
        }
        else
        {
            printf("ERROR connecting\n");
        }

        disconnect_socket(&sock);
    }
    else
    {
        perror("ERROR opening socket");
    }

    destroy_socket(&sock);

    return 0;
}
char escolhe_lampada(int lampada){
	
	switch(lampada){
		case 1:
			return 1;
		case 2:
			return 2;
		case 3:
			return 4;
		case 4:
			return 8;
		case 5:
			return 16;
		case 6:
			return 32;
	}
	return 0x00;
}
void menu(char *header,char *buffer,SOCKET *sock){
	
			int in;
			do{
            int n;
			puts("Digite 1 para teste de Echo");
			puts("Digite 2 para teste de Uppercase");
			puts("Digite 3 para teste de lampada");
			puts("Digite 4 para ligar uma lampada");
			puts("Digite 0 para sair");
			scanf("%d",&in);
			getchar();
			if(in==0)
				break;
			switch(in){
				case 1:
					header[0] = 0x01;
					keyboard_read("Digite seu texto\n", buffer, 255);
					header[1] = strlen(buffer)-1;
					send_socket(sock,header,2);
					n = send_socket(sock, buffer, strlen(buffer));
					break;
				case 2:
					header[1] = 0x02;
					keyboard_read("Digite seu texto\n", buffer, 255);
					header[1] = strlen(buffer)-1;
					send_socket(sock,header,2);
					n = send_socket(sock, buffer, strlen(buffer));
					break;
				case 3:
					header[0]= 0x03;
					send_socket(sock,header,1);
					n = recv_socket(sock,buffer,256);
					printf("%d %d\n",buffer[0]-'0',n);
					break;
				case 4:
					/*header[0]= 0x03;
					send_socket(sock,header,1);
					n = recv_socket(sock,buffer,256);
					printf("%d\n",buffer[0]);*/
					header[0] = 0x04;
					int lamp;
					puts("Digite a lampada a ser acesa: ");
					scanf("%d",&lamp);
					header[1]=escolhe_lampada(lamp);
					if(header[1] & buffer[0]){
						puts("Luz já está acesa");
					}
					else{
						send_socket(sock,header,2);
						
					}
					break;
				default:
					puts("Opcao nao implementada\n");
					
			}
			
            if (n >= 0	&& in<=2)
            {
                memset((void*) buffer, 0, 256);
                n = recv_socket(sock, buffer, 256);

                if (n >= 0)
                {
                    printf("Seu texto de saida e: %s\n", buffer);
                }
                else
                {
                    printf("ERROR reading from socket\n");
                }
            }
	
	
	}while(in!=0);
}

SOCKET create_socket(void)
{
    SOCKET sock = INVALID_SOCKET;
    WSADATA wsaData = {0};

    if (WSAStartup(MAKEWORD(2, 2), &wsaData) == 0)
    {
        sock = socket(AF_INET, SOCK_STREAM, 0);
    }

    return sock;
}

int connect_socket(SOCKET* sock, char* ip, int port, int timeout_recv)
{
    int result = 0;

    if (sock && ip)
    {
        struct sockaddr_in serv_addr = {0};
        struct timeval tv = {0};

        tv.tv_sec = timeout_recv;
        setsockopt(*sock, SOL_SOCKET, SO_RCVTIMEO, (char*) &tv, sizeof(struct timeval));

        serv_addr.sin_family = AF_INET;
        serv_addr.sin_addr.s_addr = inet_addr(ip);
        serv_addr.sin_port = htons(port);

        result = (connect(*sock, (struct sockaddr*) &serv_addr, sizeof(serv_addr)) >= 0);
    }

    return result;
}

void disconnect_socket(SOCKET* sock)
{
    if (sock)
    {
        closesocket(*sock);
    }
}

void destroy_socket(SOCKET* sock)
{
    WSACleanup();
}

int send_socket(SOCKET* sock, char* buffer, int to_send)
{
    int sent = 0;

    if (sock && buffer && (to_send > 0))
    {
        sent = send(*sock, buffer, to_send, 0);
    }

    return sent;
}

int recv_socket(SOCKET* sock, char* buffer, int to_read)
{
    int read = 0;

    if (sock && buffer && (to_read > 0))
    {
        read = recv(*sock, buffer, to_read, 0);
    }

    return read;
}

int keyboard_read(char* message, char* buffer, int to_read)
{
    int read = 0;

    if (message && buffer && (to_read > 0))
    {
        printf(message);

        if (fgets(buffer, to_read, stdin))
        {
            read = to_read;
        }
    }

    return read;
}
