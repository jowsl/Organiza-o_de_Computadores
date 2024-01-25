// Jouberth Matheus Simão Pereira nº23.2.4011
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdio_ext.h>
#include <math.h>


typedef struct{
    char id;
    float x;
    float y;
} coordenadas;


int main(){
    int n;
    char Nome[100];
    coordenadas *vetor;

    printf("Digite o nome do arquivo: ");
    __fpurge(stdin);
    fgets(Nome, sizeof(Nome), stdin);
    if (Nome[strlen(Nome) - 1] == '\n') {
        Nome[strlen(Nome) - 1] = '\0';
    }


    FILE *arquivo = fopen (Nome, "r+");
    
    fscanf(arquivo, "%d", &n);

    vetor = (coordenadas*)malloc(n * sizeof(coordenadas));

    for (int i = 0; i < n; i++)
    {
        __fpurge(stdin);
        fscanf(arquivo, "%c %f %f", &vetor[i].id, &vetor[i].x, &vetor[i].y);
            printf("DEBUG %c %f %f ", vetor[i].id, vetor[i].x, vetor[i].y);

        float dist = sqrt((pow((vetor[i+1].x - vetor[0].x), 2) + pow((vetor[i+1].y - vetor[0].y),2)));
        printf("\nDistância entre %c e %c: %.2f", vetor[0].id, vetor[i+1].id, dist);

    }
    
    free(vetor);
    fclose(arquivo);
    return 0;

}