#ifndef BlocoMemoria_h
#define BlocoMemoria_h
#include <stdbool.h>

#define TAM_C1 25
#define TAM_C2 50
#define TAM_C3 100
#define TAM_RAM 1000

typedef struct {
    struct BlocoMemoria* blocoNaMemoria;  // Bloco na cache ou na RAM
    int pos;                              // Posição para Memorias, opcional para RAM
} Memorias;

typedef struct BlocoMemoria{

    int palavras[4];
	int endBloco;
	bool atualizado;
	int custo;
	int cacheHit; 
	int cacheMiss; 
	int timeStamp; 
	Memorias cache1[TAM_C1];
	Memorias cache2[TAM_C2];
	Memorias cache3[TAM_C3];
	Memorias ram[TAM_RAM];

}BlocoMemoria;

typedef struct{
    int EndBloco;
    int EndPalavra;
}Endereco;


#endif //  BlocoMemoria_h