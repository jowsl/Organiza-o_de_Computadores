#include <stdio.h>
#include <math.h>

int main(){
    int num1 = 0;
    float quadrado, cubo;
    printf("Insira um número para que seja calculado os quadrados e cubos dele: \n");
    scanf("%d",&num1);
    while (num1 <= 100){
        quadrado = pow(num1,2);
        cubo = pow(num1,3);
        printf("Num \tQuad\tCubo\n"
        "%d\t %.0f\t%.0f\n", num1, quadrado, cubo);
        num1++;      
    }
    return 0;
}