// Jouberth Matheus Simão Pereira nº 23.2.4011
#include <stdio.h>
#include <math.h>

// protótipos
float delta(int a, int b, int c);
float r1(int a, int b, float delta);
float r2(int a, int b, float delta);

int main(){
float a, b, c, d, raiz1, raiz2;
    printf("\nEntre com os valores de a, b e c: ");
        scanf("%f %f %f", &a, &b, &c);
    d = delta(a, b, c);
    raiz1 = r1(a, b, d);
    raiz2 = r2(a, b, d);
    if (d<0){
        printf("Não existem raizes reais para um delta igual a zero!");
            return 0;
    } else if (d == 0 && raiz1>0){
        printf("\nA unica raíz possível é %.2f ", raiz1);
        return 0;
    } else if (d == 0 && raiz1<0){
        printf("\nA unica raíz possível é %.2f ", raiz2);
    } else {
    printf("\nO valor da primeira raíz é %.2f e a segunda é %.2f \n\n", raiz1, raiz2);
}
    return 0;
}

// funções
float delta(int a, int b, int c){
    return (pow(b,2) * -(4*a * c));  
}
float r1(int a, int b, float delta){
    return (-b + sqrt(delta) )/ (2 * a);
}
float r2(int a, int b, float delta){
    return (-b - sqrt(delta) )/ (2 * a);
}