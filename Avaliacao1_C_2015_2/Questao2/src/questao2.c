//Weslley da Cunha Santos
#include <stdio.h>

int main(){

	char lampadas[8]={0};
	char opcao;
	puts("Bem vindo!");
	while(1){
		puts("Digite 1 para acender alguma lampada");
		puts("Digite 2 para desligar alguma lampada");
		puts("Digite 3 para checar o estado de alguma lampada");
		puts("Digite 0 para sair");
		scanf(" %c",&opcao);
		if(opcao=='0')
		 	break;
		switch(opcao){
			
			case '1':
				puts("Digite qual a lampada que será acesa");
				scanf(" %c",&opcao);
				opcao -='1';
				lampadas[(int)opcao] == 0? lampadas[(int)opcao] =1:puts("A lampada ja esta acesa");
				break;
			case '2':
				puts("Digite qual a lampada a ser apagada");
				scanf(" %c",&opcao);
				opcao -='1';
				lampadas[(int)opcao] == 1? lampadas[(int)opcao] = 0: puts("A lampada ja esta apagada");
				break;
			case '3':
				puts("Digite a lampada a ser checada");
				scanf(" %c",&opcao);
				opcao -='1';
				lampadas[(int)opcao] == 0? puts("A lampada está apagada") : puts("A lampada esta acesa");
				break;
			default:
				puts("Opcao invalida");
		}
	
	}
	return 0;

}
