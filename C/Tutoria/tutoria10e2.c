// Jouberth Matheus Simão Pereira nº23.2.4011
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define max 100

int main(){
int n, vetor1[max], num, total=0;
srand(time(NULL));
printf("Digite quantos números serão gerados: ");
scanf("%d", &n);
printf("O vetor gerado é: [ ");
for (int i = 0; i <= n; i++){
    num = rand()%9+1;
    vetor1[i] = num;
    printf("%d ", vetor1[i]);
    total = vetor1[i]+total;
}
printf("]\n");
printf("A soma de todos os elementos do vetor: %d\n\n", total);
    return 0;
}