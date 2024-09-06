#ifndef Endereco_h
#define Endereco_h
//#include "BlocoMemoria.h"


typedef struct BlocoMemoria BlocoMemoria;

typedef struct{
    int EndBloco;
    int EndPalavra;
}Endereco;

typedef struct{
    BlocoMemoria* blocoCache;
    int pos;
    int tamAtual;
    int timeStampContador;
}Caches;



#endif //  Endereco_h