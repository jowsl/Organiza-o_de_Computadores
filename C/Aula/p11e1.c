// Jouberth Matheus Simão Pereira nº23.2.4011
#include <stdio.h>


struct Racional {
    int numerador;
    int denominador;
};
typedef struct Racional Racional;

int mdcCalculo(int x, int y);

int main(){
Racional r1, r2;
int MDC;
double r1nRed, r1dRed, r2nRed, r2dRed;  // Variáveis pra armazenar os termos reduzidos
    printf("Digite numerador e denominador de r1: ");
    scanf("%d %d", &r1.numerador, &r1.denominador);
    printf("Digite numerador e denominador de r2: ");
    scanf("%d %d", &r2.numerador, &r2.denominador);
    MDC = mdcCalculo(r1.numerador, r1.denominador);
    r1nRed = r1.numerador / MDC;
    r1dRed = r1.denominador / MDC;
    MDC = mdcCalculo(r2.numerador, r2.denominador);
    r2nRed = r2.numerador / MDC;
    r2dRed = r2.denominador / MDC;
    if ( (r1nRed/r1dRed) == (r2nRed/r2dRed)){
        printf("r1 e r2 são iguais a (%.2lf / %.2lf)!\n\n", r1nRed, r1dRed);
        return 1;
    } else { 
    printf("r1 e r2 são diferentes!\n\n");
    }
    return 0;
}
int mdcCalculo(int x, int y){
    int resto;
        while (y != 0){
        resto = x % y;
        x = y;
        y = resto;
    }
    return x;   
}
