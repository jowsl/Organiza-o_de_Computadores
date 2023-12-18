// Jouberth Matheus Simão Pereira nº23.2.4011
#include <stdio.h>
#define TAM 50

int main(){
    int vetor[TAM], soma=0;
    printf("Digite os 50 valores:");
    for (int  i = 0; i < TAM; i++){
        scanf("%d", &vetor[i]);
        soma = vetor[i]+soma;
    }
printf("A soma dos valores do vertor é: %d\n", soma);
    return 0;
}