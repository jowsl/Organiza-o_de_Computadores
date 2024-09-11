#ifndef CPU_H
#define CPU_H

#include <stdio.h>
#include <stdlib.h>
#include "BlocoMemoria.h"
#include "Instrucao.h"

typedef struct {
    BlocoMemoria *registrador1;
    BlocoMemoria *registrador2;
    BlocoMemoria *registrador3;
    int PC;
    Instrucao *programa;
    int opcode;
    int custo;
    int missC1;
    int hitC1;
    int missC2;
    int hitC2;
    BlocoMemoria *cache1;
    BlocoMemoria *cache2;
} CPU;

#endif // CPU_H
