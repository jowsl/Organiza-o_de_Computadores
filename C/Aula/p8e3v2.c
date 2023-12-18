// Jouberth Matheus Simão Pereira nº23.2.4011
#include <stdio.h>
#define max 100

void abaixoMedia(float valor, int vNumeros[max], float n){
printf("\nValores abaixo da média:");
    for (int i = 0; i < n; i++){
        if (vNumeros[i]<valor)
            printf("%d ", vNumeros[i]);
    }
}

void acimaMedia(float valor, int vNumeros[max], float n){
printf("\nValores acima da média:");
    for (int i = 0; i < n; i++){
        if (vNumeros[i]>valor)
            printf("%d ", vNumeros[i]);
    }
}

int main(){
int vNumeros[max], n=0;
float valor=0; 
while (n>100||n<=0){
printf("\nDigite a quantidade de valores <= 100: ");
scanf("%d", &n);
}
printf("\nDigite os elementos do vetor: ");
for (int i = 0; i < n; i++){
    int nx;
    scanf("%d", &nx);
    vNumeros[i] = nx;
    valor = nx+valor;
}
valor = valor/n;
printf("\nMédia: %.1f", valor);
abaixoMedia(valor, vNumeros, n);
acimaMedia(valor, vNumeros, n);
printf("\n\n");
    return 0;
}