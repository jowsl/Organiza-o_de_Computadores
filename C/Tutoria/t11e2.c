// Jouberth Matheus Simão Pereira nº23.2.4011
#include <stdio.h>
#define max 100

int testePrimo(int v25primos[25],int cemNumeros[max]){
int quantos = 0;
    for (int i = 2; i <=max; i++){
        int ePrimo=1;
        for (int j = 2; j*j <=i; j++){
        if (i % j == 0){
            ePrimo=0;
            break;
        }
        } 
        if (ePrimo==1){
            v25primos[quantos] = i;
            quantos++;
            if (quantos == 25)
            break;  
        }         
    }
    return 0;
}
int main(){
int v25primos[25], cemNumeros[max];
for (int x = 0; x <max; x++){
    cemNumeros[x] = x+1;
}
testePrimo(v25primos, cemNumeros);
printf("[ ");
for (int y = 0; y < 25; y++){
    printf("%d ", v25primos[y]);
}
printf("]\n");
    return 0;
}