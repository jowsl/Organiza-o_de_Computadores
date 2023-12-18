#include <stdio.h>
#include <string.h>

int main(){
char string[100], c, temp[100]={0};
printf("Entre com a string:");
fgets(string, 100, stdin);
string[strlen(string)-1]='\0'; // removendo \n após o fgets
printf("Entre com o character:");
    scanf(" %c", &c);
    int x = strlen(string);
    int contador=0;
    for (int i = 0; i < x; i++){
        if (string[i]!=c){
            temp[contador]=string[i];
            contador++;
        }
    }
temp[contador]='\0';
for (int i = 0; i <= contador; i++){
    string[i]=temp[i];
}
string[contador]='\0';
printf("A string resultante é: %s\n", string);
    return 0;
}