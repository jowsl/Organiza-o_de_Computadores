#include <stdio.h>

int main(){
int a, b, media=0, produtorio=1,contadorImpar=0;
printf("Digite o limite inferior(a):");
scanf("%d", &a);
printf("Digite o limite superior(b):");
scanf("%d", &b);
while (b<a){
    printf("O valor de b deve ser maior que o de a!\n");
    printf("Digite o limite superior(b) corretamente:");
    scanf("%d", &b);
}
for (int i = a; i <= b; i++){
    if (i % 2 == 0){
    produtorio = produtorio*i;
    } else {
    media = media+i;
    contadorImpar++;
    }
}
media = media/contadorImpar;
//produtorio = produtorio+1;
printf("Media dos ímpares: %d\n", media);
printf("Produtórios dos pares: %d\n", produtorio);

    return 0;
}