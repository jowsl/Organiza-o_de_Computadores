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
    FILE *arquivo = fopen ("aluno.txt", "w+");
    printf("Digite o número de alunos: ");
    scanf("%d", &x);
    fprintf(arquivo, "%d\n", x);
    for (int i = 0; i < x; i++){
        printf("Digite o número de matrícula do aluno %d: ", i+1);
        scanf("%d", &nAlunos[i].mat);
        fprintf(arquivo, "%d ", nAlunos[i].mat);
        printf("Digite o coeficiente do aluno %d: ", i+1);
        scanf("%f", &nAlunos[i].coeficiente);
        fprintf(arquivo,"%.1f\n", nAlunos[i].coeficiente);       
    }
    fclose(arquivo);
    return 0;
}