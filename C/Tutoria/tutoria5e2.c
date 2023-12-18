#include <stdio.h>
// Jouberth Matheus Simão Pereira - nº 23.2.4011
void converteMedidas(float metros, float *jardas, float *pes, float *polegadas);

int main(){
float metros, jardas, pes, polegadas;
    printf("\nDigite o tamanho em metros: ");
    scanf("%f", &metros);
    converteMedidas(metros, &jardas, &pes, &polegadas);
    printf("%.2f Metros \n"
    "%.2f Polegadas\n" 
    "%.2f Jardas\n"
    "%.2f Pés\n", metros, jardas, pes, polegadas);    
    return 0;
}

void converteMedidas(float metros, float *jardas, float *pes, float *polegadas){
    *jardas = metros * 1.09 ;
    *pes = metros * 3.28;
    *polegadas = metros * 39.37;
}
