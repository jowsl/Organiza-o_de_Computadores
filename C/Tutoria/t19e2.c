// Jouberth Matheus Simão Pereira nº23.2.4011
#include <stdio.h>
#include <stdlib.h>

float** criaMatriz(int m, int n);
void liberaMatriz(float **matriz, int m);
float ** custoEnergia(float **mat, int n);

int main() {
    float **mat;
    int nCasas;

    printf("Digite a quantidade de residências: ");
    scanf("%d", &nCasas);
    mat = criaMatriz(nCasas, 2);

    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < nCasas; j++) {
            printf("Digite os gastos de KWh da residência %d:", j + 1);
            scanf("%f", &mat[0][j]);
            custoEnergia(mat, nCasas);
        }
    }

    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < nCasas; j++) {
            printf("Residência %d: Gastos %.2f KWh - Custo: R$%.2f\n", j + 1, mat[0][j], mat[1][j]);
        }
    }

    liberaMatriz(mat, nCasas);
    free(mat);
    return 0;
}

float** criaMatriz(int m, int n) {
    float **matriz = malloc(m * sizeof(float*));
    for (int i = 0; i < m; i++) {
        matriz[i] = malloc(n * sizeof(float));
    }
    return matriz;
}

void liberaMatriz(float **matriz, int m) {
    for (int i = 0; i < m; i++) {
        free(matriz[i]);
    }
}

float ** custoEnergia(float **mat, int n) {
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < n; j++) {
            if (mat[0][j] < 30)
                mat[0][j] = mat[1][j] * 1.08;
            else if (mat[0][j] > 30 && mat[0][j] < 120)
                mat[0][j] = mat[1][j] * 1.08 + 30;
            else if (mat[0][j] > 120)
                mat[0][j] = mat[1][j] * 1.22 + 30;
            else
                printf("Valor incorreto!");
        }
    }
    return mat;
}
