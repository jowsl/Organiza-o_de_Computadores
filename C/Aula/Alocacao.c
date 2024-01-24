#include <stdio.h>
#include <stdlib.h>

int main (){
int *numero = malloc(sizeof(int)); // sizeof retorna o tamanho do tipo, nocaso do int 4bits
*numero = 3;

printf ("Endereço: %p\n", numero);
printf("Valor: %d\n", *numero);
free(numero);
    return 0;
}