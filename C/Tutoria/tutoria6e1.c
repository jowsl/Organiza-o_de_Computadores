// Jouberth Matheus Simão Pereira n23.2.4011
#include <stdio.h>


int main(){
int num1, num2, intervalo;
    printf("Entre com o número do intervalo: ");
        scanf("%d", &intervalo);
        printf("Entre com dois números: ");
        scanf("%d %d", &num1, &num2);
    while ((num1 <= 0 && num2 <= 0) || (num1 > intervalo || num2 > intervalo)){
        printf("\nNúmero fora do intervalo!");
        printf("\nEntre com dois números: ");
        scanf("%d %d", &num1, &num2);
    } 
    printf("A soma é igual a %d\n", num1 + num2);
    return 0;
}