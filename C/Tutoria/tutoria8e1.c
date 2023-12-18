#include <stdio.h>

void Fibonacci(int n){
    int num1=1, num2=1, num3;
    for(int i = 1; i <= n; i++){
        printf("%d ", num1);
        num3 = num1 + num2;
        num1 = num2;
        num2 = num3;
    }
}
int main(){
int n;
printf("Digite a quantidade de números da sequência:");
scanf("%d", &n);
Fibonacci(n);

    return 0;
}