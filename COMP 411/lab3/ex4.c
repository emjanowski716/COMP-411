#include <stdio.h>

int main(){

int A[3][3];
int B[3][3];
int C[3][3];

printf("Please enter 9 values for matrix A:\n");

for(int i = 0; i < 3; i++){
for(int j = 0; j < 3; j++){
scanf("%d", &A[i][j]);
}
}

printf("Please enter 9 values for matrix B:\n");

for(int i = 0; i < 3; i++){
for(int j = 0; j < 3; j++){
scanf("%d", &B[i][j]);
C[i][j] = A[i][j] + B[i][j];
}
}

printf("C = B + A =\n");

for(int i = 0; i < 3; i++){
for(int j = 0; j < 3; j+=3){
printf("%10d%10d%10d\n", C[i][j], C[i][j+1], C[i][j+2]);
}
}
}

