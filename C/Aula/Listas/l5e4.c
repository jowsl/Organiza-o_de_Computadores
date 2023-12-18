#include <stdio.h>
#define MAX 10

int main(){
int vA[MAX], vB[MAX], vC[MAX];
printf("Entre com os valores de vA:");
for (int i = 0; i < MAX; i++){
    scanf("%d", &vA[i]);
}
printf("Entre com os valores de vB:");
for (int i = 0; i < MAX; i++){
    scanf("%d", &vB[i]);
}
printf("O vC (soma de vA[i] e vB[i]) é: ");
for (int i = 0; i < MAX; i++){
    vC[i] = vA[i]+vB[i];
    printf("%d ", vC[i]);
}
printf("\n");

    return 0;
}