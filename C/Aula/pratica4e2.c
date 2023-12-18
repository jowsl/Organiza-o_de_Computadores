#include <stdio.h>
// Jouberth Matheus Simão Pereira   

// Protótico
void ordena3valores(int a, int b, int c, int *menor, int *meio, int *maior);

int main(){
    int a, b, c, maior, meio, menor;
        printf("\nDigite três valores: ");
            scanf("%d %d %d", &a, &b, &c);
    ordena3valores(a, b, c, &menor, &meio, &maior);
        
        printf("\nOs valores ordenados são: %d %d %d \n\n", maior, meio, menor);
    return 0;
}

// Função
void ordena3valores(int a, int b, int c, int *maior, int *meio, int *menor){
    if(a > b && b > c){
        *maior = a;
        *meio = b;   
        *menor = c;
    } else if (a > c && c > b) {
        *maior = a;  
        *meio = c;   
        *menor = b;
    } else if (b>a && a>c){
        *maior = b;  
        *meio = a;   
        *menor = c;
    } else if (b>c && c>a){
        *maior = b;  
        *meio = c;   
        *menor = a;
    } else if (c>a && a>b){
        *maior = c;  
        *meio = a;   
        *menor = b;
    } else {
        *maior = c;  
        *meio = b;   
        *menor = a;
    }
}