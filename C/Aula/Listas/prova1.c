// 12
#include <stdio.h>
#include <math.h>

// protótipo
float decimalInteiro(float num1, float *decimal, float *inteiro);

int main(){
    float num1, decimal, inteiro;
    printf("Entre com um número real: ");
    scanf("%f", &num1);
    decimalInteiro(num1, &decimal, &inteiro);
    printf("Decimal = %f e inteiro = %.0f ", decimal, inteiro);

    return 0;
}
float decimalInteiro(float num1, float *decimal, float *inteiro){
    *inteiro = trunc(num1);
    *decimal = num1 - *inteiro;
    return 0;
}
