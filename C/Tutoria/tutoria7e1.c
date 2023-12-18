// Jouberth Matheus Simão Pereira
#include <stdio.h>

int testePrimo(int);

int main(){
int intervalo1, intervalo2, numero, encontrado = 0;
printf("Digite os números do intervalo: ");
scanf("%d %d", &intervalo1, &intervalo2);
    for ( numero = intervalo1; numero <= intervalo2; numero++){
        if( testePrimo(numero) == 1){
            printf("O menor primo no intervalo é: %d\n", numero);
            encontrado = 1;
            break;
        }
    }
    if (!encontrado) 
    printf ("Nenhum numero primo foi encontrado!\n");

        return 0;
}

int testePrimo(int numero){
    if(numero <=1)
    return 0;
    if (numero % 2 ==0 && numero >2)
    return 0;
    for(int primo = 3; primo * primo <= numero; primo = primo +2){
        if (numero % primo == 0)
        return 0;
    }
    return 1;

}