#include "servidor.h"

int chat(User *sockets,  int socket_cliente,int numClientes, int numClienteOrigem);
int broadcast(User *sockets, int usuariosLogados,int socketOrigem,char *mensagem, int numClienteOrigem);
int private(User *sockets,int usuariosLogados,char *destino, int socketOrigem,char *mensagem, int numClienteOrigem);


int main(int argc, char *argv[])
{
	User socketPrincipal;
	socketPrincipal.socket = criarSocket();
	if(socketPrincipal.socket != INVALID_SOCKET)
	{
			if(vincularSocket(socketPrincipal.socket,PORTA)!=-1)
			{
				User sockets[CLIENTES] = {-1};
				int socketsAbertos = 0;
				while(1)
				{
					int i,max;
					if(socketsAbertos<CLIENTES)
					{	
						char nome[50]={0};
						User socketSecundario;
						 socketSecundario.socket = esperarConexao(socketPrincipal.socket,CLIENTES); 
						if(socketSecundario.socket != INVALID_SOCKET)
						{
							lerMensagemCliente(socketSecundario.socket,nome,sizeof(nome));
							strcpy(socketSecundario.nome,nome);
							sockets[socketsAbertos++] = socketSecundario;

						}
					}
					for(i=0,max = socketsAbertos; i < max; ++i)
					{
						if(sockets[i].socket != INVALID_SOCKET)
						{
							chat(sockets,sockets[i].socket,socketsAbertos,i);
						}
					
					}
				
				}
		
		
		
			}
	}

	 


}
int private(User *sockets,int usuariosLogados,char *destino, int socketOrigem,char *mensagem,int numClienteOrigem)
{
	char saida[256];
	int i,flag = 0;
	for(i=0;i<usuariosLogados;i++)
	{
		if(!strcmp(destino,sockets[i].nome))
		{
			flag = 1;
			break;
		}
	}
	if(flag)
	{
		sprintf(saida,"[%s][PVT] %s",sockets[numClienteOrigem].nome,mensagem);
		enviarMensagemCliente(sockets[i].socket,saida,strlen(saida));
	}
}

int broadcast(User *sockets, int usuariosLogados,int socketOrigem,char *mensagem,int numClienteOrigem)
{
	int i,resultado;

	for(i=0;i<usuariosLogados;++i)
	{
		if(sockets[i].socket != socketOrigem)
		{
			char saida[256]={0};
			sprintf(saida,"[%s] %s",sockets[numClienteOrigem].nome,mensagem);
			resultado = enviarMensagemCliente(sockets[i].socket,saida,strlen(saida));

		}

	}
	return resultado;
}

int chat(User *sockets,  int socket_cliente,int numClientes,int numClienteOrigem)
{	
	int result;
	if(socket_cliente != INVALID_SOCKET)
	{
		char buffer[256]={0},nome[30]={0},mensagemLimpa[256]={0};
		 int selected,i,j=0,k=0,flag=0;
        {
        
         	int tam = lerMensagemCliente(socket_cliente,buffer,sizeof(buffer));
         	if(tam >0 && buffer[0] != '<')
         	{
         		
         		broadcast(sockets,numClientes,socket_cliente,buffer,numClienteOrigem);
         	}
         	else if(tam>0)
         	{
         		for(i=1;i<strlen(buffer);i++)
         		{
         			if(flag==0 && buffer[i] != '>')
         				nome[j++] = buffer[i];
         			else
         			{
         				flag = 1;
         				mensagemLimpa[k++] = buffer[i];
         			}

         		}
         		private(sockets,numClientes,nome,socket_cliente,mensagemLimpa,numClienteOrigem);
         	}
        }

	}
	return 0;
}