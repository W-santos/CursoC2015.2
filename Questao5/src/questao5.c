#include "proc_aula.h"
#include <stdio.h>
#include <stdlib.h>
int main(){

	sala *alunos;
	int num;
	
	

	puts("Digite o numero de alunos");
	scanf("%d",&num);
	alunos = (sala * ) malloc(num*sizeof(sala));
	if(alunos==NULL){
		puts("Erro ao usar malloc!");
		return 1;
	}
	preenche_sala(alunos,num);
	printf("A media da sala e igual a: %.2f\n",calcula_media(alunos,num));
	ordena_alunos(alunos,num);
	imprime_alunos(alunos,num);
	free(alunos);
	
	return 0;
}

