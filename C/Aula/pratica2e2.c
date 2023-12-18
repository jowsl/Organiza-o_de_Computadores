#include <stdio.h>

int main(){
int idade, ano_nascimento, ano_atual, resposta;
    printf("Entre com o ano de nascimento: ");
        scanf("%d", &ano_nascimento);
    printf("Entre com o ano atual: ");
        scanf("%d", &ano_atual);
    idade = ano_atual - ano_nascimento;
    resposta = 2025 - ano_nascimento;
    printf("\nVoce tem %d", idade);
    printf("\nEm 2025 voce tera %d", resposta);

    return 0;
}