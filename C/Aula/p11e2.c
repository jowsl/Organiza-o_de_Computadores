// Jouberth Matheus Simão Pereira nº23.2.4011
#include <stdio.h>
#include <math.h>

typedef struct{
    double x;
    double y;
} Ponto;

double distancia(double x, double y, double distPontos);

int main(){
Ponto pontos[40];
int n=0, contadorMaior=0, contadorMenor=0;
double distPontos, pmenor=999, pmaior=0.0;

    printf("Digite o número de pontos (0 < n <= 20):");
    scanf("%d", &n);

    while(n<=0 || n>20){
        printf("Valor inválido. Digite o número de pontos:");
        scanf("%d", &n);
    }

    for(int i=0; i < n ; i++){
        printf("Digite as coordenadadas x e y do ponto %d:", i+1);
        scanf("%lf %lf", &pontos[i].x, &pontos[i].y);
    }
    printf("\nDistâncias dos pontos até a origem:\n\n");

    for(int i=0; i < n ; i++){
        
        distPontos = distancia(pontos[i].x, pontos[i].y, distPontos);
        printf("P(%.1lf, %.1lf): %.1lf\n", pontos[i].x, pontos[i].y, distPontos);
        if (distPontos>pmaior){
            pmaior = distPontos;
            contadorMaior = i;
        }
        if(distPontos<pmenor){
            pmenor = distPontos;
            contadorMenor = i;
        }
    }

    printf("Menor distância: P(%.1lf, %.1lf) = %.1lf\n", pontos[contadorMenor].x, pontos[contadorMenor].y, pmenor);
    printf("Maior distância: P(%.1lf, %.1lf) = %.1lf\n", pontos[contadorMaior].x, pontos[contadorMaior].y, pmaior);

    return 0;
}

double distancia(double x, double y, double distPontos){
    distPontos =  sqrt(pow((x),2)+ pow((y),2));
    return distPontos;
}

