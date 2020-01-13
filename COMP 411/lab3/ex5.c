#include <stdio.h>
#include <string.h>
#define MAX_BUF 1024

int main(){

char buf[MAX_BUF], after[MAX_BUF];
int length;

do {
fgets(buf, MAX_BUF, stdin);
length = strlen(buf) - 1;

for(int i = 0; i < length; i++){
char temp = buf[i];
if(temp == 'E' || temp == 'e'){
temp = '3';
} else if (temp == 'I' || temp == 'i'){
temp = '1';
} else if (temp == 'O' || temp == 'o'){
temp = '0';
} else if (temp == 'S' || temp == 's'){
temp = '5';
}
buf[i] = temp;
}

if (length != 1){

printf("%s", buf);
}

} while (length > 0);
}
