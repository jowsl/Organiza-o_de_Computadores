#include <stdio.h>
#define max 100
int main(){
int num;
while(num<max){
    if(num % 2 !=0){
    printf("%d ", num);
    }
    num++;
}
    return 0;
}