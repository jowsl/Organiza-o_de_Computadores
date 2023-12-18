#include <stdio.h>

// Protótico da função 
double CelsiusToFahrenheit (double tempCel);

int main(){
double tempCelsius, tempFahrenheit;
    printf("Conversão Celsius para Fahrenheit\n");
    printf("Digite a temperatura em Celsius: ");
        scanf("%lf", &tempCelsius);
    if (tempCelsius >= -273.15){
        tempFahrenheit = CelsiusToFahrenheit(tempCelsius);
        printf("%lf graus Celsius = %lf graus Fahrenheit.\n\n", tempCelsius, tempFahrenheit);
    }
    return 0;
}