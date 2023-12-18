#include <stdio.h>
#define TAM_MAX 10
int main(){
double vet[TAM_MAX];
for(int i=0;i<TAM_MAX; i++){
    vet[i] =  TAM_MAX-1-i;
    printf("%.0lf ", vet[i]);
}
    return 0;
}