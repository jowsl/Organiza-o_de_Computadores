// Jouberth Matheus Simão Pereira 23.2.4011
#include <stdio.h>

int main (){
float nota1, nota2, soma=0;
int quantAlunos;

    while (1){  
        
        printf("Digite a nota do aluno: ");
        scanf("%f %f", &nota1, &nota2);
        if (nota1 < 0 || nota2 < 0 )
        return 0;
        else {
        soma = nota1 + nota2;
        quantAlunos =2;
        printf("Média das notas será: %.1f \n", soma / quantAlunos);        
        }
    }
    return 0;
}