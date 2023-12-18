// Jouberth Matheus Simão Pereira nº23.2.4011
#include <stdio.h>
#include <stdlib.h>
#define MAX 100

//Protótipo da função de busca
int buscarMenor(int aleatorio[MAX], int num);
int buscarMaior(int aleatorio[MAX], int num);
// int buscarIgual(int aleatorio[MAX], int num); -teste-

int main(){
int num, aleatorio[MAX];
srand(10);
printf("Digite um número: ");
    scanf("%d", &num);
for (int i = 0; i < MAX; i++){
    aleatorio[i] = rand()%200;
}
printf("\nMaiores: ");
buscarMaior(aleatorio, num);
printf("\nMenores: ");
buscarMenor(aleatorio, num);
//buscarIgual(aleatorio, num);
    return 0;
}

int buscarMaior(int aleatorio[MAX], int num){
    for (int i = 0; i < MAX; i++){
        if(num<=aleatorio[i])
        printf("%d ", aleatorio[i]);
    }
    return 0;
}
int buscarMenor(int aleatorio[MAX], int num){
    for (int i = 0; i < MAX; i++){
        if(num>aleatorio[i])
        printf("%d ", aleatorio[i]);
    }
    return 0;
}