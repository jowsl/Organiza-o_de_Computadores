#include <stdio.h>

void converteLiquidos(float litros, float *oz, float *gallons);

int main(){
    float litros, oz, gallon;
        printf("Digite o total em litros: ");
            scanf("%f", &litros);
        converteLiquidos(litros, &oz, &gallon);        
        printf("Total em oz: %.2f\nTotal em gallons: %.2f\n\n", oz, gallon);


    return 0;
}

void converteLiquidos(float litros, float *oz, float *gallons){
        *oz = litros * 33.814;
        *gallons = litros * 0.264172;

}