#include <stdio.h>
#include <math.h>

int main(){
    double hip, catO, catA;
    printf("Insira o valor dos catetos:\n");
    printf("\nCateto Oposto: ");
    scanf("%lf", &catO);
    printf("\nCateto Adjacente: ");
    scanf("%lf", &catA);
        hip = sqrt(pow(catO, 2)+pow(catA,2));
    printf("O valor da hipotenusa será de: %.2lf\n\n", hip);
    return 0;
}