#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
int adivinhou, tentativas = 0, num;
srand(time (NULL));
    
    adivinhou = rand() % 10 +1; // garante a geração de um número aleatório entre 1 e 10
    do {
        printf("\n\nDigite um número qualquer para tentar adivinha: ");
        scanf("%d", &num);
        if (num != adivinhou){
            printf("Numero %d é Incorreto! Tente novamente! \n", num);
            tentativas++;
        }
        } while ( num != adivinhou);
    printf("Parabéns você adivinhou a resposta %d!\n" 
    "Nº de tentativas foi %d\n"
    "\nFIM DE JOGO\n\n", adivinhou, tentativas);
    return 0;
}