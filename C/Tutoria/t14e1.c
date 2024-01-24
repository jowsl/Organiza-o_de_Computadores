#include <stdio.h>
#include <string.h>
#define MAX 61

int main(){
char frase[MAX], fraseInversa[MAX];
printf("Entre com uma frase: ");
fgets(frase, MAX, stdin);

int x = strlen(frase) -1; // para retirar o \n q entrou na fgets
frase[x] = '\0';
for (int i = 0; i < x; i++){
    fraseInversa[i]=frase[x-1-i];
}
fraseInversa[x] = '\0'; // colocando '\0' na fraseInversa
printf("Frase inversa: %s\n", fraseInversa);
    return 0;
}