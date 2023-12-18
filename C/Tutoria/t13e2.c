// Jouberth Matheus Simão Pereira nº23.2.4011
#include <stdio.h>

int main(){
int matriz1[3][3],  matriz2[3][3];
printf("Digite os valores da primeira matriz:");
for (int i = 0; i < 3; i++){
    for (int j = 0; j< 3; j++){
        scanf("%d", &matriz1[i][j]);
        }
}        
printf("Digite os valores da segunda matriz:");
for (int i = 0; i < 3; i++){
    for (int j = 0; j< 3; j++){
        scanf("%d", &matriz2[i][j]);
    }
}     
for (int i = 0; i < 3; i++){
    for (int j = 0; j < 3; j++){
        if (matriz1[i][j]*matriz2[i][j]==0)
            matriz1[i][j] = 0;
        }
        
    }
for (int i = 0; i < 3; i++){
    for (int j = 0; j < 3; j++){
        printf("%d ", matriz1[i][j]);
        }
    printf("\n");
    }

    return 0;
}



