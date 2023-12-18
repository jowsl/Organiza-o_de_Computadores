// Jouberth Matheus Simão Pereira nº23.2.4011
#include <stdio.h>

void leitorM(int a, int b, int mat[a][b]);
void printM(int m, int n, int p, int matA[m][p], int matB[p][n], int matC[m][n]);

int main() {
    int m, n, p, q;
    do {
        printf("Entre com os valores de m, p, q, n: ");
        scanf("%d %d %d %d", &m, &p, &q, &n);
        if(m > 10 || m < 1 || n > 10 || n < 1 || p > 10 || p < 1 || p != q)
            printf("Valores inválidos!\n");
    } while (m > 10 || m < 1 || n > 10 || n < 1 || p > 10 || p < 1 || p != q);
    int matA[m][p], matB[q][n], matC[m][n];
    printf("Entre com os elementos da matriz: ");
    leitorM(m, p, matA);
    printf("Entre com os elementos da matriz: ");
    leitorM(q, n, matB);
    printM(m, n, p, matA, matB, matC);
    return 0;
}

void leitorM(int a, int b, int mat[a][b]) {
    for (int i = 0; i < a; i++)
        for (int j = 0; j < b; j++)
            scanf("%d", &mat[i][j]);
}

void printM(int m, int n, int p, int matA[m][p], int matB[p][n], int matC[m][n]) {
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++){
            matC[i][j] = 0;
            for (int k = 0; k < p; k++)
                matC[i][j] += matA[i][k] * matB[k][j];
        }
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++)
            printf("%d ", matC[i][j]);
        printf("\n");
}
}