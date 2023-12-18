#include <stdio.h>

int main(){
int vet[100]={30};

printf("%d\n", vet[0]);
for (int i = 0; i < 100; i++){
    vet[i]=1+i;
    printf("%d ", vet[i]);
    }
    return 0;
}