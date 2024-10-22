#include "cpu.h"
#include <stdio.h>
//* Os defines dos tamanhos estao no BlocoMemoria.h

void liberarMemoria(Memoria* memoria)
{
    if (memoria->vetorDeBlocos != NULL) {
        free(memoria->vetorDeBlocos);
        memoria->vetorDeBlocos = NULL; 
    }
}

void rodaProgramas(CPU* cpu)
{
    Instrucao instrucao;
    FILE *arquivoTxt;
    
    arquivoTxt = fopen("instructions.txt", "r");

    if (arquivoTxt == NULL) 
    {
        printf("Erro ao abrir o arquivo texto\n");
        return;
    }

    for (int i = 0; fscanf(arquivoTxt, "%d %d %d %d %d %d %d", &instrucao.opcode, &instrucao.endereco1.endBloco, &instrucao.endereco1.endPalavra, 
                    &instrucao.endereco2.endBloco, &instrucao.endereco2.endPalavra, &instrucao.endereco3.endBloco, &instrucao.endereco3.endPalavra) != EOF; i++)
    {
        printf("Instrução numero %d: ", i);
        executarInstrucao(cpu, instrucao);
    }

    fclose(arquivoTxt);
    return;

}

int main (int argc, char *argv[]) 
{
    CPU cpu;
    iniciarCPU(&cpu, TAM_C1, TAM_C2, TAM_C3, TAM_RAM, TAM_HD);

    rodaProgramas(&cpu);

    printf("\nCusto total: %d\n\n", cpu.custo);

    // Imprimir relatório de hits e misses de cada cache
    printf("Relatório de Hits e Misses:\n");
    printf("Cache 1 - Hits: %d, Misses: %d\n", cpu.cache1.cacheHit, cpu.cache1.cacheMiss);
    printf("Cache 2 - Hits: %d, Misses: %d\n", cpu.cache2.cacheHit, cpu.cache2.cacheMiss);
    printf("Cache 3 - Hits: %d, Misses: %d\n", cpu.cache3.cacheHit, cpu.cache3.cacheMiss);
    printf("Memoria RAM - Hits: %d, Misses: %d\n", cpu.RAM.cacheHit, cpu.RAM.cacheMiss);
    printf("Memoria HD - Hits: %d, Misses: %d\n", cpu.HD.cacheHit, cpu.HD.cacheMiss);

    printf("\nQuantidade de interrupções tratadas: %d\n", cpu.qtdInterrupcoes);
    printf("\nQuantidade de interrupções ignoradas: %d\n", cpu.interrupcoesIgnoradas);

    liberarMemoria(&cpu.cache1);
    liberarMemoria(&cpu.cache2);
    liberarMemoria(&cpu.cache3);
    liberarMemoria(&cpu.RAM);
    liberarMemoria(&cpu.HD);

    return 0;
}