#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "BlocoMemoria.h"


#define TAM_C1 25
#define TAM_C2 50
#define TAM_C3 100
#define TAM_RAM 1000
int timeStampContador = 0;

/*
OPCODE(0 e 1):ENDBLOCO:ENDPALAVRA(sempre de 0 1 2 3):ENDBLOCO:ENDPALAVRA:ENDBLOCO:ENDPALAVRA
*/

int timeStamp()
{ //atualizar o timeStamp
    return timeStampContador++;
}

//inicializar caches
void inicializarCaches(BlocoMemoria* bloco)
{
    for (int i = 0; i < TAM_C1; i++)
    {
        bloco->cache1[i].blocoNaCache = NULL;
    }

    for (int i = 0; i < TAM_C2; i++)
    {
        bloco->cache2[i].blocoNaCache = NULL;
    }

    for (int i = 0; i < TAM_C3; i++)
    {
        bloco->cache3[i].blocoNaCache = NULL;
    }
}



// Função responsável por localizar um dado bloco nas memorias.
int buscarNasMemorias(Endereco* pEnd, BlocoMemoria* pBloco, Caches* cache, int TAM)
{
    // Pesquisa na cache1
    for (int i = 0; i < TAM_C1; i++)
    {
        if (pEnd->EndBloco == pBloco->cache1[i].blocoNaCache->endBloco)
        {

            pBloco->cacheHit += 1; //Incrementa o contador de cache hit
            pBloco->timeStamp = timeStamp(); // Atualiza o timestamp
            printf("Bloco encontrado na cache1.\n");
            return i;
        } else {
            pBloco->cacheMiss += 1;
            break; //Incrementa o contador de cache miss
        }
    }
    // Pesquisa na cache2
    for (int i = 0; i < TAM_C2; i++)
    {

        if (pEnd->EndBloco == pBloco->cache2[i].blocoNaCache->endBloco)
        {
            pBloco->cacheHit += 1; 
            pBloco->cache2[i].pos = i;
            printf("Bloco encontrado na cache2.\n");
            return i;
            //aqui deve ter uma chamada pra função de mover para a cache1
        } else {
            pBloco->cacheMiss += 1; 
            pBloco->custo = TAM_C1+TAM_C2+TAM_C3;
            break;
        }
    
    }

        // Pesquisa na cache3
    for (int i = 0; i < 100; i++)
    {

        if (pEnd->EndBloco == pBloco->cache3[i].blocoNaCache->endBloco)
        {
            pBloco->cacheHit += 1; 
            pBloco->cache3[i].pos = i;
            printf("Bloco encontrado na cache3.\n");
            return i;
            //aqui deve ter uma chamada pra função de mover para a cache2 e depois para a cache1

        } else {
            pBloco->cacheMiss += 1; 
            pBloco->custo = TAM_C1+TAM_C2+TAM_C3+TAM_RAM;
            break; 
        }    
    }
    
        // Pesquisa na RAM
    for (int i = 0; i < TAM_RAM; i++)
    {

        if (pEnd->EndBloco == pBloco->ram[i].blocoNaRam->endBloco)
        {
            pBloco->ram[i].blocoNaRam->endBloco = i;
            printf("Bloco encontrado na RAM.\n");
            return i;
            //aqui deve ter uma chamada pra função de mover para a cache3, cache2 e depois para a cache1
        } else {
            printf("Esse Bloco ja levou o caralho.\n");
            break;
        }    
    }
    return printf("Bloco não encontrado.\n");
}


int verificarMaisVelho(int TAM_C, BlocoMemoria* bloco) {
    int minimoI = 0;
    int minTimeStamp = bloco->cache1[0].blocoNaCache->timeStamp;

    for (int i = 1; i < TAM_C; i++) {
        if (bloco->cache1[i].blocoNaCache->timeStamp < minTimeStamp) {
            minimoI = i;
            minTimeStamp = bloco->cache1[i].blocoNaCache->timeStamp;
        }
    }
    return minimoI; //deveria retornar o indice do menor timeStamp
}

//cacheCheio(25, bloco->cache1) cacheCheio(50, bloco->cache2) cacheCheio(100, bloco->cache3)
bool cacheCheio(int tamanho, Caches cache[]) {
    for (int i = 0; i < tamanho; i++) {
        if (cache[i].blocoNaCache == NULL) {
            return false;
        }
    }
    return true;
}


int movCache2Cache1(BlocoMemoria* bloco1, Endereco* )
{
    int aux;
    int index;
    
    if(cacheCheio(TAM_C1, bloco1->cache1))
    {
        index = verificarMaisVelho(TAM_C1, bloco1);
        aux = 
        bloco2->cache2[index].blocoNaCache = bloco1->cache1[index].blocoNaCache;
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

    inicializarCaches(bloco);

    endereco->EndBloco = 122;
    int indice = 

    

    return 0;
}