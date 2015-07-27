#include <stdio.h>
 
#define TAM 10000
int main(){
 
    int anterior1=0,anterior2=1,soma=0;
    puts("Sequencia de fibonacci:");
    printf("0 ");
  	while(1){       
		   soma=anterior1+anterior2;
		   anterior2=anterior1;
		   anterior1=soma;
		   if(soma >TAM)
		   	break;
		   printf("%d ",soma);
	}
	puts("");
 
    return 0;
}
