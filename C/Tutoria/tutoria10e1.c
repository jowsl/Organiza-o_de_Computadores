// Jouberth Matheus Simão Pereira nº23.2.4011
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define max 100

int maiorValor(int vetor1[max], int n, int *maior, int *posicaoMaior);
int menorValor(int vetor1[max], int n, int *menor, int *posicaoMenor);

int main(){
int n, numAleatorio, vetor1[max], maior, menor, posicaoMenor, posicaoMaior;
srand(time(NULL));
printf("Digite quantos números serão gerados: ");
scanf("%d", &n);
printf("O vetor gerado é: [");
int i;
for (i = 1; i <= n; i++){
    numAleatorio = rand()%99+1;
    vetor1[i] = numAleatorio;
    if(i==n){
    printf("%d", vetor1[i]);
    printf("]");
    } else {
    printf("%d ", vetor1[i]);
    }
    }
    maiorValor(vetor1, n, &maior, &posicaoMaior);
    menorValor(vetor1, n, &menor, &posicaoMenor);
    return 0;
}

int maiorValor(int vetor1[max], int n, int *maior,int *posicaoMaior){
    *maior = vetor1[1];
    for (int i = 2; i <= n; i++){
    if (vetor1[i]>*maior){
        *maior = vetor1[i];
        *posicaoMaior = i;
    } if (i==n){
        printf("\nO maior valor é: %d e está na posição %d.", *maior, *posicaoMaior);
    }
    }
    return 0;
}
int menorValor(int vetor1[max], int n, int *menor, int *posicaoMenor){
    *menor = vetor1[1];
    for (int i = 2; i <= n; i++){
    if (vetor1[i]<*menor){
        *menor = vetor1[i];
        *posicaoMenor = i;
    } if (i==n){
        printf("\nO menor valor é: %d e está na posição %d.\n\n", *menor, *posicaoMenor);
    }
    }
    return 0;
}