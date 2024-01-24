#include <stdio.h>
#include <stdlib.h>

int pirocaA(int num){
    if(num < 0)
        return 1;
    else
        return 0;
}


int main() {
int num;
scanf("%d", &num);
pirocaA(num);
    if (1)
        printf("hehe");

    return 0;
}
