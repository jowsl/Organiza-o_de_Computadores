#include <stdio.h>
#define max 20
int main(){
int vetor[max], vetorInverso[max];
printf("Entre com os valores: ");
for (int i = 0; i < max; i++){
    scanf("%d", &vetor[i]);
}
printf("Vetor normal:");
for (int i = 0; i < max; i++){
    printf("%d ", vetor[i]);
    vetorInverso[max-1-i]=vetor[i];
}
printf("\n");
printf("Vetor invertido: ");
for (int i = 0; i < max; i++){
    vetor[i]=vetorInverso[i];
    printf("%d ", vetor[i]);
}
    return 0;
}