// Jouberth Matheus Simão Pereira nº23.2.4011
#include <stdio.h>
#include <string.h>
#define MAX 51

int main(){
char string1[MAX], l1, l2;
printf("Digite a frase: ");
fflush(stdin);
fgets(string1, MAX, stdin);
printf("Digite L1:");
fflush(stdin);
scanf(" %c", &l1);
printf("Digite L2:");
fflush(stdin);
scanf(" %c", &l2);

for (int i = 0; i < MAX-1; i++){
    if (string1[i] == l1)
        string1[i] = l2;
}
printf("%s", string1);
    return 0;
}
