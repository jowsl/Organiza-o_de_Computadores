#include <stdio.h>
#include <stdlib.h>
#define n 15
typedef struct{
    int mat;
    float coeficiente;
} Aluno;

int main(){
    Aluno nAlunos[n];
    int x;
    FILE *arquivo = fopen ("aluno.txt", "r");
    fscanf(arquivo, "%d", &x);
    for (int i = 0; i < x; i++){
        printf("Número de matrícula do aluno %d:" , i+1);
        fscanf(arquivo, "%d", &nAlunos[i].mat);
        printf("%d\n", nAlunos[i].mat);
        printf("Coeficiente do aluno %d:", i+1);
        fscanf(arquivo, "%f\n", &nAlunos[i].coeficiente);
        printf("%.1f\n", nAlunos[i].coeficiente);       
    }
    fclose(arquivo);
    return 0;
}