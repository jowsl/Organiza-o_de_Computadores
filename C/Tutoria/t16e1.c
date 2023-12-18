// Jouberth Matheus Simão Pereira nº23.2.4011
#include <stdio.h>
#include <stdio_ext.h>

typedef struct {
    int valor;
    char naipe;
}Truco;

int main(){
Truco teste;
teste.valor = 1;
while (teste.valor > 0){
    printf("Qual valor da sua carta? (Digite 0 para sair.): ");
    scanf("%d", &teste.valor);    
        if (teste.valor == 0){
        printf("\n\tPrograma encerrado. \n\n");
        return 0;
        }
    printf("E o naipe (C - Copas, E - Espadas, O - Ouros, P - Paus)?: ");
    __fpurge(stdin);
    scanf("%c", &teste.naipe);
        switch (teste.valor){
        case 7:
            if (teste.naipe == 'C' || teste.naipe == 'O'){
                printf("\nSua carta é manilha!\n\n");
            } else {
                printf("\nSua carta não é manilha!\n\n");
            }
            break;
        case 1:
            if (teste.naipe == 'E'){
                printf("\nSua carta é manilha!\n\n");
            }
        case 4:
        if (teste.naipe == 'P'){
            printf("\nSua carta é manilha!\n\n");
        }
        default:
        printf("\nSua carta não é manilha!\n\n");
            break;
        }
}
    return 0;
}