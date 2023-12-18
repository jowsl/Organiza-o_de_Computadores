#include <stdio.h>

int main(){
    int x = 100;
    int *px = &x;
    printf("Valor de X  %d\n", x);
    printf("Endereço de X %p: \n", &x);
    printf("Endereço de X %p: \n", px);
    printf("Valor de X %d\n", *px);
    
    return 0;
}