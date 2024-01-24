// Jouberth Matheus Simão Pereira nº23.2.4011
#include <stdio.h>
#include <stdlib.h>


float** criaMatriz(int m, int n);
void liberaMatriz(float** matriz, int m);

int main(){
    int d, a;
    float **mat;
    float somatorio=0, *media, maiorAlt=0;

    printf("Digite o número de delegações: ");
    scanf("%d", &d); 
    printf("Digite o número de atletas: ");
    scanf("%d", &a); 

    mat = criaMatriz(d, a);
    media = malloc(d * sizeof(float));
    
    printf("\nDigite as alturas\n");
        for (int i = 0; i < d; i++){
                printf("\nDelegação %d:\n", i+1);
                somatorio = 0;
            for (int j = 0; j < a; j++){
                printf("Atleta %d: ", j+1);
                scanf("%f", &mat[i][j]);
                if(mat[i][j] > maiorAlt)
                    maiorAlt = mat[i][j];
                somatorio = somatorio + mat[i][j];
            }
            media[i] = somatorio / a;
        }
        

    printf("\nMédia das alturas\n");
    for (int i = 0; i < d; i++)
    {
        printf("Delegação %d: %.2f\n", i+1, media[i]);
    }
    printf("\nMaior altura: %.2f", maiorAlt);

    

    liberaMatriz(mat, d);
    free(mat);
    free(media);

    return 0;
}

    float** criaMatriz(int m, int n){
    float **matriz = malloc (m * sizeof(float*));
    for (int i = 0; i < m; i++){
        matriz[i] = malloc(n * sizeof(float));
        }
    return matriz;
}

void liberaMatriz(float** matriz, int m){
    for (int i = 0; i < m; i++){
        free(matriz[i]);
    }   
}