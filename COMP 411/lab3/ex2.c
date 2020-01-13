#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define MAX 1000

int main(){

char text[MAX], middle[MAX];
int i;
int length;
int pali = 1;

puts("Type some text (then ENTER):");

fgets(text, MAX, stdin);
length = strlen(text) - 1;

puts("Your input in reverse is:");

for (i = 0; i < length; i++){
middle[length - i - 1] = text[i];
if (middle[length - 1 - i] != text[length - i - 1]){
pali = 0;
}
}

for(i = 0; i < length; i++){
printf("%c", middle[i]);
}

printf("\n");

if(pali == 1){
puts("Found a palindrome!");
}
}

