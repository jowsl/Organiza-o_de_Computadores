#include <stdio.h>
#include <stdlib.h>

int main(){
int num1, num2;

    printf("Digite dois valores: \n");
    scanf("%d %d", &num1, &num2);
    /*    if(num1==num2)
        {
           printf("Os números devem ser diferentes. \n");
           return 0;
        }*/
    if(num1 > num2)
    {
        printf("%d maior e %d menor\n", num1, num2);
    }
        else
    {
        printf("%d maior e %d menor\n", num2, num1);
    } 

    return 0;
}