// Jouberth Matheus Simão Pereira nº23.2.4011
#include <stdio.h>
#include <string.h>

typedef struct{
    char modelo[26];
    float consumo; //quanto cada um faz por litro    
}Carro;
int carroEconomico(Carro vetor[5]);
void litroKm(Carro vetor[5]);


int main(){
Carro vetor[5];

    for (int i = 0; i < 5; i++){
        printf("Carro %d:", i);
        printf("Modelo: ");
        scanf("%s", vetor[i].modelo);
        printf("Consumo (km/l):");
        scanf("%f", &vetor[i].consumo);
        
    }
int x = carroEconomico(vetor);
printf("Mais econômico: %s\n", vetor[x].modelo);
printf("Consumo em 1000 km\n");
litroKm(vetor);

    return 0;
}

int carroEconomico(Carro vetor[5]){
    int x = 0;
    for(int i = 1; i < 5; i++){
        if(vetor[i].consumo > vetor[x].consumo){
            x = i;
        }
    }
    return x;
}

void litroKm(Carro vetor[5]){
    for (int i = 0; i < 5; i++){
        printf("%s %.2f\n", vetor[i].modelo, 1000/vetor[i].consumo);
    }
}