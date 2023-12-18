#include <stdio.h>

int main(){
float peso, altura, imc;
    printf("\nDigite o seu peso atual em kg: ");
        scanf("%f", &peso);
    printf("\nDigite agora sua altura em metros: ");
        scanf("%f", &altura);
    imc = peso/(altura*altura);
        printf("Valor do imc é: %.2f \n", imc);
    if (imc<18.5){
        printf("Abaixo do peso\n\n");
    } else if (25 <= imc){
        printf("Peso normal\n\n");
    } else if (25 <= imc && imc <= 30){
        printf("Acima do peso\n\n");
    } else { 
        printf("Obeso\n\n");
    }
    return 0;
}