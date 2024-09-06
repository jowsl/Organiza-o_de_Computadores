#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "Endereco.h"
#include "BlocoMemoria.h"


#define TAM_C1 25
#define TAM_C2 50
#define TAM_C3 100
#define TAM_RAM 1000
int timeStampContador = 0;


int timeStamp()
{ //atualizar o timeStamp
    return timeStampContador++;
}

// Função responsável por localizar um dado bloco nas memorias.
int buscarNasMemorias(Endereco* pEnd, RAM ram, BlocoMemoria* pBloco)
{

    // Pesquisa na cache1
    for (int i = 0; i < TAM_C1; i++)
    {

        if (pEnd->EndBloco == pBloco->cache1[i].blocoCache->endBloco)
        {

            pBloco->custo = TAM_C1; //Atribui um valor de custo de acesso dependendo de onde ele foi enontrado
            pBloco->cacheHit += 1; //Incrementa o contador de cache hit
            pBloco->timeStamp = timeStamp(); // Atualiza o timestamp

            return i;
        } else {
            pBloco->cacheMiss += 1; //Incrementa o contador de cache miss
            pBloco->custo = TAM_C1+TAM_C2; 
        }
    }
    // Pesquisa na cache2
    for (int i = 0; i < TAM_C2; i++)
    {

        if (pEnd->EndBloco == pBloco->cache2[i].blocoCache->endBloco)
        {
            pBloco->cacheHit += 1; 
            pBloco->cache2[i].pos = i;
            return pBloco;
            //aqui deve ter uma chamada pra função de mover para a cache1
        } else {
            pBloco->cacheMiss += 1; 
            pBloco->custo = TAM_C1+TAM_C2+TAM_C3;
        }
    
    }

        // Pesquisa na cache3
    for (int i = 0; i < 100; i++)
    {

        if (pEnd->EndBloco == pBloco->cache3[i].blocoCache->endBloco)
        {
            pBloco->cacheHit += 1; 
            pBloco->cache3[i].pos = i;
            return pBloco;
            //aqui deve ter uma chamada pra função de mover para a cache2 e depois para a cache1

        } else {
            pBloco->cacheMiss += 1; 
            pBloco->custo = TAM_C1+TAM_C2+TAM_C3+TAM_RAM; 
        }    
    }
    
        // Pesquisa na RAM
    for (int i = 0; i < ram.tamanho; i++)
    {

        if (pEnd->EndBloco == ram.memoria[i].endBloco)
        {
            ram.endereco = i;
            return ram.endereco;
            //aqui deve ter uma chamada pra função de mover para a cache3, cache2 e depois para a cache1
        } else {
            printf("Esse Bloco ja levou o caralho.\n");
        }    
    }
    return printf("Bloco não encontrado.\n");
}


int verificarMaisVelho(int TAM_C, BlocoMemoria* bloco) {
    int minimoI = 0;
    int minTimeStamp = bloco->cache1[0].blocoCache->timeStamp;

    for (int i = 1; i < TAM_C; i++) {
        if (bloco->cache1[i].blocoCache->timeStamp < minTimeStamp) {
            minimoI = i;
            minTimeStamp = bloco->cache1[i].blocoCache->timeStamp;
        }
    }
    return minimoI; //deveria retornar o indice do menor timeStamp
}


bool cacheCheio(int Tamanho, BlocoMemoria* cache)
{
    return (cache->cache1->tamAtual >= Tamanho);
}


int movCache2Cache1(BlocoMemoria* bloco1, Endereco* )
{
    int aux;
    int index;
    
    if(cacheCheio(TAM_C1, bloco1->cache1))
    {
        index = verificarMaisVelho(TAM_C1, bloco1);
        aux = 
        bloco2->cache2[index].blocoCache = bloco1->cache1[index].blocoCache;
    }
}


void movCache1Cache2(BlocoMemoria* bloco)
{ //mover o mais velho para a 2
    if(cacheCheio(TAM_C2, bloco->cache2))
    {
        verificarMaisVelho(TAM_C2, bloco);

    }
}


void movCache2Cache3(BlocoMemoria* bloco)
{
    if(cacheCheio(TAM_C3, bloco->cache3))
    {
        verificarMaisVelho(TAM_C3, bloco);
    }
}


void movCache3Cache2(BlocoMemoria* bloco)
{
    if(cacheCheio(TAM_C2, bloco->cache2))
    {
        verificarMaisVelho(TAM_C2, bloco);
    }    
}


void movCache3Ram(BlocoMemoria* bloco)
{
}


void movRamCache3(BlocoMemoria* bloco)
{
    if(cacheCheio(TAM_C3, bloco->cache3))
    {
        verificarMaisVelho(TAM_C3, bloco);
    }
}

	// static BlocoMemoria movCache2Cache1(int posicaoCache1, int posicaoCache2, BlocoMemoria[] cache1, BlocoMemoria[] cache2, int custo)
    // {
	// 	BlocoMemoria aux = cache1[posicaoCache1];	
	// 	cache1[posicaoCache1] = cache2[posicaoCache2];
	// 	cache2[posicaoCache2] = aux;
	// 	cache1[posicaoCache1].custo = custo;
	// 	return cache1[posicaoCache1]; 
	// }


int main(int argc, char* argv[])
{
    Endereco* endereco;
    BlocoMemoria* bloco;
    RAM ram;

    endereco->EndBloco = 1;
    int indice = buscarNasMemorias(endereco, ram, bloco);

    int buscou = buscarNasMemorias(endereco, ram, bloco);
    

    return 0;
}