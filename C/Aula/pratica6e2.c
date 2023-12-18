// Jouberth Matheus Simao Pereira n 23.2.4011
#include <stdio.h>
// prototipo
int quadrado_por_soma(int n);

int main() {
    int n, quadrado;
    printf("Digite um número: ");
    scanf("%d", &n);
    quadrado = quadrado_por_soma(n);
    printf("O quadrado de %d é: %d\n", n, quadrado);
    return 0;
}

//funcao
int quadrado_por_soma(int n) {
int i = 1, soma = 0;
    while(i <= 2*n-1) {
        soma = soma + i;
        i = i + 2;
    }
    return soma;
}

