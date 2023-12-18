#include <stdio.h>
#include <math.h>
// escrever e retornar dis entre dois pontos (x1, y1) e (x2, y2) 
int main(){
    double dis, x1, y1, x2, y2;
    printf("\nDigite os valores de X (abscissas) e Y (ordenadas) do ponto A: ");
    scanf("%lf %lf", &x1, &y1);
    printf("\nAgora entre com os valores de X e Y para o ponto B: ");
    scanf("%lf %lf", &x2, &y2);
    dis = sqrt(pow(x1-x2,2)+pow(y1-y2,2));
    printf("\nA distancia entre o ponto A e o ponto B é exatamente: %.2lf .\n\n", dis);

    return 0;
}