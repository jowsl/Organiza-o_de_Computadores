// Jouberth Matheus Simão Pereira nº23.2.4011
#include <stdio.h>
#define max 51

int main(){
char frase[max], letra;
int contador=0;
printf("Digite a frase: ");
fflush(stdin);
fgets(frase, max, stdin);
printf("Digite a letra: ");
fflush(stdin);
scanf(" %c", &letra);
for (int i = 0; i < max; i++){
    if (frase[i]==letra){
    contador++;
    }
}
printf("Quantidade de vezes que a letra %c aparece: %d\n\n", letra, contador);
    return 0;
}