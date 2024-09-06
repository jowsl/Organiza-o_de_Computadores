// Jouberth Pereira, Enzo Bernardes, Cauã Guenrick
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#define MAX_TAM 1000
#define pi 3

// maquinaInterpretada
void fazInstrucao(int* umaInstrucao, int* RAM)
{
    int opcode = umaInstrucao[0];

    int val1, val2, val3;
    val1 = umaInstrucao[1];
    val2 = umaInstrucao[2];
    val3 = umaInstrucao[3];

    switch (opcode)
    {
    //Somar
    case 1://1 = endereço 2 = endereço 3 = endereço resultado
        int conteudoSomaRam1 = RAM[val1];
        int conteudoSomaRam2 = RAM[val2];	
        int soma = conteudoSomaRam1+conteudoSomaRam2;
        RAM[val3] = soma;
        
        printf("somando %d com %d e gerando %d, salvando no endereço %d\n", conteudoSomaRam1, conteudoSomaRam2, soma, val3);
        break;
    //Subtrair
    case 2://1 = endereço 2 = endereço 3 = endereço resultado
    
        int conteudoSubRam1 = RAM[val1];
        int conteudoSubRam2 = RAM[val2];	
        int subtrai = conteudoSubRam1-conteudoSubRam2;
        RAM[val3] = subtrai;
        
        printf("subtraindo %d de %d e gerando %d, salvando no endereço %d\n", conteudoSubRam2, conteudoSubRam1, subtrai, val3);
        break;
    //Store na RAM  
    case 3: // 1 = conteudo 2 = endereço 3 = inutilizado
        int content = val1;
        int end = val2;
        RAM[end]=content; 
        printf("[ %d, foi armazenado no endereço %d ]\n", content, end);

        break;
    //Load da RAM
    case 4: // 
        umaInstrucao[1]=RAM[val2];
        printf("[ %d foi trazido da RAM ]\n", umaInstrucao[1]);
        break;
    case -1:
        //halt
        printf("\nO programa será encerrado\n\n");
        break;
    default:
        printf("Opcode invalido");
        break;
    }
}


int main(){
    //vetor RAM sendo alocado como ponteiro
    int* RAM = malloc(MAX_TAM * sizeof(int));
    int** listaInstrucoes;

    listaInstrucoes = malloc(MAX_TAM * sizeof(int*));
    for (int i = 0; i < MAX_TAM; i++)
    {
        listaInstrucoes[i] = malloc(4 * sizeof(int));
    }

    //bota lixo na RAM 
    srand(time(NULL));
    for (int i = 0; i < MAX_TAM; i++)
    {
        RAM[i] = (rand() % 10) + 90;
        printf("RAM %d", RAM[i]);

    }



    //halt
    listaInstrucoes[0][0] = -1;
    fazInstrucao(listaInstrucoes[0], RAM);

    return 0;
}
