// Jouberth Matheus Simão Pereira nº23.2.4011
#include <stdio.h>
#define MAX 15

int main(){
int vetorNormal[MAX], vetorRotacionado[MAX], n;
printf("\nEntre com os 15 valores: ");
for (int i = 0; i < MAX; i++){
    scanf("%d", &vetorNormal[i]);
}
printf("\nEntre com valor de n: ");
    scanf("%d", &n);

for (int i = 0; i < MAX; i++){
    int inferno = (i+n) % MAX;
    vetorRotacionado[i] = vetorNormal[inferno];
}
for (int i = 0; i < MAX; i++){
    vetorNormal[i] = vetorRotacionado[i];
}
for (int i = 0; i < MAX; i++){
    printf("%d ", vetorNormal[i]);
}
printf("\n\n");
    return 0;
}