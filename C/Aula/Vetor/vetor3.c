#include <stdio.h>
#define MAX 5
int main(){
int num[MAX];
for (int i = 0; i < MAX; i++){
    printf("Digite um número: ");
    scanf("%d", &num[i]);    
}
for (int i = MAX-1; i >= 0; i--){ // para evitar printar um lixo de memória
    printf("%d ", num[i]);
    }

    return 0;
}