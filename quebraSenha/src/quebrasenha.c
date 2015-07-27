#include <stdio.h>
#include <string.h>
//Weslley da Cunha Santos
int main(){
	char key [  ] = {"MaStErSuPeRhYpErKeY"};
	char hash[32] = {0};
	char saida[32] = {0};

	int i, ckey;

	printf("Entre com o Hash a ser quebrado: ");
	scanf("%s", hash);

	for (i = 0; i < strlen(hash); ++i){
		ckey = i % strlen(key);
		saida[i] = ((key[ckey] + 4) ^ (hash[i]   - 33))-8;
	}


	printf("Senha quebrada: %s\n", saida);

	return 0;
}

