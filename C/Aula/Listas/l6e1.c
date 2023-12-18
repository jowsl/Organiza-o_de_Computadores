#include <stdio.h>

int contaCaractere(char* str, char c) {
    int cont = 0;
    for(int i = 0; str[i] != '\0'; i++) {
        if(str[i] == c) {
            cont++;
        }
    }
    return cont;
}

int main() {
    char str[100];
    char c;

    printf("Digite uma string: ");
    fgets(str, sizeof(str), stdin);
    
    printf("Digite um caractere: ");
    scanf("%c", &c);

    int cont = contaCaractere(str, c);
    printf("O caractere '%c' aparece %d vezes na string.\n", c, cont);

    return 0;
}
