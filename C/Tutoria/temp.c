#include <stdio.h>
#include <string.h>
#define MAX 61

int main() {
    char frase[MAX], fraseInversa[MAX];
    printf("Entre com uma frase: ");
    fgets(frase, MAX, stdin);

    int x = strlen(frase) - 1;
    frase[x] = '\0'; // Remover a quebra de linha adicionada por fgets

    for (int i = 0; i < x; i++) {
        fraseInversa[i] = frase[x - 1 - i];
    }
    fraseInversa[x] = '\0'; // Adiciona o caractere nulo no final da string invertida

    printf("Frase Invertida: %s\n", fraseInversa);

    return 0;
}
