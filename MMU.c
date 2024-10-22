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
    case 4:
        for (int i = 0; i < TAM_RAM; i++)
        {
            if ( cpu->RAM.vetorDeBlocos[i].ultimaVezAcessado < cpu->RAM.vetorDeBlocos[maisVelho].ultimaVezAcessado 
             ||  cpu->RAM.vetorDeBlocos[i].endBloco == -1 )
            {
                maisVelho = i;
            }
        }
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

void buscarBinario(CPU *cpu ,int endBloco)
{
    FILE *arquivoBin = fopen("HD.bin", "rb");
    printf("Busca binaria\n");
    fseek(arquivoBin, endBloco * 6 * sizeof(int), SEEK_SET);
    printf("Endereço do bloco passado: %d\n", endBloco);
    int umaInstrucao[6];
    fread(umaInstrucao, sizeof(int), 6, arquivoBin);
    printf("Endereço lido do binario: %d\n", umaInstrucao[0]);
    cpu->HD.vetorDeBlocos[endBloco].endBloco = umaInstrucao[0];
    cpu->HD.vetorDeBlocos[endBloco].palavras[0] = umaInstrucao[1];
    cpu->HD.vetorDeBlocos[endBloco].palavras[1] = umaInstrucao[2];
    cpu->HD.vetorDeBlocos[endBloco].palavras[2] = umaInstrucao[3];
    cpu->HD.vetorDeBlocos[endBloco].palavras[3] = umaInstrucao[4];
    cpu->HD.vetorDeBlocos[endBloco].atualizado = umaInstrucao[5];
    
    fclose(arquivoBin);
}

void escreverBinario(CPU *cpu, int endBloco, int maisVelho)
{
    printf("Escrita binaria\n");
    
    FILE *arquivoBin = fopen("HD.bin", "rb+");
    
    fseek(arquivoBin, endBloco * 6 * sizeof(int), SEEK_SET);

    fwrite(&cpu->RAM.vetorDeBlocos[cpu->RAM.vetorDeBlocos[maisVelho].endBloco].endBloco, sizeof(int), 1, arquivoBin);
    fwrite(&cpu->RAM.vetorDeBlocos[cpu->RAM.vetorDeBlocos[maisVelho].endBloco].palavras, sizeof(int), 4, arquivoBin);

    
    fclose(arquivoBin);
}

BlocoDePalavras* movCache2Cache1(CPU *cpu, int endBloco, int maisVelho)
{
    printf("Movendo da posição %d da cache 2 para a posição %d da cache 1\n", endBloco, maisVelho);
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
    trocarBloco(&cpu->RAM, &cpu->cache3, endBloco, maisVelho);

    return &cpu->cache3.vetorDeBlocos[maisVelho];
}

BlocoDePalavras* movHDRam(CPU *cpu, int endBloco, int maisVelho)
{
    buscarBinario(cpu, endBloco);
    if (cpu->RAM.vetorDeBlocos[maisVelho].endBloco == -1)
    {
        cpu->RAM.vetorDeBlocos[maisVelho] = cpu->HD.vetorDeBlocos[endBloco];
    }else if (cpu->RAM.vetorDeBlocos[maisVelho].atualizado == 1)
    {
        //*Atualiza a HD
        printf("Atualizando a HD\n\n\n\n\n");
        cpu->RAM.vetorDeBlocos[maisVelho].atualizado = 0;
        escreverBinario(cpu, endBloco, maisVelho);
        cpu->RAM.vetorDeBlocos[maisVelho] = cpu->HD.vetorDeBlocos[endBloco];
    }else
    {
        cpu->RAM.vetorDeBlocos[maisVelho] = cpu->HD.vetorDeBlocos[endBloco];
    }

    return &cpu->RAM.vetorDeBlocos[maisVelho];
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

    printf("Buscando na cache 2\n\n\n\n\n");
    for (int i = 1; i < TAM_C2; i++)
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

    printf("Buscando na cache 3\n\n\n\n\n");
    for (int i = 0; i < TAM_C3; i++)
    {
        if (cpu->cache3.vetorDeBlocos[i].endBloco == end.endBloco)
        {
            cpu->cache3.cacheHit++;
            cpu->custo += TAM_C3;

            int maisVelho2 = verificarMaisVelho(2, cpu);

            movCache3Cache2(cpu, i, maisVelho2);

            int maisVelho1 = verificarMaisVelho(1, cpu);

            return movCache2Cache1(cpu, maisVelho2, maisVelho1);
        }
    }
    cpu->cache3.cacheMiss++;
    cpu->custo += TAM_C3;
    
    printf("Buscando na RAM\n\n\n\n\n");
    for (int i = 0; i < TAM_RAM; i++)
    {
        if (cpu->RAM.vetorDeBlocos[i].endBloco == end.endBloco)
        {
            cpu->RAM.cacheHit++;
            cpu->custo += TAM_RAM;
            
            int maisVelho3 = verificarMaisVelho(3, cpu);
            movRAMCache3(cpu, i, maisVelho3);

            int maisVelho2 = verificarMaisVelho(2, cpu);
            movCache3Cache2(cpu, i, maisVelho2);

            int maisVelho1 = verificarMaisVelho(1, cpu);   
            return movCache2Cache1(cpu, maisVelho2, maisVelho1);
        }
    }
    cpu->RAM.cacheMiss++;
    cpu->HD.cacheHit++;
    cpu->custo += TAM_RAM;
    cpu->custo += TAM_HD;

    printf("Buscando no HD endereço: %d \n\n\n\n\n", end.endBloco);

    int maisVelho4 = verificarMaisVelho(4, cpu);
    movHDRam(cpu, end.endBloco, maisVelho4);

    int maisVelho3 = verificarMaisVelho(3, cpu);
    movRAMCache3(cpu, maisVelho4, maisVelho3);

    int maisVelho2 = verificarMaisVelho(2, cpu);
    movCache3Cache2(cpu, maisVelho3, maisVelho2);

    int maisVelho1 = verificarMaisVelho(1, cpu);
    return movCache2Cache1(cpu, maisVelho2, maisVelho1);
}
