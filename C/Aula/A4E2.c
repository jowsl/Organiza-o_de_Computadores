#include <stdio.h>

int main(){
    float numero1, numero2, total;
    char X;
    printf("Digite dois números: \n");
        scanf("%f %f", &numero1, &numero2);
    printf("Digite um operador matemático (+, -, *, /): \n");
        scanf(" %c", &X);  // ??????????????
        if ( X == '+' )
        {
        total = numero1 + numero2;
        }
        else if ( X == '-' )
        {
            total = numero1 - numero2;
        }
        else if ( X == '*' )
        {
            total = numero1 * numero2;
        }
        else if ( X == '/' ) // Caso seja digitado um valor zero: fazer um "if" para mostrar a mensagem de erro
        {
            total = numero1 / numero2;
        }
    printf("Seu resultado é: %.2f\n\n", total);

    return 0;
}
