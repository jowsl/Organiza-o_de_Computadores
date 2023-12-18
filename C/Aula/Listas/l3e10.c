#include <stdio.h>
#define MAX 10

int main(){
char vSexo[MAX];
float vAltura[MAX];
for (int i = 0; i < MAX; i++){
    printf("Entre com o sexo do indivíduo %d :", i+1);
    scanf(" %c", &vSexo[i]);
}
for (int i = 0; i < MAX; i++){
    printf("Entre com a altura do indivíduo %d : ", i+1);
    scanf("%f", &vAltura[i]);
}
printf("\n\n");
printf("Gênero\tAltura\n");
for (int i = 0; i < MAX; i++){
    printf("%c\t%.2f\n", vSexo[i], vAltura[i]);
}
printf("\n\n");

    return 0;
}