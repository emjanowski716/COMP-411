#include <stdio.h>
#include <string.h>
#define NUM 25
#define LEN 1000

int my_compare_strings(char string1[], char string2[]){
for (int i = 0; i < LEN; i++){
if (string1[i] > string2[i]){
	return 1;
} else if (string1[i] < string2[i]){
	return -1;
} 
}
return 0;
}

void my_swap_strings(char string1[], char string2[]){

char temp;
for (int i = 0; i < LEN; i++){
temp = string1[i];
string1[i] = string2[i];
string2[i] = temp;
}
}

int main(){

char Strings[NUM][LEN];

printf("Please enter %d strings, one per line:\n", NUM);

for (int i = 0; i < NUM; i++){
fgets(Strings[i], LEN, stdin);
}

puts("\nHere are the strings in the order you entered:");

for (int i = 0; i < NUM; i++){
char *letters = Strings[i];
while (*letters != '\0'){
printf("%c", *letters++);
}
}

char tempstring[LEN];
for (int i = 0; i < NUM-1; i++){
for (int j = 0; j < NUM-i-1; j++){
if (strcmp(Strings[j], Strings[j+1]) > 0){
strcpy(tempstring, Strings[j]);
strcpy(Strings[j], Strings[j+1]);
strcpy(Strings[j+1], tempstring);
}
}
}
 
puts("\nIn alphabetical order, the strings are:");

for (int i = 0; i < NUM; i++){
char *abc = Strings[i];
while (*abc != '\0'){
printf("%c", *abc++);
}
}
}

