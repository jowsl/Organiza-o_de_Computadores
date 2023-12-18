#include <stdio.h>

int main(){
int num;
    printf("Digite um número qualquer: \n");
    scanf("%d", &num);
    if(num % 2 == 0)
    {
        printf("O número é par!\n\n");
    } 
    else 
    {
        printf("O número é impar!\n\n");
    }

    return 0;
}