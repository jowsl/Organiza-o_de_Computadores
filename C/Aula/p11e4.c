// Jouberth Matheus Simão Pereira nº23.2.4011
#include <stdio.h>
#define n 30

typedef struct{
    char nome[50];
    float nota;
    int freque;
} Aluno;

int main(){

Aluno nAlunos[n];
int teste, contador=0;
    FILE *arquivo = fopen("alunos.txt", "w+");
    for(int i=0; i<n;i++){
        printf("Digite 1 para entrar um aluno ou 0 para encerrar: ");
        scanf("%d", &teste);
        if (teste==1){
        contador++;
        scanf("%s %f %d", nAlunos[i].nome, &nAlunos[i].nota, &nAlunos[i].freque);
        } else {
            break;
        }
    }
    fprintf(arquivo, "%d\n\n", contador);
    // fprintf(arquivo, "\n");
    for (int i = 0; i < contador; i++){
        fprintf(arquivo, "%s %.1f %d\n\n", nAlunos[i].nome, nAlunos[i].nota, nAlunos[i].freque);
    }
    
    fclose(arquivo);
    return 0;
}