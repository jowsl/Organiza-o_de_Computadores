#include <stdio.h>

float somadorBolado(float, float);

int main(){
float num1 = 0, num2 = 0, soma, numero;
do{
    printf("\nSelecione uma opção\n"
    "[1.Soma]\n"
    "[2.Ajuda]\n"
    "[0.Encerrar]\n");
    scanf("%f", &numero);
    if(numero == 1){
    soma = somadorBolado(num1, num2);
    printf("O dos números é: %.2f ", soma);
    } else if (numero == 2){
    printf("\nEste é um programa de soma simples, selecione [1. Soma] no menu principal e digite dois valores\n\n");
}
} while( numero != 0);

    return 0;
}
float somadorBolado(float num1, float num2){
    printf("Entre com dois números para serem somados: \n");
    scanf("%f %f", &num1, &num2);
    return num1 + num2;
}
