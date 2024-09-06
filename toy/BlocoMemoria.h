#ifndef BlocoMemoria_h
#define BlocoMemoria_h
#include <stdbool.h>

typedef struct{

    int palavras[4];
	int endBloco = 0;
	bool atualizado = false;
	int custo = 0;
	int cacheHit = 0;
	int timeStamp;
	int cache1[16];
	int cache2[32];
	int cache3[64];

}BlocoMemoria;

typedef struct 
{
    BlocoMemoria* memoria;
    int tamanho;
} RAM;

#endif //  BlocoMemoria_h