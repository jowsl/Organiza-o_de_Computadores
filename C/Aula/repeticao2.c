#include <stdio.h>

int main(){
float numAlunos, nota;
    printf("Entre com a quantidade de alunos: \n");
    scanf("%f", &numAlunos);

float i = 1, soma = 0;
    while (i<=numAlunos){
        printf("Entre com a nota do aluno: \n");
        scanf("%f", &nota);
        soma += nota;
        i++;
    }
    
    printf("A média das notas será %.2f\n\n", soma/numAlunos);


    return 0;
}