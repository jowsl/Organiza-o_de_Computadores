#ifndef BlocoMemoria_h
#define BlocoMemoria_h
#include <stdbool.h>

#define TAM_C1 25
#define TAM_C2 50
#define TAM_C3 100
#define TAM_RAM 1000

typedef struct BlocoMemoria{

    int palavras[4];
	int endBloco;
	bool atualizado;
	int custo;
	int cacheHit; 
	int cacheMiss; 
	int timeStamp; 
	Caches cache1[TAM_C1];
	Caches cache2[TAM_C2];
	Caches cache3[TAM_C3];
	RAM ram[TAM_RAM];

}BlocoMemoria;

typedef struct {
    BlocoMemoria* blocoNaRam;
} RAM;

typedef struct{
    int EndBloco;
    int EndPalavra;
}Endereco;

typedef struct{
    BlocoMemoria* blocoNaCache;
    int pos;
}Caches;

#endif //  BlocoMemoria_h