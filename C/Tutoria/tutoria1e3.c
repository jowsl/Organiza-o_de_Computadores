#include <stdio.h>
// Jouberth Matheus Simão Pereira

int main(){
int primeiro_digito, codigo_modelo, codigo_cor;

    printf("Digite o código do veículo: ");
        scanf("%d", &codigo_modelo);
    primeiro_digito = codigo_modelo / 1000;

    switch (primeiro_digito) {
        case 1: printf("O Veículo é um(a): Corolla"); 
            break;
        case 2: printf("O Veículo é um(a): Fiat Uno");
            break;
        case 3: printf("O Veículo é um(a): Celta");
            break;
        case 4: printf("O Veículo é um(a): Opala");
            break;
        case 5: printf("O Veículo é um(a): Marea");
            break;
        case 6: printf("O Veículo é um(a): Hilux");
            break;
        default:
        printf("Motocicleta.");
        return 0;
    }
    codigo_cor = codigo_modelo % 6;
    switch (codigo_cor){
    case 0: printf(" Preto\n\n");
        break;
    case 1: printf(" Branco\n\n");
        break;
    case 2: printf(" Vermelho\n\n");
        break;
    case 3: printf(" Azul\n\n");
        break;
    case 4: printf(" Amarelo\n\n");
        break;
    case 5: printf(" Prata\n\n");
        break;    
    default: printf("Erro. Nenhuma cor encontrada.\n\n");
        break;
    }

    return 0;
}
