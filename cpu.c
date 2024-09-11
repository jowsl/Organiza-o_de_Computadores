#include "cpu.h"

BlocoMemoria* iniciarCache(int tamanho) {
    BlocoMemoria* umaCache = (BlocoMemoria*)malloc(tamanho * sizeof(BlocoMemoria));
    for (int i = 0; i < tamanho; i++) {
        umaCache[i].atualizado = false;
        umaCache[i].custo = 0;
        umaCache[i].cacheHit = 0;
        umaCache[i].cacheMiss = 0;
    }
    return umaCache;
}

void setPrograma(CPU *cpu, Instrucao *programaAux) {
    cpu->programa = programaAux;
}

BlocoMemoria* buscarNasMemorias(Endereco addr, BlocoMemoria *ram, BlocoMemoria *cache1, BlocoMemoria *cache2);

void iniciar(CPU *cpu, BlocoMemoria *ram, int tamanhoCache1, int tamanhoCache2) {
    cpu->cache1 = iniciarCache(tamanhoCache1);
    cpu->cache2 = iniciarCache(tamanhoCache2);
    cpu->opcode = 0;
    cpu->PC = 0;

    while (cpu->opcode != -1) {
        Instrucao inst = cpu->programa[cpu->PC];

        cpu->opcode = inst.opcode;

        if (cpu->opcode != -1) {
            cpu->registrador1 = buscarNasMemorias(inst.address1, ram, cpu->cache1, cpu->cache2);
            cpu->registrador2 = buscarNasMemorias(inst.address2, ram, cpu->cache1, cpu->cache2);
            cpu->registrador3 = buscarNasMemorias(inst.address3, ram, cpu->cache1, cpu->cache2);

            switch (cpu->registrador1->cacheHit) {
                case 1: cpu->hitC1++; break;
                case 2: cpu->missC1++; cpu->hitC2++; break;
                case 3: cpu->missC1++; cpu->missC2++; break;
            }

            switch (cpu->registrador2->cacheHit) {
                case 1: cpu->hitC1++; break;
                case 2: cpu->missC1++; cpu->hitC2++; break;
                case 3: cpu->missC1++; cpu->missC2++; break;
            }

            switch (cpu->registrador3->cacheHit) {
                case 1: cpu->hitC1++; break;
                case 2: cpu->missC1++; cpu->hitC2++; break;
                case 3: cpu->missC1++; cpu->missC2++; break;
            }

            switch (cpu->opcode) {
                case -1:
                    printf("Programa terminou!!\n");
                    break;
                case 0:
                    cpu->registrador3->palavras[inst.address3.endPalavra] = cpu->registrador1->palavras[inst.address1.endPalavra] + cpu->registrador2->palavras[inst.address2.endPalavra];
                    cpu->registrador3->atualizado = true;
                    cpu->custo += cpu->registrador1->custo + cpu->registrador2->custo + cpu->registrador3->custo;
                    printf("Inst sum -> RAM posicao %d com conteudo na cache 1 %d\n", inst.address3.endBloco, cpu->registrador3->palavras[inst.address3.endPalavra]);
                    break;
                case 1:
                    cpu->registrador3->palavras[inst.address3.endPalavra] = cpu->registrador1->palavras[inst.address1.endPalavra] - cpu->registrador2->palavras[inst.address2.endPalavra];
                    cpu->registrador3->atualizado = true;
                    cpu->custo += cpu->registrador1->custo + cpu->registrador2->custo + cpu->registrador3->custo;
                    printf("Inst sub -> RAM posicao %d com conteudo na cache 1 %d\n", inst.address3.endBloco, cpu->registrador3->palavras[inst.address3.endPalavra]);
                    break;
            }

            cpu->PC++;
        }
    }
}