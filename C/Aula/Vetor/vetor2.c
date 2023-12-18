#include <stdio.h>
#define TAM_MAX 5
int main(){
double notas[TAM_MAX];
    for (int i = 0; i < TAM_MAX; i++){
        printf("\nDigite a nota %d ", i+1); // Pediu pra adicionar a nota de número i+1
        scanf("%lf", &notas[i]); // A nota vai ser armazenada no espaço de memoria do vetor referente ao local do número contido em i   
    }
    double maiorNota = 0;
    for (int i = 0; i < TAM_MAX; i++){ 
        if (notas[i]> maiorNota){ //passamos por cada posição do vetor notas[] e testamos se são maiores q 0 (e depois para outros valores)
            maiorNota = notas[i]; //Assim sempre substituimos a variavel maiorNota pelo maior valor nos espaços do vetor notas[]
        }
    }
            printf("\nMaior nota é %0.lf \n\n", maiorNota);
    
    return 0;
}