#include "BlocoMemoria.h"
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#define TAM_RAM 1000


// BlocoMemoria* criaRAM_vazia()
// {
//     BlocoMemoria* memoria = (BlocoMemoria*) malloc(TAM_RAM * sizeof(BlocoMemoria));
    
//     for (int i = 0; i < TAM_RAM; i++){
//         memoria[i].endBloco = 1;
        
//         for (int j = 0; j < 4; j++){
//             memoria[i].palavras[j] = 0;
//         }
//     }
//     return memoria;
// }

void inicializarRAM(BlocoMemoria* pBloco) 
{
    for (int i = 0; i < TAM_RAM; i++) {
        pBloco->ram[i].blocoNaMemoria->endBloco = i+1;  // Inicializa o endBloco, por exemplo
        pBloco->ram[i].blocoNaMemoria->atualizado = false;  
        pBloco->ram[i].blocoNaMemoria->custo = 0;
        for (int j = 0; j < 4; j++){
            pBloco->palavras[j] = 0;
        }
    }
}



void setDado(int endereco, BlocoMemoria conteudo, BlocoMemoria* memoria) {
    memoria[endereco] = conteudo;
}

BlocoMemoria getDado(int endereco, BlocoMemoria* memoria) {
		return memoria[endereco];
}

void imprimir(BlocoMemoria* memoria) {
    printf("Conteudo da RAM\n");
    for (int i = 0; i < TAM_RAM; i++) {
        imprimirUmBloco(memoria[i]);
    }
    
    printf("\n");
}

void imprimirUmBloco(BlocoMemoria bloco) {
    for (int i = 0; i < 4; i++) {
        printf("%d,", bloco.palavras[i]);
    }
}



