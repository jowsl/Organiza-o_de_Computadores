// Jouberth Matheus Simão Pereira nº23.2.4011
#include <stdio.h>
#include <stdlib.h>

int buscaLinear(int buscado, int *vetor, int n);

int main(){
    int *vetor, n, valor;

    printf("Digite o tamanho do vetor: ");
    scanf("%d", &n);
    
    vetor = malloc ( n * sizeof(int));

    printf("Digite os valores do vetor:");
    for (int i = 0; i < n; i++){
        scanf("%d", &valor);
        vetor[i] =  valor;
    }
    
    printf("Digite o valor que você quer contar: ");
    int numero;
    scanf("%d", &numero);
    int teste = buscaLinear(numero, vetor, n);

    printf("\nO %d apareceu %d vezes\n", numero, teste);
    int antecessor = (numero) - 1;
    teste = buscaLinear(antecessor, vetor, n);

    printf("O antecessor de %d, %d, apareceu %d vezes\n", numero, numero-1, teste);
    int sucessor = (numero) + 1;
    teste = buscaLinear(sucessor, vetor, n);

    printf("O sucessor de %d, %d, apareceu %d vezes\n", numero, numero+1, teste);

    free(vetor);
    return 0;
}

int buscaLinear(int buscado, int *vetor, int n){
    int contador=0;
    for (int i = 0; i < n; i++){
        if (vetor[i] == buscado)
            contador++;
    }
    return contador;
}