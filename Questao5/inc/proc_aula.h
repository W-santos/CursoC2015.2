#define TAM 100
typedef struct{
	char nome[TAM];
	float nota;
}sala;


void preenche_sala(sala *aluno,int numalunos);
float calcula_media(sala *aluno,int numalunos);
void ordena_alunos(sala *aluno,int numalunos);
void imprime_alunos(sala *aluno, int numalunos);
