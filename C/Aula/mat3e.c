#include <stdio.h>
#define M 5
#define N 5

void printadorBolado(int matrizA[M][N]){
    for (int i = 0; i < M; i++){
        for (int j = 0; j < N; j++){
            printf("%d ", matrizA[i][j]);
        }
        printf("\n");
    }
}

int main(){
int matrizA[M][N]={{0,0,0,0,0},{0,0,0,0,0},{0,0,0,0,0},{0,0,0,0,0},{0,0,0,0,0}};
int indice, coluna, num;
printadorBolado(matrizA);
for (int i = 0; i < M; i++){
    for (int j = 0; j < N; j++){
        printf("Entre com índice, coluna e valor da posição que deseja alterar: ");
        scanf("%d%d%d", &indice, &coluna, &num);
        if (num < 0 || indice < 0 || coluna < 0){  
            printf("\n\nErro: o valor não é um número inteiro > 0!\n\n");
            return 0;
        }
        matrizA[indice][coluna] = num;  // Entrar com as variáveis no local dos índices, essa posição recebe 'num'
        printadorBolado(matrizA);
    }
}
    return 0;
}