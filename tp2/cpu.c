#include "cpu.h"
#include "MMU.h"

//* PRONTA
void iniciarCache(int tamanho, Memoria* umaCache)
{
    umaCache->vetorDeBlocos = (BlocoDePalavras*)malloc(tamanho * sizeof(BlocoDePalavras));
    umaCache->cacheHit = 0;
    umaCache->cacheMiss = 0;

    for (int i = 0; i < tamanho; i++)
    {
        umaCache->vetorDeBlocos[i].endBloco = -1;
        umaCache->vetorDeBlocos[i].atualizado = false;
        umaCache->vetorDeBlocos[i].ultimaVezAcessado = 0;
    }


	return;
}

//* PRONTA
void iniciarRAM(int tamanho, Memoria* umaRAM)
{
    umaRAM->vetorDeBlocos = (BlocoDePalavras*)malloc(tamanho * sizeof(BlocoDePalavras));
    umaRAM->cacheHit = 0;
    umaRAM->cacheMiss = 0;

    for (int i = 0; i < tamanho; i++)
    {
        umaRAM->vetorDeBlocos[i].endBloco = i + 1;
        umaRAM->vetorDeBlocos[i].atualizado = false;
        umaRAM->vetorDeBlocos[i].ultimaVezAcessado = 0;
        for (int j = 0; j < TAM_BLOCO; j++)
        {
            umaRAM->vetorDeBlocos[i].palavras[j] = rand() % 101;
        }
    }

    return;
}

//* PRONTA
void iniciarCPU(CPU* umaCPU, int tamanhoCache1, int tamanhoCache2, int tamanhoCache3, int tamanhoRAM)
{
    iniciarCache(tamanhoCache1, &umaCPU->cache1);
    iniciarCache(tamanhoCache2, &umaCPU->cache2);
    iniciarCache(tamanhoCache3, &umaCPU->cache3);
    iniciarRAM(tamanhoRAM, &umaCPU->RAM);

    umaCPU->custo = 0;
    umaCPU->tempoAtual = 0;

    return;
}

void executarInstrucao(CPU* umaCPU, Instrucao umaInstrucao)
{
    BlocoDePalavras* registrador1;
    BlocoDePalavras* registrador2;
    BlocoDePalavras* registrador3;

    registrador1 = buscarNasMemorias(umaCPU, umaInstrucao.endereco1);
    registrador2 = buscarNasMemorias(umaCPU, umaInstrucao.endereco2);
    registrador3 = buscarNasMemorias(umaCPU, umaInstrucao.endereco3);

    switch (umaInstrucao.opcode)
    {
    case 0:
        registrador3->palavras[umaInstrucao.endereco3.endPalavra] = 
                registrador1->palavras[umaInstrucao.endereco1.endPalavra] + registrador2->palavras[umaInstrucao.endereco2.endPalavra];
        
        registrador3->atualizado = true;
        break;
    case 1:
        registrador3->palavras[umaInstrucao.endereco3.endPalavra] = 
                registrador1->palavras[umaInstrucao.endereco1.endPalavra] - registrador2->palavras[umaInstrucao.endereco2.endPalavra];
        
        registrador3->atualizado = true;
        break;
    default:
        break;
    }

    printf("%s %d com %d resultando em %d\n", umaInstrucao.opcode == 0 ? "Somando" : "Subtraindo", 
            registrador1->palavras[umaInstrucao.endereco1.endPalavra], 
            registrador2->palavras[umaInstrucao.endereco2.endPalavra], 
            registrador3->palavras[umaInstrucao.endereco3.endPalavra]);

    return;
}

