// Jouberth Matheus Simão Pereira nº23.2.4011
#include <stdio.h>
#define MAX 10


void printadorBrabo(char vEvogal[MAX], int nVogal){
printf("%d vogais:", nVogal);
for (int i = 0; i<nVogal; i++){
    printf("%c ", vEvogal[i]);
}
printf("\n");
}

void printadorBrabo2(char vEconsoante[MAX], int nConsoante){
printf("%d consoantes:", nConsoante);
for (int i = 0; i<nConsoante; i++){
    printf("%c ", vEconsoante[i]);
}
printf("\n");
}

int main(){
char vetorLetras[MAX], vetorVogais[] = {'a', 'e', 'i', 'o', 'u'}, vEconsoante[MAX], vEvogal[MAX];
int nVogal=0, nConsoante=0;
for(int i = 0; i<MAX; i++){
    printf("\nDigite o %d caractere: ", i+1);
    //fflush(stdin); // windows
    scanf("%c", &vetorLetras[i]);
    getchar();
}
    for (int i = 0; i<MAX; i++){
        int testeVogal = 0;
        for (int j = 0; j < 5; j++){
            if (vetorLetras[i] == vetorVogais[j]){
            vEvogal[nVogal] = vetorLetras[i];
            nVogal++;
            testeVogal = 1;
            break;
            }
        }
        if (testeVogal==0){
            vEconsoante[nConsoante] = vetorLetras[i];
            nConsoante++;
            }
        }
    printadorBrabo(vEvogal, nVogal);
    printadorBrabo2(vEconsoante, nConsoante);
    return 0;
}