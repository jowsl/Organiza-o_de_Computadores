/* Vetor pode ser inicializado int vetor[5] ={0,1,2,3,4};
Se for inicializar o vetor, pode-se ignorar o valor entre [chaves]/ Exemplo / double Vetor[] = {10.0, 11.5, 23.9}
-----OQUE NÃO FAZER: declarar uma variável qualquer q vai ser inserida no local tamanho do vetor 
Exemplo: int n; ... scanf n; vet[n] ---- ERRADO, é bem possível que esse vetor vai assumir valores de lixo
o comando TAM_MAX <numero> consegue definir o valor do vetor / Facilita na hora que for trocar
#define ou const TAM_MAX 10
double vetor[TAM_MAX] 
biblioteca limits.h permite setar os valores máximos para os tipos. Exemplo INT_MAX
*/
#include <stdio.h> 
#define TAM_MAX 10

int main(){
int numeros[TAM_MAX];
for(int i=0;i<TAM_MAX;i++){
    printf("Digite um nº %d ", i+1);
    scanf("%d", &numeros[i]);
}
for(int i = TAM_MAX-1; i>=0; i--){
    printf("%d ", numeros[i]);
}
printf("\n");    
    return 0; 
}

