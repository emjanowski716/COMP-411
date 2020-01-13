#include <stdio.h>

int main(){

int NchooseK(int n, int k);

int n, k, result;
do {
scanf("%d", &n);
if (n == 0){
break;
}
scanf("%d", &k);
result = NchooseK(n, k);
printf("%d\n", result);
} while (n != 0);
}

int NchooseK(int n, int k){

if (n==k){
return 1;
}
if (k==0){
return 1;
}
return (n * NchooseK(n-1, k-1)) / k;
}
