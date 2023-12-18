// Jouberth Matheus Simão Pereira nº23.2.4011
#include <stdio.h>

int main(){
int n;
char l;
printf("Letra: ");
scanf("%c", &l);
do{
printf("N: ");
scanf("%d", &n);
} while (n<=0);
for(int i=0;i<n;i++){
    for (int j = 0; j<n; j++){
    if (i==0 || i==n-1 || j==0 || j==n-1)
    printf("%c", l);
        else
        printf(" ");

   }   
printf("\n");
}
    return 0;
}
