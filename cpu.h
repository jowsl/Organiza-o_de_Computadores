#ifndef CPU_H
#define CPU_H

#include <stdio.h>
#include <stdlib.h>
#include "BlocoMemoria.h"

typedef struct cpu {

    int custo;

    int tempoAtual;

    Memoria cache1;
    Memoria cache2;
    Memoria cache3;
    Memoria RAM;
    Memoria HD;

	int qtdInterrupcoes;
    int interrupcoesIgnoradas;

} CPU;

void executarInstrucao(CPU* umaCPU, Instrucao umaInstrucao);

void iniciarCPU(CPU* umaCPU, int tamanhoCache1, int tamanhoCache2, int tamanhoCache3, int tamanhoRAM, int tamanhoHD);

void iniciarHD(int tamanho, Memoria* umHD);

void iniciarCache(int tamanho, Memoria* umaCache);

#endif // CPU_H