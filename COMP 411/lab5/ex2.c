#include<stdio.h>

int A[10][10];
int B[10][10];
int C[10][10];

int main(){
int r;
scanf("%d", &r);

for(int i = 0; i < r; i++){
for(int j = 0; j < r; j++){
int temp;
scanf("%d", &temp);
A[i][j] = temp;
}
}

for(int i = 0; i < r; i++){
for(int j = 0; j < r; j++){
int temp;
scanf("%d", &temp);
B[i][j] = temp;
}
}

for(int i = 0; i < r; i++){
for(int j = 0; j < r; j++){
for(int k = 0; k < r; k++){
C[i][j] += A[i][k] * B[k][j];
}
}
}

for(int i = 0; i < r; i++){
for(int j = 0; j < r; j++){
printf("%6d", C[i][j]);
}
printf("\n");
}
}

