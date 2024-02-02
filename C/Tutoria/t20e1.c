 // Jouberth Matheus Simão Pereira nº23.2.4011
 #include <stdio.h>
 #include <stdlib.h>


typedef struct{
int qtd_ingredientes;
int **ingredientes; // a matriz q armazena os ingredientes
}Pocoes;

typedef struct{
char cor[10]; //Armazena a cor do livreto
int qtd_pocoes; //Armazena a quantidade de pocoes do livreto
Pocoes *pocao;
}Livreto;

void alocaMatriz(int linhas, int ***matriz); // aponta para o endereço para uma matriz
void alocaLivreto(Livreto *livreto, int qtd_pocoes);
void leLivreto(Livreto *livreto);
void desalocaMatriz(int linhas, int ***matriz);
void desalocaLivreto(Livreto *livreto);
 
 int main(){
    Pocoes *potions;
    Livreto *livreto;
    int nPotions;
    
    printf("Quantas poções vão ser armazenadas? ");
    scanf("%d", &nPotions);

    potions = malloc(nPotions * sizeof(int));
    alocaMatriz(nPotions, potions->ingredientes);

    for(int i = 0; i < nPotions; i++){
        printf("Entre com os ingredientes da poção %d.\nSão necessário no mínimo 2 ingredientes e no máximo 10.\n", i+1);
        scanf("%d", &potions[i].qtd_ingredientes);
        for (int j = 0; j < 2; j++){
            potions[i].ingredientes[i][j] = potions[i].qtd_ingredientes;
        }
    }








 
    free(potions);
    free(potions->ingredientes);
    return 0;
 }

 void imprimeLivreto(Livreto livreto) {
    printf("\n-------------------------\n");
    printf("Cor do Livreto: %s\n", livreto.cor);
    printf("Quantidade de Poções: %d\n", livreto.qtd_pocoes);
    printf("-------------------------\n");
    for (int i = 0; i < livreto.qtd_pocoes; i++) {
    printf("\nPoção %d:\n", i + 1);
    printf("Quantidade de Ingredientes: %d\n", livreto.pocao[i].qtd_ingredientes);
    printf("%-20s%-10s\n", "Ingrediente", "Quantidade");
    for (int j = 0; j < livreto.pocao[i].qtd_ingredientes; j++) {

    printf("%-20s%-10d\n", (char *)&livreto.pocao[i].ingredientes[j][0],

    livreto.pocao[i].ingredientes[j][1]);
    }
    printf("-------------------------\n");
    }
}

void alocaMatriz(int linhas, int ***matriz){ // aponta para o endereço para uma matriz
    int **matriz = malloc (linhas * sizeof(int*));
    for (int i = 0; i < linhas; i++){
        matriz[i] = malloc(2 * sizeof(int));
    }
    return matriz;
}

void alocaLivreto(Livreto *livreto, int qtd_pocoes){

    
}

