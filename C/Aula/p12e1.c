// Jouberth Matheus Simão Pereira nº23.2.4011
#include <stdio.h>
#include <stdlib.h>

int main(){
    int n, contPar=0, contImpar=0;
    
    printf("Digite o valor de n:");
    scanf("%d", &n);

    int *vet1 = malloc (n * sizeof(int));

    printf("\nDigite os valores do vetor:");
    for (int i = 0; i < n; i++){
        scanf("%d", &vet1[i]);
        if(vet1[i] % 2 == 0)
        contPar++;
    }
    contImpar = n - contPar;
    printf("\nVetor com os valores pares:");
    if(contPar == 0) 
        printf("Vazio\n");
        else{
            printf("[ ");
            int *vet_par = malloc (contPar * sizeof(int));
            int i_par = 0;
            for (int i = 0; i < n; i++){
                if (vet1[i] % 2 == 0){
                vet_par[i_par] = vet1[i];
                printf("%d ", vet_par[i_par]);
                i_par++;
                }
            }
            printf("]\n");
            free(vet_par);
        }

    printf("Vetor com os valores ímpares:"); 
    if(contImpar == 0)
        printf("Vazio\n");
        else{
            printf("[ ");
            int *vet_impar = malloc (contImpar * sizeof(int));
            int i_impar = 0;
            for (int i = 0; i < n; i++){
                if(vet1[i] % 2 != 0){
                    vet_impar[i_impar] = vet1[i];
                    printf("%d ", vet_impar[i_impar]);
                }
            }
            printf("]\n");
            free(vet_impar);
        }
        free(vet1);
    return 0;
}
