// Jouberth Matheus Simão Pereira nº23.2.4011
#include <stdio.h>

typedef struct{
    char nome[50];
    float nota;
    int freque;
} Aluno;

float calculoMedias(float medias, int n); // protótipo da função calculadora de medias

int main(){
FILE *arquivo;
char nomeArquivo[100];
int n;
float mediaNotas=0, mediaFreq=0, aprovados=0;

printf("Digite o nome do arquivo: ");
scanf("%s", nomeArquivo);
    arquivo = fopen(nomeArquivo, "r");
    fscanf (arquivo, "%d", &n); 
    Aluno nAlunos[n]; //vetor para os n alunos
    for(int i=0;i<n;i++){ //scans dos dados
        fscanf (arquivo, "%s", nAlunos[i].nome);
        fscanf (arquivo, "%f", &nAlunos[i].nota);
        fscanf (arquivo, "%d", &nAlunos[i].freque);
    }
    for (int i = 0; i < n; i++){ //somando medias
        mediaNotas += nAlunos[i].nota;
        mediaFreq += nAlunos[i].freque;
    }
    mediaNotas = calculoMedias(mediaNotas, n);  //calculo das notas medias
    printf("\nNota média: %.1f\n", mediaNotas);
    mediaFreq = calculoMedias(mediaFreq, n); // calculos das frequencias medias
    printf("Frequência média: %.0f%%\n", mediaFreq);

    float contador=0; // contador para saber quantos estão acima da media de notas
    for (int i = 0; i < n; i++){
        if(nAlunos[i].nota>mediaNotas)
            contador++;
    }
    aprovados = (contador/n)*100; //porcentagem de aprovados
    printf("Percentual de aprovação: %.0f%%\n", aprovados);
    printf("Nome dos alunos com nota acima da nota média:\n");
    for (int i = 0; i < n; i++){
        if(nAlunos[i].nota>mediaNotas)
            printf("%s\n", nAlunos[i].nome);
    }
    return 0;
}

float calculoMedias(float medias, int n){
    float total;
    total = medias / n;
    return total;
}
