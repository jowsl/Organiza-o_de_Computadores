#include <stdio.h>
#include <stdlib.h>

void liberarMemoria(int **m, int lin){
    for (int i = 0; i < lin; i++){
        free(m[i]);
    }
    free(m);
    
}

int **transpd(int **m, int lin, int col){ //função para criar a transposta
    int **trans = malloc(col * sizeof(int*)); // int* por estar criando um vetor de ponteiros
    for (int i = 0; i < col; i++){ 
        trans[i] = malloc(lin * sizeof(int)); // alocando memoria necessária
        for(int j = 0; j < lin; j++)
            trans[i][j] = m[j][i]; // preenchendo e trocando linhas por colunas.
    }
    return trans;
}
int main(){
    int l, c;
    printf("Digite as dimensões da matriz: ");
    scanf("%d %d", &l, &c);
// alocando memoria
    int **matriz = malloc(l * sizeof(int)); 
    for (int i = 0; i < l; i++)
        matriz[i] = malloc(c * sizeof(int)); 
// preenchendo a matriz 
    printf("Entre com os valores da matriz: ");
    for (int i = 0; i < l; i++){
        for (int j = 0; j < c; j++)
            scanf("%d", &matriz[i][j]);
    }
    printf("A matriz comum é: \n");
    for (int i = 0; i < l; i++){
        for (int j = 0; j < c; j++)
            printf("%d\t", matriz[i][j]);
        printf("\n");
    }
    printf("\n\n");
    printf("Agora vamos preparar a transposta dela.\n");
    int **transposta = transpd(matriz, l, c); 
    printf("...\n\n");
    for (int i = 0; i < l; i++){
        for (int j = 0; j < c; j++)
            printf("%d\t", transposta[i][j]);
        printf("\n");
    }
    
    printf("\n\n");
    liberarMemoria(matriz, l);
    liberarMemoria(transposta, c);

    return 0;
}