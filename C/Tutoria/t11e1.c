// Jouberth Matheus Simão Pereira nº23.2.4011
#include <stdio.h>

int main(){
float vAcordenadas[3], vBcordenadas[3], pEscalar;
printf("Digite as coodernadas do vertor A:");
for (int i = 0; i < 3; i++){
    scanf("%f", &vAcordenadas[i]);
}
printf("Digite as coodernadas do vertor B:");
for (int i = 0; i < 3; i++){
    scanf("%f", &vBcordenadas[i]);
}
pEscalar = (vAcordenadas[0]*vBcordenadas[0]) + (vAcordenadas[1]*vBcordenadas[1]) + (vAcordenadas[2]*vBcordenadas[2]);
printf("Produto escalar: %.1f", pEscalar);

    return 0;
}