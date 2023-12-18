// Jouberth Matheus Simão Pereira nº23.2.4011
#include <stdio.h>

int main(){
float numN;
//float contador=0;
float resultado=0;
printf("\nDigite um valor: ");
scanf("%f", &numN);
resultado = resultado+numN;
float contador=0;
if(numN==0){
    printf("Não foi possível calcular MA!");
    return 0;
} else {
    do{
        printf("\nDigite um valor: ");
        scanf("%f", &numN);
        resultado = resultado+numN;
        contador++;
    } while(numN!=0);
}
printf("\nMA = %.2f\n\n", (1/contador)*resultado);
    return 0;
}