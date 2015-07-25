#include <stdio.h>
#include "calc.h"

int main(){
	
	int op,num1,num2;
	do{
		puts("Bem vindo a calculadora");
		puts("Pressione 1 para Soma");
		puts("Pressione 2 para Subtracao");
		puts("Pressione 3 para Multiplicacao");
		puts("Pressione 4 para Divisao");
		puts("Pressione 0 para Sair");
		scanf("%d",&op);
		switch(op){
			case 1:
				puts("Entre com os numeros");
				scanf("%d %d",&num1,&num2);
				printf("A soma e igual a %d\n",soma(num1,num2));
				break;
			case 2:
				puts("Entre com os numeros");
				scanf("%d %d",&num1,&num2);
				printf("A subtracação e igual a %d\n",subtracao(num1,num2));
				break;
			case 3:
				puts("Entre com os numeros");
				scanf("%d %d",&num1,&num2);
				printf("O produto e igual a %d\n",multiplicacao(num1,num2));
				break;
			case 4:
				puts("Entre com os numeros");
				scanf("%d %d",&num1,&num2);
				printf("A divisao e igual a %d\n",divisao(num1,num2));
				break;
			case 0:
				puts("Saindo...");
				break;
			default:
				puts("Opcao invalida");
				break;
		}
	}while(op!=0);
	return 0;
}
