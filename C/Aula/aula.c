#include <stdio.h>
#define M 4
#define N 5


int main(){
int matriz[M][N], soma1=0, somalinhas[4];  
for (int i = 0; i < M; i++){
    somalinhas[i]=0;
    for (int j = 0; j < N; j++){   
        scanf("%d", &matriz[i][j]);
        somalinhas[i] = matriz[i][j]+somalinhas[i];
        soma1 = somalinhas[i]+soma1;
    }

}
for (int i = 0; i < M; i++){
    for (int j = 0; j < N; j++){
        printf("%d ", matriz[i][j]);
    }
printf("\n");
}   

printf("Soma de cada linha: ");
    for (int i = 0; i < M; i++){
        printf("%d ", somalinhas[i]);
    }
     printf("\nSoma total de todos os elementos da matriz: %d\n", soma1);


    return 0;
}

// 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20
// Soma de cada linha: 15 40 65 90
// Soma total de todos os elementos da matriz: 590
