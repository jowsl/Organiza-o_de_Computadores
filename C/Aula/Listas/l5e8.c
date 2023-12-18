#include <stdio.h>
#define max 10

int main(){
int vPar[max], vImpar[max], vetorMax[max], contPar=0, contImpar=0;
printf("Digite os valores do vetor: ");
for (int i = 0; i < max; i++){
    scanf("%d", &vetorMax[i]);
}
for(int i=0;i<max;i++){
    if (vetorMax[i]%2==0){
        vPar[contPar]=vetorMax[i];
         contPar++;
    } else {
        vImpar[contImpar]= vetorMax[i];
        contImpar++;
    } 
}
printf("Valores do vPar: ");
for (int i = 0; i < contPar; i++){
    printf("%d ", vPar[i]);
}
printf("\n");
printf("Valores do vImpar: ");
for (int i = 0; i < contImpar; i++){
    printf("%d ", vImpar[i]);
}
    return 0;
}
