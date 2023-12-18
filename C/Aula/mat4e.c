#include <stdio.h>
#define TAM 10

int main(){
int matriz[TAM][TAM], maior;
printf("Entre com os valores da matriz: ");
for (int i = 0; i < TAM; i++){
    for (int  j = 0; j < TAM; j++){
        scanf("%d", &matriz[i][j]);
    }
}
maior = matriz[0][0];  // para procurar o maior termo, ou iniciar maior com 0 ou com o primeiro termo da matriz.
int l=0;
int c=0;
for (int i = 0; i < TAM; i++){
    for (int  j = 0; j < TAM; j++){
        if (matriz[i][j]>=maior){  // se o termo for maior, a posição dos índices i e j são armazenadas em vetores l e c.
            maior =  matriz[i][j]; // assim teremos a posição do maior termo.
            l = i;
            c = j;
        }
    }
}
printf("O maior valor é %d e sua localização é i %d j %d \n", maior, l, c);
printf("Elementos da diagonal principal: ");
for (int i = 0; i < TAM; i++){
    for (int j = 0; j < TAM; j++){
        if (i==j)
        printf("%d ", matriz[i][j]);
    }
}
printf("\n");
printf("Elementos da diagonal secundaria: ");
for (int i = 0; i < TAM; i++){
    for (int j = 0; j < TAM; j++){
        if(i+j == TAM-1)
        printf("%d ", matriz[i][j]);
    }
}
printf("\n\n");
    return 0;
}