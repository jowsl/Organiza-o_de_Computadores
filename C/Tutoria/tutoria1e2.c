#include <stdio.h>

int main(){
 int velocidade, multa;
    printf("Entre o valor da velocidade limite: ");
        scanf("%d", &velocidade);
    if (velocidade >= 63 && velocidade <69) {
        multa = 300 + (300*0.05);
        printf("Valor da multa: %d\n", multa);
    } else if (velocidade>=69 && velocidade<72){
        multa = 300 + (300*0.17);
        printf("Valor da multa: %d\n", multa);
    } else if (velocidade>=72){
        multa = 300 + (300*0.23);
        printf("Valor da multa: %d\n", multa);
    } else printf("NÃO HOUVE INFRAÇÃO\n\n");

    return 0;
}