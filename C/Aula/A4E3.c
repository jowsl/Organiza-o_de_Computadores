#include <stdio.h>

int main(){
    float numero1, numero2, total;
    char X;
    printf("Digite dois números: \n");
        scanf("%f %f", &numero1, &numero2);
    printf("Digite um operador matemático (+, -, *, /): \n");
        scanf(" %c", &X);
        switch (X){
        case '+': 
        total = numero1 + numero2;
        break;
        case '-':
        total = numero1 - numero2;
        break;
        case '*':
        total = numero1 * numero2;
        break;
        case '/':
            if (numero2 != 0){
            total = numero1 / numero2;
            } else {
            printf("Erro: Divisão por 0 não existe. \n\n");
            return 0;
            } 
        break;
        default: 
        printf("Operador incorreto!\n\n");
        return 0;
        break;
        }
        printf("Resultado: %.2f %c %.2f = %.2f\n\n", numero1, X, numero2, total);
    return 0;
}
