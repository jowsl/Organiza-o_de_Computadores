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
        bloco->cache1[i].blocoNaMemoria = NULL;
    }

    for (int i = 0; i < TAM_C2; i++)
    {
        bloco->cache2[i].blocoNaMemoria = NULL;
    }

    for (int i = 0; i < TAM_C3; i++)
    {
        bloco->cache3[i].blocoNaMemoria = NULL;
    }
}


// Função responsável por localizar um dado bloco nas memorias.
int buscarNasMemorias(Endereco* pEnd, BlocoMemoria* pBloco)
{
    // Pesquisa na cache1
    for (int i = 0; i < TAM_C1; i++)
    {
        if (pEnd->EndBloco == pBloco->cache1[i].blocoNaMemoria->endBloco)
        {

            pBloco->cacheHit += 1; //Incrementa o contador de cache hit
            pBloco->timeStamp = timeStamp(); // Atualiza o timestamp
            printf("Bloco encontrado na cache1.\n");
            return pBloco->endBloco;
        } else {
            pBloco->cacheMiss += 1;
            break; //Incrementa o contador de cache miss
        }
    }
    // Pesquisa na cache2
    for (int i = 0; i < TAM_C2; i++)
    {

        if (pEnd->EndBloco == pBloco->cache2[i].blocoNaMemoria->endBloco)
        {
            pBloco->cacheHit += 1; 
            // pBloco->cache2[i].pos = i;
            printf("Bloco encontrado na cache2.\n");
            return pBloco->endBloco;
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

        if (pEnd->EndBloco == pBloco->cache3[i].blocoNaMemoria->endBloco)
        {
            pBloco->cacheHit += 1; 
            // pBloco->cache3[i].pos = i;
            printf("Bloco encontrado na cache3.\n");
            return pBloco->endBloco;
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

        if (pEnd->EndBloco == pBloco->ram[i].blocoNaMemoria->endBloco)
        {
            pBloco->ram[i].blocoNaMemoria->endBloco = i;
            printf("Bloco encontrado na RAM.\n");
            return pBloco->endBloco;
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
    int minTimeStamp = bloco->cache1[0].blocoNaMemoria->timeStamp;

    switch (TAM_C)
    {
    case TAM_C1:
        for (int i = 1; i < TAM_C; i++) {

            if(bloco->cache1[i].blocoNaMemoria == NULL)
            {
                return i;
            }

            else if (bloco->cache1[i].blocoNaMemoria->timeStamp < minTimeStamp) {
                minimoI = i;
                minTimeStamp = bloco->cache1[i].blocoNaMemoria->timeStamp;
            }
        }
        return minimoI; //deveria retornar o indice do menor timeStamp
        break;
    case TAM_C2:
        for (int i = 1; i < TAM_C; i++) {

            if(bloco->cache2[i].blocoNaMemoria == NULL)
            {
                return i;
            }

            else if (bloco->cache2[i].blocoNaMemoria->timeStamp < minTimeStamp){
                minimoI = i;
                minTimeStamp = bloco->cache2[i].blocoNaMemoria->timeStamp;
            }
        }
        return minimoI; //deveria retornar o indice do menor timeStamp
        break;
    case TAM_C3:
        for (int i = 1; i < TAM_C; i++) {

            if(bloco->cache3[i].blocoNaMemoria == NULL)
            {
                return i;
            }

            else if (bloco->cache3[i].blocoNaMemoria->timeStamp < minTimeStamp) {
                minimoI = i;
                minTimeStamp = bloco->cache3[i].blocoNaMemoria->timeStamp;
            }
        }
        return minimoI; //deveria retornar o indice do menor timeStamp
        break;
    default:
        break;
    }
    return 0; 
}

//função que efetua troca de um item de uma cache pelo outro usando um auxiliar
//*
BlocoMemoria* trocarBlocos(int indice1, int indice2, Memorias* destino , Memorias* origem)
{
     Memorias aux;  

    aux = destino[indice1];
    destino[indice1] = origem[indice2];
    origem[indice2] = aux;

    return destino[indice1].blocoNaMemoria;  // Retornando o ponteiro para o bloco no destino
}


bool cacheCheio(int tamanho, Memorias cache[]) {
    for (int i = 0; i < tamanho; i++) {
        if (cache[i].blocoNaMemoria == NULL) {
            cache->pos = i;
            return false;
        }
    }
    return true;
}


bool movCache2Cache1(BlocoMemoria* bloco1, BlocoMemoria* bloco2)
{
    int index1, index2;
    
    if(cacheCheio(TAM_C1, bloco1->cache1))
    {
        index1 = verificarMaisVelho(TAM_C1, bloco1);
        index2 = verificarMaisVelho(TAM_C2, bloco2);
        bloco1 = trocarBlocos(index1, index2, bloco1->cache2, bloco2->cache1);
        bloco1->timeStamp = timeStamp(); //atualiza o timeStamp do novo bloco da cache1
        bloco1->atualizado = true; //atualizado? true

    } else {
        bloco1->cache1[bloco1->cache1->pos].blocoNaMemoria = bloco2->cache2->blocoNaMemoria; //insere o bloco da cache2 na cache1 onde tinha um NULL
        bloco1->timeStamp = timeStamp(); //atualiza o timeStamp do novo bloco da cache1
        bloco1->atualizado = true;

    }
    return true;
}

bool movCache3Cache2(BlocoMemoria* bloco1, BlocoMemoria* bloco2)
{
    int index1, index2;
    
    if(cacheCheio(TAM_C2, bloco1->cache2))
    {
        index1 = verificarMaisVelho(TAM_C2, bloco1);
        index2 = verificarMaisVelho(TAM_C3, bloco2);
        bloco1 = trocarBlocos(index1, index2, bloco1, bloco2);
        bloco1->timeStamp = timeStamp(); 
    } else {
        bloco1->cache2[bloco1->cache2->pos].blocoNaMemoria = bloco2->cache3->blocoNaMemoria; 
        bloco1->timeStamp = timeStamp(); 
    }
}

//*detalhe, Ram n faz a troca, sempre tem que ter uma copia do bloco la.
void movRamCache3(BlocoMemoria* bloco1, Memorias* ram)
{
    int index1, index2=0;

    if(cacheCheio(TAM_C3, bloco1->cache3))
    {
        index1 = verificarMaisVelho(TAM_C3, bloco1);
        bloco1->cache3[index1].blocoNaMemoria = ram[index2].blocoNaMemoria; //??
        //index2 = verificarMaisVelho(TAM_RAM, bloco2); ????
        bloco1->timeStamp = timeStamp(); 
    } else { 
        bloco1->cache3[bloco1->cache3->pos].blocoNaMemoria = ram->blocoNaMemoria; 
        bloco1->timeStamp = timeStamp(); 
    }
}


int main(int argc, char* argv[])
{
    Endereco* endereco;
    BlocoMemoria* bloco;
    Memorias ram;

    // inicializarMemorias(bloco);
    verificarMaisVelho(TAM_C1, bloco);


    

    return 0;
}