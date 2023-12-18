#include <stdio.h>

int main(){
float preco, precoFinal;
    printf("Valor do produto: ");
    scanf("%f", &preco);
    if (preco < 20){
        precoFinal = preco + (preco*0.45);
    } else { 
        precoFinal = preco + (preco*0.30);
    }
    printf("Valor do produto ja com o lucro imbutido é %.2f", precoFinal);

    return 0;
}