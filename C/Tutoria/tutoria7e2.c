// Jouberth Matheus Simão Pereira
#include <stdio.h>

int main(){
int numero;
printf("Digite o tamanho do triângulo: ");
scanf("%d", &numero);
int x, y;
for (x = numero; x >= 1; x--) { 
    for(y = 1; y <=  x; y++){
        printf("* ");
    }
    printf("\n");
}
    return 0;
}