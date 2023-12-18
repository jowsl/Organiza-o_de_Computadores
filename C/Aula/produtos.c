#include <stdio.h>

int main(){
int codigo;
    printf("Digite o código do produto: ");
    scanf("%d", &codigo);
    switch (codigo)
    {
    case 1:
        printf("\nAlimento não-perecível\n");
        break;
    case 2:
        printf("\nAlimento perecível\n");
        break;
    case 3:
        printf("\nVestuário\n");
        break;    
    case 4:
        printf("\nLimpeza\n");
        break;  
    default:
        printf("Erro: Número não atribuido a qualquer produto.");
        break;
    }
    return 0;
}