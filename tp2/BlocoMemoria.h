#ifndef BlocoMemoria_h
#define BlocoMemoria_h
#include <stdbool.h>
#include "Endereco.h"
#include "BlocoMemoria.h"

typedef struct BlocoMemoria{

    int palavras[4];
	int endBloco;
	bool atualizado;
	int custo;
	int cacheHit; 
	int cacheMiss; 
	int timeStamp; 
	Caches cache1[25];
	Caches cache2[50];
	Caches cache3[100];

}BlocoMemoria;

typedef struct {
    BlocoMemoria* memoria;
    int tamanho;
	int endereco;
} RAM;

#endif //  BlocoMemoria_h