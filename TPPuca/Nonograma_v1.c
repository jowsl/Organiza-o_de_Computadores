#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

// typedef struct{
//     int x;
//     int y;
// } coordenadas;

// Protótipos (descrições na implementação se necessário.)
int** criaMatriz(int m, int n);
int Check(int positivo);
void liberaMatriz(int** matriz, int m);
void MatrizVazia(int** matriz, int m, int n);



int main(int argc, char *argv[]){
    if (argc < 2){ //argv[0] deve ser nome do programa e argv[1] deve ser o nome do arquivo.
        printf("\n\tErro!\n\tVerifique se foi digitado corretamente o nome do arquivo e executável do programa.\n\n");
        return 0;
    }

    int **yCab, **xCab, **spaceCab;
    int lin, col;
    char *Arquivotxt = argv[1];
   // coordenadas x, y;

    FILE *arquivo = fopen(Arquivotxt, "r+");
    if (arquivo == NULL){
        printf("Não foi possível abrir seu arquivo. Tente novamente!");
        return 0;
    }
    
    fscanf(arquivo, "%d %d", &lin, &col);
    if( lin > 26 || col > 26){
        printf("\nErro! \nAs dimensões máximas são 26x26! Verifique o arquivo e tente novamente.\n\n");
        return 0;
    }

    int varLinAux, varColAux; // variáveis para armazenas valores arredondados da divisão quando lin/col forem impares.
    varLinAux = ceil(lin/2.0); // evita arredondar pra baixo e causar desaranjo no print da matrizVazia.
    varColAux = ceil(col/2.0);
 
    spaceCab = criaMatriz(varLinAux+1, varColAux+1);
    xCab = criaMatriz(lin, col); // aloca com 1 linha a mais p/ o abc, e com 13 colunas para ficar no canto superior esquerdo da tabela se precisar.
    yCab = criaMatriz(lin, col); // aloca com 1 coluna p/ o abc
    
    for (int i = 0; i < varLinAux+1; i++){
        for (int j = 0; j < varColAux+1; j++){
            spaceCab[i][j] = ' ';
            }
        }
    
    MatrizVazia(spaceCab, varLinAux+1, varColAux+1);

    //leitura e prints do xCab
    for (int i = 0; i < varLinAux+1; i++)
    {
        for (int j = 0; j < varColAux+1; j++)
        {
            if(i == varLinAux){
                xCab[i][j] = 65+j;
                printf("%2c ", xCab[i][j]);
            } else {    
                fscanf(arquivo, "%d", &xCab[i][j]);
                printf("%2d ", xCab[i][j]);
            }
        }
        printf("\n");
    }
    
    // implementar uma forma da matriz vazia ficar dentro de uma das duas matrizes.



    fclose(arquivo);
    
    liberaMatriz(xCab, lin);
    liberaMatriz(yCab, lin);
    liberaMatriz(spaceCab, (lin/2)+1);
    
    free(spaceCab);
    free(xCab);
    free(yCab);
    return 0;
}



// aloca dinamicamente uma matriz
int** criaMatriz(int m, int n){ 
    int **matriz = malloc (m * sizeof(int*));
    for (int i = 0; i < m; i++){
        matriz[i] = malloc(n * sizeof(int));
        }
    return matriz;
}

//checa se é negativo.
int Check(int positivo){ 
    if(positivo < 0)
        return 1;
    else
        return 0;
}

void liberaMatriz(int** matriz, int m){
    for (int i = 0; i < m; i++){
        free(matriz[i]);
    }
}

void MatrizVazia(int** matriz, int m, int n){
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            putchar(matriz[i][j]);
            putchar(' ');
        }
        printf("\n");
    }
}
            // fscanf(arquivo, "%d", &yCab[i][j]);
            // Check(yCab[i][j]);
            // if (1){
            //     printf("Erro, o Nonograma deve conter apenas números positivos inteiros.\nVerifique o arquivo e tente novamente!");
            //     return 0;