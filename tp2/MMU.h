#ifndef MMU_H
#define MMU_H

#include "cpu.h"

int verificarMaisVelho(int nCache, CPU *cpu);

void trocarBloco(Memoria* origem, Memoria* destino, int pos, int maisVelho);

BlocoDePalavras *movCache2Cache1(CPU *cpu, int endBloco, int maisVelho);

BlocoDePalavras *movCache3Cache2(CPU *cpu, int endBloco, int maisVelho);

BlocoDePalavras *movRAMCache3(CPU *cpu, int endBloco, int maisVelho);

BlocoDePalavras *buscarNasMemorias(CPU *cpu, Endereco end);


#endif // MMU_H