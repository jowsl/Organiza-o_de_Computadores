// Jouberth Matheus Simão Pereira nº23.2.4011
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int verificarNotas(char gabarito[10], char matriz[3][10], int i, int nota){
    nota = 0;
            for (int j = 0; j < 10; j++){
                if (gabarito[j]==matriz[i][j])
                nota++;
            }
    return nota;
}

int leitorMatriz(char matriz[3][10]){
for (int i = 0; i < 3; i++){
    printf("Resposta do aluno %d:", i);
    for (int j = 0; j < 10; j++){
        scanf(" %c", &matriz[i][j]);
        }
    }
    return 0;
}
void leitorGabarito(char gabarito[10]){
printf("Entre com o gabarito: ");
    for (int i = 0; i < 10; i++){
        scanf(" %c", &gabarito[i]);
    }
}

int main(){
char matriz[3][10], gabarito[10];
int nota;

leitorMatriz(matriz);
leitorGabarito(gabarito);

for (int i = 0; i < 3; i++){
    nota = verificarNotas(gabarito, matriz, i, nota);
    printf("Nota do aluno %d: %d\n", i, nota);
    }
    return 0;
}