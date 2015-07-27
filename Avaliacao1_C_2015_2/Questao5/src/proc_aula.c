#include "proc_aula.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
void preenche_sala(sala *aluno,int numalunos){

	int i;
	char nome[TAM]={0};
	float nota;
	for(i=0;i<numalunos;i++){
		getchar();
		printf("Digite o nome do %do aluno\n",i+1);
		scanf("%[^\n]s",nome);
		puts("Digite a nota desse aluno");
		scanf("%f",&nota);
		strcpy(aluno[i].nome,nome);
		aluno[i].nota = nota;	
	}

}
float calcula_media(sala *aluno,int numalunos){
	
	int i;
	float media=0;
	for(i = 0;i<numalunos;i++){
		media +=aluno[i].nota;
		
	}
	
	return media /=numalunos;
}
void ordena_alunos(sala *aluno,int numalunos){

	sala temp;
	int i ,j;
	for(i=1;i<numalunos;i++){
		temp = aluno[i];
		for(j=i;j>0;j--){
			if(aluno[j-1].nota<temp.nota){
				aluno[j] = aluno[j-1];
				aluno[j-1] = temp;
			}
		
		}
	}
}
void imprime_alunos(sala *aluno, int numalunos){
	
	int i;
	for(i=0;i<numalunos;i++){
		printf("Aluno: %s - Nota: %.2f\n",aluno[i].nome,aluno[i].nota);
	
	}
}
