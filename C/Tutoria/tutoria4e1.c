// Jouberth Matheus Simão Pereira nº 23.2.4011
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//Protótipo

int ParOuImpar(int num1);
int calculaAleatorio();

int main(){ 
    int num1, numAle;
    printf("Digite um número: ");
        scanf("%d", &num1);
    numAle = calculaAleatorio();
    ParOuImpar(num1);
    if (num1 > numAle) {
        printf("e é  maior que %d\n\n", numAle);
    } else {
        printf("e não é  maior que %d\n\n", numAle);
    }
    return 0;
}
//Funções
int calculaAleatorio(){
srand (time(NULL));
int numAle = rand() % 99 +1;
    return numAle;
}
int ParOuImpar(int num1){
 if (num1 % 2 == 0){
    printf("O numero é par ");
 } else { 
    printf("O numero é impar ");
 } return 0;
}