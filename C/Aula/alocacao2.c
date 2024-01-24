#include <stdio.h>
#include <stdlib.h>
// protótipo
int *inverso(int *v);

int main(){
    int v[5] = {1,2,3,4,5};
    int *invertido = inverso(v);
    printf("Vetor invertido:");
    for (int i = 0; i < 5; i++)
        printf("%d\t", invertido[i]);
    printf("\n\n");
    free(invertido);
    return 0;
}

int *inverso(int *v){
    int *vinv = malloc(5 * sizeof(int));
    for (int i=0; i < 5; i++)
        vinv[i] = v[5-1-i];
    return vinv;
}