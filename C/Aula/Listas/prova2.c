// 1 - receber 5 numeros inteiros e identificar o menor número.
#include <stdio.h>

int main(){
int num1, num2, num3, num4, num5, menor;
    printf("entre com os valores de 5");
    scanf("%d %d %d %d %d", &num1, &num2, &num3, &num4, &num5);
    menor = num1;

    if (num2<menor){
        menor = num2;
    } else if (num3<menor){
        menor = num3;
    } else if (num4<menor){
        menor = num4;
    } else if (num5<menor){
        menor = num5;
    }
    printf("O menor número é %d", menor);

    return 0;
}