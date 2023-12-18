#include <stdio.h>
#include <math.h>

double calSoma(double, double);
double calProduto(double, double);
double calQuadrado(double);
double calRaiz(double, double);
double calSeno(double, double);
double calModulo(double, double);

int main(){
double num1, num2, a, b, c, d, e, f;
printf("Entre com dois números reais: \n");
    scanf("%lf %lf", &num1, &num2);

a = calSoma(num1, num2);
b = calProduto(num1, num2);
c = calQuadrado(num1);
d = calRaiz(num1, num2);
e = calSeno(num1, num2);
f = calModulo(num1, num2);

printf("A soma dos numeros é: %.2lf \n"
"O produto do primeiro numero pelo quadrado do segundo é: %.2lf \n"
"O quadrado do primeiro numero é: %.2lf \n" 
"A raiz quadrada da soma dos quadrados é: %.2lf \n" 
"O seno da diferenca do primeiro numero pelo segundo é: %.2lf \n"
"O modulo do primeiro numero é: %.2lf \n", a, b, c, d, e, f);

    return 0;
}
double calSoma(double num1, double num2){
    return num1 + num2;
}
double calProduto(double num1, double num2){
    return num1 * pow(num2,2);
}
double calQuadrado(double num1){
    return pow(num1,2);
}
double calRaiz(double num1, double num2){
    return sqrt( (pow(num1,2) + pow(num2,2)) );
}
double calSeno(double num1, double num2){
    return sin( num1 / num2);
}
double calModulo(double num1, double num2){
    return fabs(num1);
}