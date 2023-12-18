#include <stdio.h>
#define max 365

int main(){
float vDias[max], media=0;
    for (int i = 0; i < max; i++){
        printf("Entre com a temperatura do dia %d: ", i);
        scanf("%f", &vDias[i]);
        media = vDias[i]+media;
    }
media = media/max;
printf("Temperatura media é: %.2f\n", media);
printf("Temperaturas abaixo da media: ");
for (int i = 0; i < max; i++){
    if (vDias[i]<=media){
        printf("%.2f ", vDias[i]);
    }
    printf("\n");
}
    return 0;
}