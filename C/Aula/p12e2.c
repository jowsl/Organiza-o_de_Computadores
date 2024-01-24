// Jouberth Matheus Simão Pereira nº23.2.4011
#include <stdio.h>
#include <stdlib.h>

int** criaMatriz(int m, int n);
int procura_valor(int **A, int m, int n, int valor);
void liberaMatriz(int** A, int m);

int main(){
    int **A, m, n, valor;

    printf("Digite o valor de m e n:");
    scanf("%d %d", &m, &n);
    printf("Digite a matriz:");
    A = criaMatriz(m , n);
    
    for (int i = 0; i < m; i++){
        for (int j = 0; j < n; j++){
            scanf("%d", &A[i][j]);
        }
    }

    printf("Digite o valor a ser procurado:");
    scanf("%d", &valor);
    int procurador = procura_valor(A, m, n, valor);
    if ( procurador == 1)
        printf("Valor encontrado!");
        else
            printf("Valor não encontrado!");

    liberaMatriz(A, m);

    free(A);
    return 0;
}

int procura_valor(int **A, int m, int n, int valor){
    for (int i = 0; i < m; i++){
        for (int j = 0; j < n; j++){
            if (A[i][j] == valor)
                return 1;
        }
    }
    return 0;
}

int** criaMatriz(int m, int n){
    int **A = malloc (m * sizeof(int*));
    for (int i = 0; i < m; i++){
        A[i] = malloc(n * sizeof(int));
        }
    return A;
}

void liberaMatriz(int** A, int m){
    for (int i = 0; i < m; i++)
    {
        free(A[i]);
    }
    
}

