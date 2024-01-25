// Jouberth Matheus Simão Pereira nº23.2.4011
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdio_ext.h>



typedef struct{
    char id;
    float x;
    float y;
} coordenadas;


int main(){
    int n;
    char novoNome[100];
    coordenadas *vetor;

    FILE *arquivo = fopen ("aux.txt", "w+");
    printf("Digite o número de pontos: ");
    scanf("%d", &n);
    fprintf(arquivo, "%d\n", n);

    vetor = (coordenadas*)malloc(n * sizeof(coordenadas));

    for (int i = 0; i < n; i++)
    {
        printf("Ponto %d:", i+1);
        printf("\nDigite o identificador, a coord. x e coord. y: ");
        __fpurge(stdin);
        scanf("%c %f %f", &vetor[i].id, &vetor[i].x, &vetor[i].y);
        fprintf(arquivo, "%c %.1f %.1f\n", vetor[i].id, vetor[i].x, vetor[i].y );
    }

    printf("Digite o nome do arquivo para salvamento: ");
    __fpurge(stdin);
    fgets(novoNome, sizeof(novoNome), stdin);

    if (novoNome[strlen(novoNome) - 1] == '\n') {
        novoNome[strlen(novoNome) - 1] = '\0';
    }
    rename("aux.txt", novoNome);

    free(vetor);
    fclose(arquivo);
    return 0;

}