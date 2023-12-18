#include <stdio.h>

int main(){
 char conceito;
    printf("Digite o conceito: ");
        scanf(" %c", &conceito);
    /* if (conceito == 'A'){
        printf("\nExcelente!\n");
    } else if (conceito == 'B'){
        printf("\nÓtimo!\n");
    } else if (conceito == 'C'){
        printf("\nBom!\n");
    } else if (conceito == 'D'){
        printf("\nRegular!\n");
    } else if (conceito == 'E'){
        printf("\nRuim!\n");
    } else if (conceito == 'F'){
        printf("\nNos vemos no ano que vem!\n");
    } else {
        printf("\nErro!\n");
    } */
    switch (conceito){ // switch so funciona com valores constantes, 
        case 'A': case 'a':    // char precisa se colocado entre apostofres ' ' //
        printf("\nExcelente!\n");
        break;
        case 'B': case 'b':
        printf("\nÓtimo!\n");
        break;
        case 'C': case 'c':
        printf("\nBom!\n");
        break;
        case 'D': case 'd':
        printf("\nRegular!\n");
        break;
        case 'E': case 'e':
        printf("\nRuim!\n");
        break;
        case 'F': case 'f':
        printf("\nNos vemos no ano que vem!\n");
        break;
        default:
        printf("Erro, conceito inexistente!");
    }
    return 0;
}