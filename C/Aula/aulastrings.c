#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[]){
char palavra[100];

printf("Digite uma palavra: ");
// scanf("%s", palavra); - FORMA 1 - 
// gets(palavra); - FORMA 2 - não segura.
fgets(palavra, 99, stdin);       // ATENÇÃO, o fgets() adiciona o '\n' no final da string, DEVEMOS ENTÃO: 
                                 // retirar o '\n' ou incluir o '\n' na comparação
                                 // RETIRANDO: int tam = strlen(palavra); Salvando tamanho da string em uma variável
                                 // palavra[tam-1]='\0'; pegando o tamanho da string -1 (q é o \0 atual, e colocando outro \0 no lugar do \n)
                                 // incluindo na comparação seria "if (strcmp(palavra, "UFOP\n")==0);"
                                 // int tam = strlen(palavra);
palavra[strlen(palavra) -1] = '\0';   // alternativa para n precisar usar uma variável intermediária 
    if (strcmp(palavra, "UFOP") == 0) // strcmp retorna um número NEGATIVO se 'palavra' vier antes de UFOP, 
        puts("Bem vindo a Ouro Preto!\n");  //  POSITIVO se vier depois de UFOP, e 0 se forem iquais 
        // put string é um comando tambem usado para imprimir

    return 0;
}