#include <stdio.h>
#define TAM 1000

int main(){
int vetor[TAM], n, maior, menor;
printf("Qual o tamanho do vetor? ");
scanf("%d", &n);
printf("Entre com os valores: ");
for (int i = 0; i < n; i++){
    scanf("%d", &vetor[i]);
}
maior = vetor[0];
menor = vetor[n-1];
for (int i = 0; i < n; i++){
    if(vetor[i]>maior)
    maior=vetor[i];
    else if (vetor[i]<menor)
    menor=vetor[i];
}

printf("Maior termo do vetor %d, menor %d\n\n", maior, menor);

    return 0;
}