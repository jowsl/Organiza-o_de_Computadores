// Jouberth Matheus Simão Pereira nº23.2.4011
#include <stdio.h>
#include <string.h>
#include <stdio_ext.h>

typedef struct{
    char nome[50];
    int ano;
    float motor;    
}Carro;

int main(){
Carro vetor[3], carroTempMotor, carroTempNovo;
    carroTempMotor.motor = 0;
    carroTempNovo.ano = 0;
    for (int i = 0; i < 3; i++){
        printf("Digite o nome do carro %d:", i+1);
        __fpurge(stdin);
        fgets(vetor[i].nome, 50, stdin);
        printf("Digite o ano de fabricação do carro %d:", i+1);
        scanf("%d", &vetor[i].ano);
        printf("Digite a versão do motor do carro %d:", i+1);
        scanf("%f", &vetor[i].motor);\
        printf("\n");
        if (carroTempNovo.ano<vetor[i].ano){
            strcpy(carroTempNovo.nome, vetor[i].nome);
        }
        if (carroTempMotor.motor<vetor[i].motor){
            strcpy(carroTempMotor.nome, vetor[i].nome);
        }
    }
printf("Carro mais novo: %s\n", carroTempNovo.nome);
printf("Carro com a maior versão do motor: %s\n\n", carroTempMotor.nome);
    return 0;
}