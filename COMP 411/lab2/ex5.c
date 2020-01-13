#include <stdio.h>

int width = 0;
int height = 0;

int main(){

do {
printf("Please enter width and height:\n");
scanf("%i", &width);

if (width == 0){
break;
}

scanf("%i", &height);

for (int i = 0; i < height; i++){
for (int j = 0; j < width; j++){
if (j == 0 || j == width-1){
if (i == 0 || i == height-1){
printf("+");
}
else{
printf("|");
}
}
else{
if (i == height-1 || i == 0){
printf("-");
}
else {
printf("~");
}
}
}
printf("\n");
}
}
while(1==1);
printf("End\n");
}
