// Jouberth Matheus Simão Pereira nº 23.2.4011
#include <stdio.h>
#include <math.h>

// protótipo
float distanciaDoisPontos(float x1, float x2, float y1,float y2);

int main(){
float x1, x2, y1, y2, distancia;
    printf("\nDigite as cordenadas de P1: ");
        scanf("%f %f", &x1, &y1);
    printf("\nDigite as cordenadas de P2: ");
        scanf("%f %f", &x2, &y2);
    distancia = distanciaDoisPontos(x1, x2, y1, y2);

    printf("\nDistancia = %f", distancia);

    return 0;
}

//função
float distanciaDoisPontos(float x1, float x2, float y1,float y2){
    return sqrt(pow((x1-x2),2)+pow((y1-y2),2));
}