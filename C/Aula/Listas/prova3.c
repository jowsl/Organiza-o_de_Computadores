#include <stdio.h>
#include <math.h>

int main(){
int num1, num2, quadrado;
float raiz;
printf("Entre com dois números: ");
    scanf("%d %d", &num1, &num2);
if (num1 == num2){
    printf("Os números são iguais!");
    return 0;
}
if (num1>num2){
    quadrado = pow(num2,2);
    raiz = sqrt(num1);
} else {
    quadrado = pow(num1,2);
    raiz = sqrt(num2);
} 
printf("O quadrado do menor é %d e a raiz do maior é %.2f ", quadrado, raiz);
}