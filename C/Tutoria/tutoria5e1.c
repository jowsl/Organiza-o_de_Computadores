#include <stdio.h>
// Jouberth Matheus Simão Pereira -  n 23.2.4011
void troca(int* n1, int* n2);

int main(){
int n1, n2;
printf("Entre com dois valores inteiro: \n");
    scanf("%d %d", &n1, &n2);
troca(&n1, &n2);
printf("Os valores trocados são: %d e %d\n\n", n1, n2);    
    return 0;
}

void troca(int* n1, int* n2){
    int trocar = *n1;
    *n1 = *n2;
    *n2 = trocar;
}
