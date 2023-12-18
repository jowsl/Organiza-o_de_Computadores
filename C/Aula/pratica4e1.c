#include <stdio.h>
#include <math.h>
//Jouberth Matheus Simão Pereira nº 23.2.4011

// Protótipo da função
float calculaArea(float);

int main(){
    float lado;
    printf("\nDigite o lado do dodecaedro regular: " );
        scanf("%f", &lado);
    float area = calculaArea(lado);

    printf("\nA area e: %.2f\n", area);
    return 0;
}

// Função
float calculaArea(float lado){
    float area;
    area = 3 * pow(lado,2) * sqrt(25 + 10*sqrt(5));

    return area;
}

