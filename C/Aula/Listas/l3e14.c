#include <stdio.h>

int main(){
int num1, num2, resultado;
char x;
do{
resultado = 0;
printf("Digite dois números: ");
scanf("%d %d", &num1, &num2);
printf("\nDigite uma operação + - * / :");
scanf(" %c", &x);
switch (x){
case '+':
    resultado=num1+num2;
    break;
case '-':
    resultado=num1-num2;
    break;
case '*':
    resultado=num1*num2;
    break;
case '/':
if (num2==0){
    printf("Erro: divisão por zero.\n\n");
    return 0;
}
    resultado=num1/num2;
    break;
default:
    break;
}
printf("\nResultado: %d\n\n", resultado);
} while (x == '+'||x=='-'||x=='*'||x=='/');
    return 0;
}