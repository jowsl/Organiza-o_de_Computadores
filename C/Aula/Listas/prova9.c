#include <stdio.h>
#include <math.h>

// Protótipo
double calculoIMC(double, double);

int main(){
double kg, altura, imc;
    printf("Entre com sua altura(m) e peso(kg).\n");
    scanf("%lf %lf", &altura, &kg);
    imc = calculoIMC(kg, altura);
    printf("\nSeu IMC é: %.2lf\n\n", imc);

    return 0;
}
//Função
double calculoIMC(double kg, double altura){
    return (kg) / (pow(altura,2));
}