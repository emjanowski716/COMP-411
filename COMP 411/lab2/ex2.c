#include <stdio.h>

int i = 0;

double sum;
double min;
double max;
double product = 1;
double numbers[10];

int main(){

printf("Enter 10 floating-point numbers:\n");

for (i=0; i<10; i++) {
scanf("%lf", &numbers[i]);

sum += numbers[i];

if (i == 0){
min = numbers[0];
}
else if (numbers[i] < min){
min = numbers[i];
}

if (i == 0){
max = numbers[0];
}
else if (numbers[i] > max){
max = numbers[i];
}

product *= numbers[i];
}

printf("Sum is %0.5lf\n", sum);
printf("Min is %0.5lf\n", min);
printf("Max is %0.5lf\n", max);
printf("Product is %0.5lf\n", product);
} 

