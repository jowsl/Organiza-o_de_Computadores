#include <stdio.h>

int main(){
int numeros = 0, soma = 0;
    printf("Entre com número para serem somados ou 0 para mostrar a soma: ");
    scanf("%d", &numeros);
    while ( numeros > 0){
        printf("Digite um número: ");
        scanf("%d", &numeros);
        soma += numeros; 
    }
    printf("A soma dos números digitados será: %d", soma);
    return 0;
}