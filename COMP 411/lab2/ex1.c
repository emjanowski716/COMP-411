#include <stdio.h>

int main() {

int r;

printf("Enter a number from 1 to 20:\n");
scanf("%d", &r);

if (r == 1){
printf("Here are the first %d ordinal numbers:\n", r);
printf("1st \n");
}
else if (r == 2){
printf("Here are the first %d ordinal numbers:\n", r);
printf("1st \n2nd \n");
}
else if (r == 3) {
printf("Here are the first %d ordinal numbers:\n", r);
printf("1st\n2nd\n3rd\n");
}
else if (r > 20 || r < 1) {
printf("Number is not in the range from 1 to 20\n"); 
}
else {
printf("Here are the first %d ordinal numbers:\n", r);
printf("1st\n2nd\n3rd\n");
int i = 0;
for (i=4; i<=r; i++){
printf("%dth\n", i);
}
}


}
