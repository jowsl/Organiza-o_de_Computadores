#include <stdio.h>
#define M 4
#define N 4
int main(){
int A[M][N] = {{1,2,3,4},{5,6,7,8},{9,10,11,12},{13,14,15,16}};
int B[M][N] = {{1,2,3,4},{5,6,7,8},{9,10,11,12},{13,14,15,16}};
int C[M][N];
for (int i = 0; i < M; i++){
    for (int j = 0; j < N; j++){
        C[i][j] = A[i][j] + B [i][j];
    }
    
}
for (int i = 0; i < M; i++){
    for (int j = 0; j < N; j++){
        printf("%d ", C[i][j]);
    }
    printf("\n");
}

    return 0;
}