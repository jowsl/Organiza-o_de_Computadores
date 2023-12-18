#include <stdio.h>

int main (){
int numAlunos;
float media, notas, soma;
    printf("Digite o número de alunos: \n");
    scanf("%d", &numAlunos);
    int i = 1;
    soma = 0;
    while (i <= numAlunos ){
        printf("Digite a nota do aluno %d:  ", i);
        scanf("%f", &notas);
        if (notas < 0 || notas > 10){
            printf("Nota inválida! Tente novamente.\n");            
        } else {
        soma += notas; // é o mesmo que soma = soma + notas;
        i++;
        }
    }
    media = soma / numAlunos;
    printf("Média das notas será: %.2f\n\n", media );
    return 0;
}