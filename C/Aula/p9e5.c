// Jouberth Matheus Simão Pereira nº23.2.4011
#include <stdio.h>

int main(){
int matriz[3][3], maior, menor; // declarando a matriz 'i' para linhas e 'j' para colunas
for (int i = 0; i < 3; i++) // for para preencher linhas 
    for (int j = 0; j < 3; j++){ // for para preencher colunas dentro do mesmo for das linhas
        scanf("%d", &matriz[i][j]); // salvando os valores em linhas e colunas
    }
    maior = menor = matriz[0][0];
for (int i = 0; i < 3; i++){  // verificador maior
    for (int j = 0; j < 3; j++){ 
        if (matriz[i][j]> maior){
            maior = matriz[i][j];
        } if (matriz[i][j]< menor){
            menor = matriz[i][j];
        }
        
    }
   
}
printf("Maior elemento:%d\n", maior);
printf("Menor elemento: %d\n", menor);

    return 0;
}