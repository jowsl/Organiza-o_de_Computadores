#include <stdio.h>
#include <math.h>
#define PI 3.1415
int main(){
    double alpha, hip;
    printf("\nInsira o valor da hipotenusa: ");
    scanf("%lf", &hip);
    printf("\nInsira agora o valor do ângulo alpha (angulo que se forma com o cat adjacente): ");
    scanf("%lf", &alpha);
        alpha = alpha * PI/180.0 ; //passando alpha para rad
    double catO = sin(alpha)*hip; 
    double catA = cos(alpha)*hip;
        catA = round(catA);
        catO = round(catO);
    printf("\nA hipotenusa vale %.0f o cateto oposto vale %.0f e o cateto adjacente vale %.0f.\n\n", hip, catO, catA);

    return 0;
}