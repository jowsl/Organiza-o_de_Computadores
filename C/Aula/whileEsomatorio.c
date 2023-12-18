#include <stdio.h>
#include <math.h>

int main(){
int n;
double soma = 0;
    printf("Digite um valor qualquer: ");
        scanf("%d", &n);
    if (n > 0){
    int i=0;
        while ( i <= n-1 ){
            soma = soma + 1/(pow(2,i));
            i++;

        }
        printf("Resultado: %lf\n", soma);

    } else {
        printf("Erro \n Valor deve ser maior que zero. \t Tente novamente.\n");
    }
    return 0;
}