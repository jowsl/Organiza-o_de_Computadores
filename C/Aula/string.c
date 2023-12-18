#include <stdio.h>
#include <string.h>
// Funções importantes:
//char *strcpy(char x[],char y[]);
// copia todo conteudo da string x para a y com \0 no final, basta garantir que o espaço
// em y senha strlen(x)+1
// strlen(x) me da a quantidade de elementos dentro do vetor, até chegar no \0
// *strcat(char x[],char y[])
// vai unir as duas funções, colocar o conteúdo de y[] dentro de x[], garantir que x[] possui o espaço suficiente.
// strcmp(char x[], char y[])
// vai comparar as duas strings. Retorna um numero negativo se x vier antes de y
// retorna um positivo se x vem depois de y
// retorna 0 se x é igual a y
// gets(x) vai ler a entrada até o usuário colocar uma quebra de linha
// fgets(x, n, stdin) onde n é o número máximo q vc vai colocar ali dentro, para quando detectar quebra de linha ou atingir o n.
// o stdin mostra de onde virá os caracteres, a entrada padrão do usuário. 
// fgets inclui o \n na string -- EVITE usar a função gets, pois não sabemos quantos char o usuário vai preencher.
/*
int main(int argc, char *argv[]){    // argv é um vetor de strings
    return 0;
}
*/

