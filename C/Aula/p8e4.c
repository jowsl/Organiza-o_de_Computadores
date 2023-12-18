// Jouberth Matheus Simão Pereira nº23.2.4011
#include <stdio.h>

void acimaMedia( float vTemperatura[30], float media){
printf("\nAcima:");
int contador=0;
    for (int i = 0; i <=29; i++){
        if (vTemperatura[i]>media)
        contador++;
    }
printf("%d", contador);
}
void abaixoMedia(float vTemperatura[30], float media){
printf("\nAbaixo:");
int contador=0;
    for (int i = 0; i <=29; i++){
        if (vTemperatura[i]<media)
        contador++;
    }
printf("%d", contador);
}

int main(){
float vTemperatura[30], media;
printf("Entre com as temperaturas:");
for (int i = 0; i < 30; i++){
    scanf("%f", &vTemperatura[i]);
    media = media+vTemperatura[i];
}
media = media/30;
//printf("média: %f ", media);
acimaMedia(vTemperatura, media);
abaixoMedia(vTemperatura, media);
    return 0;
}