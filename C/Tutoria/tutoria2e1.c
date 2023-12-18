#include <stdio.h>
// Jouberth Matheus Simão Pereira nº 23.2.4011

// Protótipo da função
float calculoSoma(float , float);
float calculoSub(float , float);
float calculoMult(float , float);
float calculoDivi(float , float);

int main (){
    float num1, num2, resultado;
    char X;
    printf("Escolha uma operação [ + - / *]: ");
        scanf("%c", &X);
    printf("Digite dois número: ");
        scanf("%f %f", &num1, &num2);
    switch (X){
    case '+':
        resultado = calculoSoma(num1, num2);
        break;
    case '-':
        resultado = calculoSub(num1, num2);
        break;
    case '*':
        resultado = calculoMult(num1, num2);
        break;
    case '/':
        resultado = calculoDivi(num1, num2);
        break;
    default:
        printf("Erro: Operador inválido!\n\n");
        break;
    }
    printf("O resultado é: %.2f \n", resultado);

    return 0;
}

//definição das funções
float calculoSoma(float num1, float num2){
    return num1 + num2;
}
float calculoSub(float num1, float num2){
    return num1 - num2;
}
float calculoMult(float num1, float num2){
    return num1 * num2;
}
float calculoDivi(float num1, float num2){
    return num1 / num2;
}
