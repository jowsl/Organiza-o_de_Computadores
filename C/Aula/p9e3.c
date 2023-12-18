// Jouberth Matheus Simão Pereira nº23.2.4011
#include <stdio.h>
#include <string.h>
#define MAX 61

int main(){
    char nome[MAX], sobrenome[MAX], primeiro[MAX], concatenados[1000];
    int letras=0, letras2=0;
    int i, x;

    printf("Digite o nome completo: ");
    fgets(nome, MAX, stdin);
    nome[strcspn(nome, "\n")] = 0;
    
    for ( i = strlen(nome) - 1; i >= 0 && nome[i] != ' '; i--);
    strcpy(sobrenome, &nome[i + 1]);
    for ( i = 0; nome[i] != ' '; i++);
    strncpy(primeiro, nome, i);
    primeiro[i] = '\0';

    for (x = 0; x < i; x++) {
        if (primeiro[x] != ' ') {
            letras++;
        }
    }
    for (x = 0; x < strlen(sobrenome); x++) {
        if (sobrenome[x] != ' ') {
            letras2++;
        }
    }
    letras = letras + letras2;
    printf("%s, %s\n", sobrenome, primeiro);
    printf("Total de letras: %d\n", letras);
    printf("Total de letras do último sobrenome: %d\n\n", letras2);
    return 0;
}
