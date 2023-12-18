#include <stdio.h>

int main(){
int num=1, positivos=0, negativos=0;
while (num!=0){
printf("DIGITE UM NUMERO REAL (PARAR = 0):");
scanf("%d", &num);
if (num>0)
    positivos++;
if (num<0)
    negativos++;
}
printf("Quantidade de positiviso e negativos digitados: %d e %d\n\n", positivos, negativos);
    return 0;
}