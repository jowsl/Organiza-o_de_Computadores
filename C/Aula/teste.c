#include <stdio.h>

struct Racional {
    int numerador;
    int denominador;
};
typedef struct Racional Racional;

int calcularMDC(int a, int b) {
    int resto;
    while (b != 0) {
        resto = a % b;
        a = b;
        b = resto;
    }
    return a;
}

int calcularMMC(int a, int b) {
    return (a * b) / calcularMDC(a, b);
}

int main() {
    Racional r1;
    int MMC, MDC;

    printf("Digite numerador e denominador de r1: ");
    scanf("%d %d", &r1.numerador, &r1.denominador);

    // Calculando o MDC e o MMC
    MDC = calcularMDC(r1.numerador, r1.denominador);
    MMC = calcularMMC(r1.numerador, r1.denominador);

    // Saída dos resultados
    printf("MDC: %d\n", MDC);
    printf("MMC: %d\n", MMC);

    // Teste de simplificação
    int numeradorSimplificado = r1.numerador / MDC;
    int denominadorSimplificado = r1.denominador / MDC;
    printf("Numerador simplificado: %d\n", numeradorSimplificado);
    printf("Denominador simplificado: %d\n", denominadorSimplificado);

    return 0;
}
