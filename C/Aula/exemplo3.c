#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// ler 2 num int onde n1<n2, imprimir um  número aleatório entre n1-n2
int main(){
    int n1, n2;
    srand(time(NULL));
    printf("\nDigite dois número :");
    scanf("%d %d", &n1, &n2);
        int numAleatorio = n1 + rand() % (n2 - n1 + 1); // gerando nº aleatório
    printf("O número aleatório gerado foi %d \n", numAleatorio);

    return 0;
}