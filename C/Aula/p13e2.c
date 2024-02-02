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

float dist2Pontos(const coordenadas *a, const coordenadas *b);

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

    FILE *arquivo = fopen (Nome, "r");
    
    fscanf(arquivo, "%d", &n);

    vetor = (coordenadas*)malloc(n * sizeof(coordenadas));

    for(int i = 0; i < n; i++){
    __fpurge(stdin);
    fscanf(arquivo, " %c %f %f", &vetor[i].id, &vetor[i].x, &vetor[i].y);
    }

    fclose(arquivo);
    //int contador=0;
    for (int i = 0; i < n; i++){
        for(int j = i +1; j < n; j++){
            float dist = dist2Pontos(&vetor[0], &vetor[j]);
            printf("\nDistância entre %c e %c: %.2f", vetor[0].id, vetor[j].id, dist);
            //contador++;
            //if (contador == 1) break;
            
        }
    }

    free(vetor);
    return 0;
}

float dist2Pontos(const coordenadas *a,const coordenadas *b){
    return sqrt(pow((b->x - a->x), 2) + pow((b->y - a->y), 2));
}