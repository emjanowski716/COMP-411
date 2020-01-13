#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define MAX 1000

int convert = 0;
char first[MAX];

void create(char c){
if(isalpha(c)){
first[convert] = toupper(c);
convert++;
}
}

int main(){

char text[MAX], middle[MAX], last[MAX];
int i;
int length;
int pali = 1;

puts("Type some text (then ENTER):");

fgets(text, MAX, stdin);
length = strlen(text) - 1;

puts("Your input in reverse is:");

for (i = 0; i < length; i++){
middle[length - i - 1] = text[i];
create(text[i]);
}

for(i = 0; i < length; i++){
printf("%c", middle[i]);
}

printf("\n");

for(i = 0; i < convert; i++){
last[convert - 1 - i] = first[i];
if(last[convert - 1 - i] != first[convert - 1 - i]){
pali = 0;
}
}

if(pali == 1){
puts("Found a palindrome!");
}
}

