#include <stdio.h>
#include <stdlib.h>

typedef struct {

    char nome[50];
    float notas, frequencia;

} alunos;

void salvarTxt(alunos *aluno, int n){
    FILE *arq = fopen("alunos.txt", "w+");
    for (int i = 0; i < n; i++){      
    fprintf(arq, "%s %.2f %.2f\n", aluno[i].nome, aluno[i].notas, aluno[i].frequencia);
    }
    fclose(arq);
}

void salvaDat(alunos *dados, int n){
    FILE *arq = fopen("alunos.dat", "wb+");
    fwrite(dados, sizeof(alunos), n, arq);
    fclose(arq);
}

int main(){
    alunos *aluno;
    // fwrite e fread
    printf("Entre com a quantidade de alunos: ");
    int n;
    scanf("%d", &n);
    aluno = (alunos *) malloc(n * sizeof(alunos));
    
    for (int i = 0; i < n; i++){
        printf("Entre com o nome do aluno, a frequencia, e a nota: ");
        scanf("%s %f %f", aluno[i].nome, &aluno[i].frequencia, &aluno[i].notas);
    }
    salvarTxt(aluno, n);
    salvaDat(aluno, n);

    // fwrite(&data, size_to_write, 1, file);

    free(aluno);    
    return 0;
}