// Jouberth Matheus Simão Pereira nº23.2.4011
#include <stdio.h>
#include <string.h>
#define max 30  // definindo valor máximo para usar nas strings


int main(){
    char concatenados[max*3], priPalavra[max], segPalavra[max], terPalavra[max];
printf("Digite a 1 palavra :");
scanf("%s", priPalavra);
printf("\nDigite a 2 palavra :");
scanf("%s", segPalavra);
printf("\nDigite a 3 palavra :");
scanf("%s", terPalavra);

strcpy(concatenados, priPalavra );
strcat(concatenados, segPalavra);
strcat(concatenados, terPalavra);

printf("\n%s\n", concatenados);


    return 0;
}