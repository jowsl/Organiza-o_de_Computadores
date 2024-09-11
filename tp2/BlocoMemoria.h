#ifndef BlocoMemoria_h
#define BlocoMemoria_h
#include <stdbool.h>

#define TAM_C1 32
#define TAM_C2 64
#define TAM_C3 128
#define TAM_RAM 1000
#define TAM_BLOCO 4

typedef struct
{
    int endBloco;
    int endPalavra;
}Endereco;

typedef struct
{
	int opcode;
	Endereco endereco1;
	Endereco endereco2;
	Endereco endereco3;

}Instrucao;


typedef struct BlocoDePalavras{

	int palavras[4];

	int ultimaVezAcessado;
	bool atualizado;

	int endBloco;

}BlocoDePalavras;

typedef struct Memoria
{
	BlocoDePalavras* vetorDeBlocos;
	int cacheHit;
	int cacheMiss;
}Memoria;


#endif //  BlocoMemoria_h