#include <stdio.h>

int main(){
    char x;
    printf("Entre com um character qualquer: ");
    scanf("%c", &x);
    if (x >= 'a' && x <= 'z'){
        printf("O char é uma letra minuscula!\n");
    } else if (x >= 'A' && x <= 'Z') {
        printf("O char digitado é uma letra maiuscula!\n");
    } else {
        printf("O character não é uma letra!\n");
    }
       

    return 0;
}