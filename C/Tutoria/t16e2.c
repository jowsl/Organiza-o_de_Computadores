// Jouberth Matheus Simão Pereira nº23.2.4011
#include <stdio.h>

typedef struct{
int peso;
float nota;
}Prova;


int main(){
Prova vetor[3];
float mediaPonderada, p1, p2, p3;
for (int  i = 0; i < 3; i++){
    printf("Digite a nota da P%d:", i+1);
    scanf("%f", &vetor[i].nota);
    printf("Digite o peso da P%d:", i+1);
    scanf("%d", &vetor[i].peso);
    switch (i){
        case 0:
            p1 = vetor[i].nota * vetor[i].peso;
            break;
        case 1:
            p2 = vetor[i].nota * vetor[i].peso;
            break;
        case 2:
            p3 = vetor[i].nota * vetor[i].peso;
        default:
            break;
    }    
    }
mediaPonderada = (p1 + p2 + p3)/ (vetor[0].peso + vetor[1].peso + vetor[2].peso);
printf("Média ponderada: %.2f\n", mediaPonderada );
if (mediaPonderada < 6.0){
    printf("\nO aluno foi reprovado!");
} else {
    printf("\nO aluno foi aprovado!");
}
    return 0;
}