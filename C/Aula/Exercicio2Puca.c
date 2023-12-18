#include <stdio.h>
// Jouberth Matheus Simão Pereira - nº23.2.4011

int main(){
float c, f, k;
    printf("Entre com o valor em graus Celsius: ");
    scanf("%f", &c);
        f = 9*c/5 + 32;
        k = c + 273.15;
    printf("\nCelsius: c = %.2f", c);
    printf("\nFahrenheit: f = %.2f", f);
    printf("\nKelvin: k = %.2f", k);
    return 0;
}