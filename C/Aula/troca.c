#include <stdio.h>

//protótipo
void troca(int *a, int *b);
int naotroca(int *a, int *b);

int main(){
    int a, b;
    printf("Digite 2 numeros inteiros> \n");
        scanf("%d %d", &a, &b);
    if (b>a){
        troca(&a, &b);
        printf("a = %d \nb = %d \n", a, b);
    } else {
        naotroca(&a, &b);
    }
    return 0;
}

// funções
void troca(int *a, int *b){
    int pa = *a;
    *a = *b;
    *b = pa; 
}
int naotroca(int *a, int *b){
    *a = *a *1; *b = *b *1;
    printf("Okay!\n a = %d \n  b= %d \n", *a, *b);
    return 0;
}