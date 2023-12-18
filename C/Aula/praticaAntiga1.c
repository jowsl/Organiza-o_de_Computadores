#include <stdio.h>

int main(){
    int a, b, c, d, resultado;
    printf("Entre com os valores de a, b, c e d:");
        scanf("%d %d %d %d", &a, &b, &c, &d);

        resultado = a*a*a* ((b+c)/d);

    printf("Resultado = %d\n", resultado);

    return 0;
}