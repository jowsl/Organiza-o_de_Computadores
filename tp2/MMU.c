#include "cpu.h"


int verificarMaisVelho(int nCache, CPU *cpu)
{
    int maisVelho = 0;

    switch (nCache)
    {
    case 1:
        for (int i = 0; i < TAM_C1; i++)
        {
            if ( cpu->cache1.vetorDeBlocos[i].ultimaVezAcessado < cpu->cache1.vetorDeBlocos[maisVelho].ultimaVezAcessado 
             ||  cpu->cache1.vetorDeBlocos[i].endBloco == -1 )
            {
                maisVelho = i;
            }
        }
        break;
    case 2:
        for (int i = 0; i < TAM_C2; i++)
        {
            if ( cpu->cache2.vetorDeBlocos[i].ultimaVezAcessado < cpu->cache2.vetorDeBlocos[maisVelho].ultimaVezAcessado 
             ||  cpu->cache2.vetorDeBlocos[i].endBloco == -1 )
            {
                maisVelho = i;
            }
        }
        break;
    case 3:
        for (int i = 0; i < TAM_C3; i++)
        {
            if ( cpu->cache3.vetorDeBlocos[i].ultimaVezAcessado < cpu->cache3.vetorDeBlocos[maisVelho].ultimaVezAcessado 
             ||  cpu->cache3.vetorDeBlocos[i].endBloco == -1 )
            {
                maisVelho = i;
            }
        }
        break;
    default:
        break;
    }

    return maisVelho;
}

void trocarBloco(Memoria* origem, Memoria* destino, int pos, int maisVelho)
{
    BlocoDePalavras aux = origem->vetorDeBlocos[pos];

    origem->vetorDeBlocos[pos] = destino->vetorDeBlocos[maisVelho];
    destino->vetorDeBlocos[maisVelho] = aux;
    
    return;
}

BlocoDePalavras* movCache2Cache1(CPU *cpu, int endBloco, int maisVelho)
{
    trocarBloco(&cpu->cache2, &cpu->cache1, endBloco, maisVelho);

    cpu->cache1.vetorDeBlocos[maisVelho].ultimaVezAcessado = ++cpu->tempoAtual;

    return &cpu->cache1.vetorDeBlocos[maisVelho];
}

BlocoDePalavras* movCache3Cache2(CPU *cpu, int endBloco, int maisVelho)
{
    trocarBloco(&cpu->cache3, &cpu->cache2, endBloco, maisVelho);

    return &cpu->cache2.vetorDeBlocos[maisVelho];
}

BlocoDePalavras* movRAMCache3(CPU *cpu, int endBloco, int maisVelho)
{
    // trocarBloco(&cpu->RAM, &cpu->cache3, endBloco, maisVelho);

    if (cpu->cache3.vetorDeBlocos[maisVelho].endBloco == -1)
    {
        cpu->cache3.vetorDeBlocos[maisVelho] = cpu->RAM.vetorDeBlocos[endBloco];;
    }else if (cpu->cache3.vetorDeBlocos[maisVelho].atualizado)
    {
        //*Atualiza a RAM
        cpu->cache3.vetorDeBlocos[maisVelho].atualizado = false;
        cpu->RAM.vetorDeBlocos[cpu->cache3.vetorDeBlocos[maisVelho].endBloco] = cpu->cache3.vetorDeBlocos[maisVelho];
        cpu->cache3.vetorDeBlocos[maisVelho] = cpu->RAM.vetorDeBlocos[endBloco];
    }else
    {
        cpu->cache3.vetorDeBlocos[maisVelho] = cpu->RAM.vetorDeBlocos[endBloco];
    }


    return &cpu->cache3.vetorDeBlocos[maisVelho];
}

BlocoDePalavras* buscarNasMemorias(CPU *cpu, Endereco end)
{
    for (int i = 0; i < TAM_C1; i++)
    {
        if (cpu->cache1.vetorDeBlocos[i].endBloco == end.endBloco)
        {
            cpu->cache1.cacheHit++;
            cpu->custo += TAM_C1;
            
            return &cpu->cache1.vetorDeBlocos[i];
        }
    }
    cpu->cache1.cacheMiss++;
    cpu->custo += TAM_C1;

    for (int i = 0; i < TAM_C2; i++)
    {
        if (cpu->cache2.vetorDeBlocos[i].endBloco == end.endBloco)
        {
            cpu->cache2.cacheHit++;
            cpu->custo += TAM_C2;
            int maisVelho = verificarMaisVelho(1, cpu);
            return movCache2Cache1(cpu, i, maisVelho);
        }
    }
    cpu->cache2.cacheMiss++;
    cpu->custo += TAM_C2;

    for (int i = 0; i < TAM_C3; i++)
    {
        if (cpu->cache3.vetorDeBlocos[i].endBloco == end.endBloco)
        {
            cpu->cache3.cacheHit++;
            cpu->custo += TAM_C3;

            int maisVelho = verificarMaisVelho(2, cpu);

            movCache3Cache2(cpu, i, maisVelho);

            maisVelho = verificarMaisVelho(1, cpu);

            return movCache2Cache1(cpu, i, maisVelho);
        }
    }
    cpu->cache3.cacheMiss++;
    cpu->custo += TAM_C3;
    cpu->custo += TAM_RAM;

    int maisVelho = verificarMaisVelho(3, cpu);
    movRAMCache3(cpu, end.endBloco, maisVelho);

    maisVelho = verificarMaisVelho(2, cpu);
    movCache3Cache2(cpu, end.endBloco, maisVelho);

    maisVelho = verificarMaisVelho(1, cpu);
    return movCache2Cache1(cpu, end.endBloco, maisVelho);
}
