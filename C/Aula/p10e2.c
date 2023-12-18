// Jouberth Matheus Simão Pereira nº23.2.4011
#include <stdio.h>
#define max 4
int main(){
float matriz[max][max];
for (int i = 0; i < max; i++){
    printf("Digite a linha %d da matriz: ", i+1);
    for(int j = 0; j < max; j++){
    scanf("%f", &matriz[i][j]);
    }
}
float media=0.0, acima, abaixo;
for (int i = 0; i < max; i++){  
    for(int j = 0; j < max; j++){
    media = matriz[i][j]+media;
    }
}
media = media / 16.0;
printf("Média da matriz: %.2f\n", media);
printf("Acima da média: ");
for (int i = 0; i < max; i++){
    for(int j = 0; j < max; j++){
        if (media<matriz[i][j]){
            printf("%.2f ", matriz[i][j]);
        }
    }
} 
printf("\n");
printf("Abaixo ou igual a média: ");
for (int i = 0; i < max; i++){
    for (int j = 0; j < max; j++){
        if (media>=matriz[i][j])
        printf("%.2f ", matriz[i][j]);
    }
}
    return 0;
}