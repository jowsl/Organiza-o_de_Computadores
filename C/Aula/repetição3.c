#include <stdio.h>

int main(){
int numero = 20;
// printf("");
// scanf("%d", &numero);
int x, y;
for (x = 1; x < 20; x +=2) { 
    for(y = 1; y < 20 ; y+=2){
       if (numero % 2 != 0) printf("%3d", x*y);
    }
    printf("\n");
}
    return 0;
}