// Jouberth Matheus Simão Pereira nº23.2.4011
#include <stdio.h>
#define MAX 15
int main(){
float vetor[MAX];
float soma=0;
    for(int i=0; i<MAX; i++){
        printf("Digite o consumo da %d residência: ", i+1);
        scanf("%f", &vetor[i]);
        soma = soma+vetor[i];  
    }
    float MAIOR=vetor[0];
    for (int i = 0; i <= MAX; i++){
        if (vetor[i]>MAIOR)
            MAIOR = vetor[i];
    }
        float MENOR=vetor[0];
    for (int i = 0; i < MAX; i++){
        if (vetor[i]<MENOR)
            MENOR = vetor[i];
    }
    soma = soma/15;
    printf("\nConsumo médio: %.2f Kwh",soma);
    printf("\nMaior consumo: %.2f Kwm", MAIOR);
    printf("\nMenor consumo: %.2f Kwm\n\n", MENOR);
    return 0;
}