#include "cpu.h"
#include "MMU.h"

//* PRONTA
void iniciarCache(int tamanho, Memoria* umaCache) //talvez mudar para IniciarMemoria
{
    umaCache->vetorDeBlocos = (BlocoDePalavras*)malloc(tamanho * sizeof(BlocoDePalavras));
    umaCache->cacheHit = 0;
    umaCache->cacheMiss = 0;

    for (int i = 0; i < tamanho; i++)
    {
        umaCache->vetorDeBlocos[i].endBloco = -1;
        umaCache->vetorDeBlocos[i].atualizado = 0;
        umaCache->vetorDeBlocos[i].ultimaVezAcessado = 0;
    }

	return;
}

//* Binario vai ter ENDBLOCO, PALAVRA1, PALAVRA2, PALAVRA3, PALAVRA4, ATUALIZADO
void iniciarHD(int tamanho, Memoria* HD)
{
    HD->vetorDeBlocos = (BlocoDePalavras*)malloc(tamanho * sizeof(BlocoDePalavras));
    HD->cacheHit = 0;
    HD->cacheMiss = 0;
    FILE *arquivoBin = fopen("HD.bin", "wb");

    for (int i = 0; i < tamanho; i++)
    {
        fwrite(&i, sizeof(int), 1, arquivoBin); // Grava o endereço do bloco no binário
        for (int j = 0; j < TAM_BLOCO; j++)
        {
            int num = rand() % 101;
            fwrite(&num, sizeof(int), 1, arquivoBin);
        }
        int atualizado = 0;
        fwrite(&atualizado, sizeof(int), 1, arquivoBin); // flag de atualizado, 0 = não atualizado, 1 = atualizado
    }
    
    fclose(arquivoBin);
}


void tratadorDeInterrupcoes(CPU* cpu, Instrucao instrucao){
    
    FILE* arquivo1 = fopen("tratador_interrupcao.txt", "r");
    cpu->qtdInterrupcoes++;
    cpu->interrupcoesIgnoradas++;

    for (int i = 0; fscanf(arquivo1, "%d %d %d %d %d %d %d", &instrucao.opcode, &instrucao.endereco1.endBloco, &instrucao.endereco1.endPalavra, 
                    &instrucao.endereco2.endBloco, &instrucao.endereco2.endPalavra, &instrucao.endereco3.endBloco, &instrucao.endereco3.endPalavra) != EOF; i++)
    {
        if(instrucao.opcode == 2)
        {
            cpu->qtdInterrupcoes++;
            
            FILE* arquivo2 = fopen("tratador_interrupcao.txt", "r");
                
                for (int i = 0; fscanf(arquivo2, "%d %d %d %d %d %d %d", &instrucao.opcode, &instrucao.endereco1.endBloco, &instrucao.endereco1.endPalavra, 
                    &instrucao.endereco2.endBloco, &instrucao.endereco2.endPalavra, &instrucao.endereco3.endBloco, &instrucao.endereco3.endPalavra) != EOF; i++)
                {
                    if(instrucao.opcode == 2)
                    {
                        cpu->qtdInterrupcoes++;

                        FILE* arquivo3 = fopen("tratador_interrupcao.txt", "r");
                        
                        for (int i = 0; fscanf(arquivo3, "%d %d %d %d %d %d %d", &instrucao.opcode, &instrucao.endereco1.endBloco, &instrucao.endereco1.endPalavra, 
                            &instrucao.endereco2.endBloco, &instrucao.endereco2.endPalavra, &instrucao.endereco3.endBloco, &instrucao.endereco3.endPalavra) != EOF; i++)
                        {
                            if(instrucao.opcode == 2)
                            {
                                cpu->interrupcoesIgnoradas++;
                                break;
                            }
                            else
                            {
                                executarInstrucao(cpu, instrucao);
                            }
                        }
                        fclose(arquivo3);
                    }
                    else
                    {
                        executarInstrucao(cpu, instrucao);
                    }
                }
                fclose(arquivo2);
        } 
        else 
        {
            executarInstrucao(cpu, instrucao);
        }
    }
        fclose(arquivo1);
    
    return;
}


void iniciarCPU(CPU* umaCPU, int tamanhoCache1, int tamanhoCache2, int tamanhoCache3, int tamanhoRAM, int tamanhoHD)
{
    iniciarCache(tamanhoCache1, &umaCPU->cache1);
    iniciarCache(tamanhoCache2, &umaCPU->cache2);
    iniciarCache(tamanhoCache3, &umaCPU->cache3);
    iniciarCache(tamanhoRAM, &umaCPU->RAM);
    iniciarHD(tamanhoHD, &umaCPU->HD);

    umaCPU->custo = 0;
    umaCPU->tempoAtual = 0;
    umaCPU->qtdInterrupcoes = 0;
    umaCPU->interrupcoesIgnoradas = 0;


    return;
}

void executarInstrucao(CPU* umaCPU, Instrucao umaInstrucao)
{
    BlocoDePalavras* registrador1;
    BlocoDePalavras* registrador2;
    BlocoDePalavras* registrador3;

    registrador1 = buscarNasMemorias(umaCPU, umaInstrucao.endereco1);
    registrador2 = buscarNasMemorias(umaCPU, umaInstrucao.endereco2);
    registrador3 = buscarNasMemorias(umaCPU, umaInstrucao.endereco3);

    switch (umaInstrucao.opcode)
    {
    case 0:
        registrador3->palavras[umaInstrucao.endereco3.endPalavra % 4] = 
                registrador1->palavras[umaInstrucao.endereco1.endPalavra % 4] + registrador2->palavras[umaInstrucao.endereco2.endPalavra % 4];
        
        registrador3->atualizado = 1;
        printf("Resultado : %d \n", registrador3->palavras[umaInstrucao.endereco3.endPalavra % 4]);
        break;
    case 1:
        registrador3->palavras[umaInstrucao.endereco3.endPalavra % 4] = 
                registrador1->palavras[umaInstrucao.endereco1.endPalavra % 4] - registrador2->palavras[umaInstrucao.endereco2.endPalavra % 4];
        
        registrador3->atualizado = 1;
        printf("Resultado : %d \n", registrador3->palavras[umaInstrucao.endereco3.endPalavra % 4]);
        break;
    case 2:
        tratadorDeInterrupcoes(umaCPU, umaInstrucao);
        break;
    default:
        break;
    }
    return;
}

