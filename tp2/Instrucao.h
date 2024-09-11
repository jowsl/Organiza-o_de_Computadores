#ifndef Instrucao_h
#define Instrucao_h
#include "BlocoMemoria.h"

typedef struct{

    Endereco address1;
    Endereco address2;
    Endereco address3;
    int opcode;

}Instrucao;


#endif //  Instrucao_h