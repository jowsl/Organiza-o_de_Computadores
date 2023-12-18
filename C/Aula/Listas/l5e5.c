#include <stdio.h>
#define max 50

int main(){
int vA[max];
for (int i = 0; i < max; i++){
    vA[i] = i*2;
    printf("%d ", vA[i]);
}
    return 0;
}