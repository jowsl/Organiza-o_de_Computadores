#include "BlocoMemoria.h"
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#define MAX_TAM 1000


BlocoMemoria* criaRAM_vazia(int tam)
{
    BlocoMemoria* memoria = (BlocoMemoria*) malloc(tam * sizeof(BlocoMemoria));
    
    for (int i = 0; i < tam; i++){
        memoria[i].endBloco = 1;
        
        for (int j = 0; j < 4; j++){
            memoria[i].palavras[j] = 0;
        }
    
    }
    return memoria;
}

BlocoMemoria* criaRAM_aleatoria(int tam){
    
    srand(time(NULL));
    BlocoMemoria* memoria = (BlocoMemoria*) malloc(tam * sizeof(BlocoMemoria));
    
    for (int i = 0; i < tam; i++){
       
        memoria[i].endBloco = 1;
        
        for (int j = 0; j < 4; j++){
            
            memoria[i].palavras[j] = rand() % 99 + 1;
        }
    
    }
    return memoria;
}

void setDado(int endereco, BlocoMemoria conteudo, BlocoMemoria* memoria) {
    memoria[endereco] = conteudo;
}

BlocoMemoria getDado(int endereco, BlocoMemoria* memoria) {
		return memoria[endereco];
}

void imprimir(BlocoMemoria* memoria, int tamanho) {
    printf("Conteudo da RAM\n");
    for (int i = 0; i < tamanho; i++) {
        imprimirUmBloco(memoria[i]);
    }
    
    printf("\n");
}

void imprimirUmBloco(BlocoMemoria bloco) {
    for (int i = 0; i < 4; i++) {
        printf("%d,", bloco.palavras[i]);
    }
}



