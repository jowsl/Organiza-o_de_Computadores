#include <stdio.h>

int main(){
int num; 
float media=0;
printf("Digite a idade:");
scanf("%d", &num);
int i=0;
media = media+num;
while (num!=0){
    printf("Digite a idade:");
    scanf("%d", &num);
    i++;
    media = media+num;
}
media = media/i;
//printf("%d %.1f", i,media); (debug)
printf("A média dos valores é: %.1f\n\n", media);
    return 0;
}