#include <stdio.h>

int main(){
int vA[10], vAinvertido[10];
for (int i = 0; i < 10; i++){
    printf("Entre com o valor do índice %d: ", i);
    scanf("%d", &vA[i]);
    }
for (int i = 0; i < 10; i++){
        vAinvertido[9-i] = vA[i]; // Índice é sempre tamanho-1
    }
for (int i = 0; i < 10; i++){
    printf("%d ", vA[i]);
}
printf("\n");
for (int i = 0; i < 10; i++){
    printf("%d ", vAinvertido[i]);
}
    return 0;
}

