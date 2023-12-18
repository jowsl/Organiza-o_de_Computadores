// Jouberth Matheus Simão Pereira nº23.2.4011
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define max 100

int checagemMaior(int vetor1[max], int m, int n, int *maior);

int main(){
int n, numAleatorio, m, vetor1[max], maior=0;
srand(time(NULL));
printf("Digite quantos números serão gerados: ");
scanf("%d", &n);
printf("\nDigite o valor de m: ");
scanf("%d", &m);
printf("\nO vetor gerado é: [ ");
for (int i = 0; i < n; i++){
    numAleatorio = rand()%99+1;
    vetor1[i] = numAleatorio;
    printf("%d ", vetor1[i]);
}
printf("]\n");
checagemMaior(vetor1, m, n, &maior);
    return 0;
}

int checagemMaior(int vetor1[max], int m, int n, int *maior){
    int contadorDeMaiores=0;
    for (int i = 0; i < n; i++){
        if(vetor1[i] > m)
        contadorDeMaiores++;
    }
    *maior = contadorDeMaiores;
    printf("\nExistem %d valores maiores que %d!\n\n", *maior, m );
    return 0;

}