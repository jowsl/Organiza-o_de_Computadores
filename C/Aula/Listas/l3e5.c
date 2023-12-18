#include <stdio.h>

int main(){
int numStart=6, numEnd;
printf("Entre com o número limite: ");
scanf("%d", &numEnd);
do{
if (numStart % 3 ==0){
    printf("%d ", numStart);
    }
numStart++;
} while (numStart<=numEnd);
    return 0;
}