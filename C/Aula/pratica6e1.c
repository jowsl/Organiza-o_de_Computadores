// Jouberth Matheus Simão Pereira 23.2.4011
#include <stdio.h>

int todosDivisores(int);

int main(){
int num1;
    printf("Digite o valor de n: ");
    scanf("%d", &num1);
    todosDivisores(num1);

    return 0;
}

// Função
int todosDivisores(int num1){
    int contador = 1;
    printf("Os divisores de %d são: ", num1);
    while (contador <= num1){
        if(num1 % contador == 0){
            printf("%d ", contador);
        }
        contador = contador + 1;
        }
      return 0;  
    }

    

    
