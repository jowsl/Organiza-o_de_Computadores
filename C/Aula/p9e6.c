// Jouberth Matheus Simão Pereira nº23.2.4011
#include <stdio.h>
#define max 4


int main(){
int matriz[max][max];
printf("Digite os valores da matriz:");
for (int i = 0; i < max; i++){
    for (int j = 0; j < max; j++){
        scanf("%d", &matriz[i][j]);
        while (matriz[i][j]<0){
        scanf("%d", &matriz[i][j]);
        }
        printf("%d ", matriz[i][j]);
    }
printf("\n");
}
printf("Posições de valores pares:\n");

for (int i = 0; i < max; i++){
    for (int j = 0; j < max; j++){
        if (matriz[i][j]%2==0){
            printf("%d %d", i, j);
        }
        printf("\n");
    }
}
    return 0;
}