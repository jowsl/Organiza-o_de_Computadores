#include <stdio.h>
#include <string.h>
int main(){
char vString[100], l1, l2;
int x;
printf("Digite l1 e l2: ");
scanf(" %c %c", &l1, &l2);
getchar();
printf("Digite a vString: ");
fgets(vString, 100, stdin);
vString[strlen(vString)-1]='\0';
x = strlen(vString);
for (int i = 0; i < x; i++){
    if (vString[i]==l1){
        vString[i]=l2;
    }
}
printf("%s", vString);
    return 0;
}