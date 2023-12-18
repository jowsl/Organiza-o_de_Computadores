// Jouberth Matheus Simão Pereira nº23.2.4011
#include <stdio.h>

int main(){
int matriz[3][3], soma1=0, soma2=0, multi1=1, multi2=1;
printf("Digite a matriz: ");
for (int i = 0; i < 3; i++){
    for (int j = 0; j < 3; j++){
        scanf("%d", &matriz[i][j]);
    }
}
    for (int i = 0; i < 3; i++){
        for (int j = 0; j < 3; j++){
            printf("%d ", matriz[i][j]);
        }
        printf("\n");
    }
for (int  i = 0; i < 3; i++){
    for (int j = 0; j < 3; j++){
        if (i==j){
            soma1+=matriz[i][j];
            multi1=multi1*matriz[i][j]; 
        }       
    }
}
soma2 = matriz[0][2]+matriz[1][1]+matriz[2][0];
multi2 = matriz[0][2] * matriz[1][1] * matriz[2][0]; // Não conseguir pensar em uma forma de colocar isso dentro do 'For'

printf("A soma da diagonal principal é %d e a multiplicação dos termos é %d\n", soma1, multi1);
printf("A soma da diagonal secundária é %d e a multiplicação dos termos é %d\n", soma2, multi2);
    return 0;
}
