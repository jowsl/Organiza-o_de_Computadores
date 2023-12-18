#include <stdio.h>

int main(){
int hora, min, seg, segResultado;
    printf("Digite a hora, minutos e segundos: ");
        scanf("%d %d %d", &hora, &min, &seg);
        
    segResultado = hora*3600 + min*60 + seg; //calculo, passando tudo para segundo.

    printf("Total: %d\n\n", segResultado  );



    return 0;
}