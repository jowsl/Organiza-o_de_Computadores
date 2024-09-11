#include "cpu.h"
#include <stdio.h>

//* Os defines dos tamanhos estao no BlocoMemoria.h

void rodaProgramas(CPU* cpu)
{
    Instrucao instrucao;

    //abrir o arquivo instrucao.h
    FILE* arquivo = fopen("instructions.txt", "r");

    if (arquivo == NULL)
    {
        printf("Erro ao abrir o arquivo\n");
        return;
    }

    while (fscanf(arquivo, "%d %d %d %d %d %d %d", &instrucao.opcode, &instrucao.endereco1.endBloco, &instrucao.endereco1.endPalavra, 
    &instrucao.endereco2.endBloco, &instrucao.endereco2.endPalavra, &instrucao.endereco3.endBloco, &instrucao.endereco3.endPalavra) != EOF)
    {
        executarInstrucao(cpu, instrucao);
    }

    fclose(arquivo);

    return;

}


int main (int argc, char *argv[]) 
{
    CPU cpu;
    iniciarCPU(&cpu, TAM_C1, TAM_C2, TAM_C3, TAM_RAM);

    rodaProgramas(&cpu);


    // Imprimir relatório de hits e misses de cada cache
    printf("Relatório de Hits e Misses:\n");
    printf("Cache 1 - Hits: %d, Misses: %d\n", cpu.cache1.cacheHit, cpu.cache1.cacheMiss);
    printf("Cache 2 - Hits: %d, Misses: %d\n", cpu.cache2.cacheHit, cpu.cache2.cacheMiss);
    printf("Cache 3 - Hits: %d, Misses: %d\n", cpu.cache3.cacheHit, cpu.cache3.cacheMiss);


    return 0;
}