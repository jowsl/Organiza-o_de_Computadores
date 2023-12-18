#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
    srand(time(NULL));
    int sorte = rand() % 100;
    printf("\nNúmero aleatório entre 0 e 99: %d\n\n", sorte);
    
    return 0;
}    