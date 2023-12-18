#include <stdio.h>
// Jouberth Matheus Simão Pereira nº 23.2.4011

// protótipos das funções
float calculoMedia(float);
float calculoSoma(int, int, int, int, int);


int main(){
    char X;
    int num1, num2, num3, num4, num5;
    float resultadoGeral, resultadoSoma;
    
    printf("\nDigite 'M' para calcular a média ou 'S' para calcular a soma dos 5 valores inteiros: ");
        scanf("%c", &X);
    printf("\nDigite 5 números inteiros para que seja calculado a média ou soma: ");
        scanf("%d %d %d %d %d", &num1, &num2, &num3, &num4, &num5);
    resultadoSoma = calculoSoma(num1, num2, num3, num4, num5);
    switch (X){
    case 'M':
        resultadoGeral = calculoMedia(resultadoSoma);
        break;
    case 'S':
        resultadoGeral = resultadoSoma;
        break;
    default:
        printf("\nErro, digite apenas 'M' ou 'S'! \n\n");
            return 0;
        break;
    }    
    printf("\nResultado é: %.2f \n\n", resultadoGeral);

    return 0;
}

// Definições das funções
float calculoMedia(float resultadoSoma){
    float A;
        A = resultadoSoma/5;
    return A;
}
float calculoSoma(int num1, int num2, int num3, int num4, int num5){
    float f;
        f = num1 + num2 + num3 + num4 + num5;
    return f;
}