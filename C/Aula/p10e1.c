// Jouberth Matheus Simão Pereira nº23.2.4011
#include <stdio.h>
#define max 3

int main(){
int matrizA[max][max], matrizB[max][max];
for (int i = 0; i < max; i++){
    printf("\nDigite a linha %d da matriz: ", i+1);
    for(int j = 0; j < max; j++){
    scanf("%d", &matrizA[i][j]);
    }
}
for (int i = 0; i < max; i++) {
        for (int j = 0; j < max; j++) {
            matrizB[j][max - 1 - i] = matrizA[i][j];
        }
    }
printf("\nMatriz rotacionada:");
for (int i = 0; i < max; i++){
    for (int j = 0; j < max; j++){
        printf("%d ", matrizB[i][j]);
    }
    printf("\n");
}
    return 0;
}

