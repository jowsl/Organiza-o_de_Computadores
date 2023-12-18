// Jouberth Matheus Simao pereira
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int main(){
srand(time(NULL));
int numAleatorio = rand() % 100 +1;
// printf("%d ", numAleatorio); ---- testar se esta gerando
printf("##Caça aliens 2000##\n\n");

int i = 0, num;
while(i <= 6){
    printf("Onde está o alien?");
    scanf("%d", &num);
    if(num<numAleatorio){ 
        printf("Errou, esta a direita!\n");
    } else if (num>numAleatorio) { 
        printf("Errou, esta a esquerda\n");
    } else { printf ("\n\nAcertou, estou morto x.x\n\n");
    return 0;
    } 
    i++;
}
printf("FIM DE JOGO: Você errou os 6 disparos. ");
    return 0;
}