#include <stdio.h>
#define max 50

float custoEnergia(float valor){
    float gasto = 0;
    if(valor<30)
        gasto=1.08*valor;
    else if(valor>30 && valor<120)
        gasto=1.08*valor+30;
    else if(valor>120)
        gasto=1.22*valor+30;
    return gasto;
}

int main(){
    int casas;
    float valor[max], v[max];
    printf("Digite a quantidade de residências: ");
    scanf("%d", &casas);
    if (casas>50||casas<0){
        printf("Valor inválido! Digite a quantidade de residências:");
        scanf("%d", &casas);
    }
    for (int i = 0; i < casas; i++){
        printf("Digite os gastos em KWh da residência %d:", i+1);
        scanf("%f", &valor[i]);
        v[i]=custoEnergia(valor[i]);
    }
    for (int i = 0; i < casas; i++){
        printf("Residência %d:Gasto:%.2f KWh - Custo: R$%.2f\n", i+1, valor[i], v[i]);
    }
    return 0;
}
