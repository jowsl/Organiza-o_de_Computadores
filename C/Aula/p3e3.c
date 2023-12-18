#include <stdio.h>
// Jouberth Matheus Simão Pereira - nº 23.2.4011
int main(){
    float preco, total;
    int pagamento;

    printf("\nDigite o preço do produto: ");
        scanf("%f", &preco);
    if (preco == 0) { 
        printf ("Erro, o preço do produto não pode ser 0!\n\n");
        return 0;
    }
    printf("\nDigite a condição de pagamento: ");
        scanf("%d", &pagamento);
    switch (pagamento){
    case 1:
        total = preco - (preco * 0.1);
        printf("\nO valor final do seu produto sera: R$%.2f\n\n", total);
        break;
    case 2:
        total = preco - (preco * 0.05);
        printf("\nO valor final do seu produto sera: R$%.2f\n\n", total);
        break;
    case 3:
        total = preco;
        printf("\nO valor final do seu produto sera: R$%.2f\n\n", total);
        break;
    case 4:
        total = (preco*1.10);
        printf("\nO valor final do seu produto sera: R$%.2f\n\n", total);
        break;
    default:
        printf("\nErro, condição de pagamento invalida");
        break;
    }
    return 0;
}