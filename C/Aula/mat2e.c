#include <stdio.h>
#define MAX 100

int main(){
int M, N, matrizA[MAX][MAX], C, linha; // setar uma matriz como no máximo 100x00
printf("Entre com as dimensões da matriz (<= 100)"); // usuário seta as dimensões verdadeiras
scanf("%d %d", &M, &N); 
for (int i = 0; i < M; i++){
    for (int j = 0; j < N; j++){
        printf("Entre com o elemento da matriz[%d][%d]: ", i, j);
        scanf("%d", &matrizA[i][j]); //scanf da matriz indice i e j
    }
}
printf("Digite agora a linha da matriz que você quer multiplicar e um nº constante 'C': ");
scanf("%d%d", &linha, &C);
for (int j = 0; j < N; j++){ // Como a linha será constante, percorremos apenas a coluna, j.
    matrizA[linha][j] = matrizA[linha][j] * C;
}
for (int i = 0; i < M; i++){
     for (int j = 0; j < N; j++){
        printf("%d ", matrizA[i][j]);
    }
    printf("\n");
}
    return 0;
}
