// Jouberth Matheus Simão Pereira nº23.2.4011
#include <stdio.h>
#include <string.h>
#define MAX 500

int testePalindromo(char palavra[MAX], int tamanho);

int main(){
    char palavra[MAX];
    int palaindromo=1, tamanho;
do{
    printf("Digite uma palavra ou FIM para sair:");
    scanf("%s", palavra);
    tamanho = strlen(palavra);
    if (strcmp (palavra, "FIM") == 0){
    break;
    }
    palaindromo=testePalindromo(palavra, tamanho); 
    if (palaindromo == 1) {
            printf("%s é um palíndromo.\n", palavra);
        } else {
            printf("%s não é um palíndromo.\n", palavra);
        }
} while (1);
    return 0;
}
int testePalindromo(char palavra[MAX], int tamanho){
    int comeco = 0;
    int fim = tamanho - 1;
    while (comeco < fim) {
        if (palavra[comeco] != palavra[fim]) {
            return 0;
        }
        comeco++;
        fim--;
    }
    return 1;
}