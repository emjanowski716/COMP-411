#include <stdio.h>
#include <stdlib.h>

void collatz(int num){

int temp = 0;

if(num % 2 == 0){
temp = num / 2;
if(temp == 1){
printf("1/n");
exit(0);
}
printf("%d, ", temp);
collatz(temp);
} else {
temp = 3*num+1;
printf("%d, ", temp);
collatz(temp);
}
}

int main(){

int start = 0;
printf("Please enter the starting number of the Collatz sequence:\n");
scanf("%d", &start);
printf("%d, ", start);
collatz(start);
}
