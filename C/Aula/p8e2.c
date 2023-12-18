// Jouberth Matheus Simão Pereira nº23.2.4011
#include <stdio.h>
#include <stdlib.h>

#define MAX 500

int main(){
int vQuinhentos[MAX], n;
srand(5);

while (n>500||n<=0){
printf("Entre com um número inteiro <= 500: ");
scanf("%d", &n);
}
for(int i = 0; i < n; i++){
      vQuinhentos[i] = 0;
    }
for (int i = 0; i < 100000; i++){
    int numAleatorio = rand()%n;
    vQuinhentos[numAleatorio]++;
    }
for(int i = 0; i < n; i++){
      printf("\nA[%d] = %d", i+1, vQuinhentos[i]);
    }
printf("\n\n");
    return 0;
}