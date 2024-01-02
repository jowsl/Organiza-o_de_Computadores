// Jouberth Matheus Simão Pereira nº23.2.4011
#include <stdio.h>
#define num 100

typedef struct {
    float nlados; // numero de lados
    float tlados; // tamanho dos lados
    float apo; // apótema
    float peri; // perímetro
    float   area; 
} Poligono;

void calculoPoli(Poligono *ponteiro);
void printadorPoli(Poligono *ponteiro, int nPoli);

int main(){
Poligono poligonos[num];
int nPoli;

    printf("Digite o nú mero de polígonos regulares (0 < n <= 100): ");
    scanf("%d", &nPoli);
    while (nPoli<=0 || nPoli>100){
        printf("Valor inválido. Digite o número de polígonos: ");
        scanf("%d", &nPoli);
    }
    for (int i = 0; i < nPoli; i++){
        printf("Polígono Regular %d", i+1);
        
        printf("\nNúmero de lados: ");
        scanf("%f", &poligonos[i].nlados);
        while (poligonos[i].nlados<3){
            printf("Valor inválido. Número de lados: ");
            scanf("%f", &poligonos[i].nlados);
        }
        
        printf("Tamanho dos lados: ");
        scanf("%f", &poligonos[i].tlados);
        while (poligonos[i].tlados<0){
            printf("Valor inválido: Tamanho dos lados: ");
            scanf("%f", &poligonos[i].tlados);
        }
        
        printf("Apótema: ");
        scanf("%f", &poligonos[i].apo);
        while(poligonos[i].apo>poligonos[i].tlados){
            printf("Valor inválido. Apótema: ");
            scanf("%f", &poligonos[i].apo);
        }
        calculoPoli(&poligonos[i]);
    }
    printf("\n");
    for (int i = 0; i < nPoli; i++){
        printf("Polígono Regular %d:\n", i+1);
        printadorPoli(&poligonos[i], nPoli);
    }
    return 0;
}

void calculoPoli(Poligono *ponteiro){
    ponteiro->peri = ponteiro->nlados * ponteiro->tlados;
    ponteiro->area = (0.5 * ponteiro->peri) * ponteiro->apo;
}

void printadorPoli(Poligono *ponteiro,int nPoli){
    printf("Perímetro: %.2f\n", ponteiro->peri);
    printf("Área: %.2f\n", ponteiro->area);   
    printf("\n");
}