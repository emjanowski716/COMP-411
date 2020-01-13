#include<stdio.h>
#include<stdlib.h>

#define true 1
#define false 0
#define MAX 100

int maze[100][100];
int wasHere[100][100];
int correctPath[100][100];
int width;
int height;
int startX, startY, endX, endY;
int recursiveSolve(int x, int y);

int recursiveSolve(int x, int y){

if(x == endX && y == endY){
return 1;
}
else if (maze[y][x] == '*' || wasHere[y][x] == 1){
return 0;
}
wasHere[y][x] = 1;

if(x != 0){
if(recursiveSolve(x-1, y) == 1){
correctPath[y][x] = 1;
return 1;
}
}
if(x != width - 1){
if(recursiveSolve(x+1, y) == 1){
correctPath[y][x] = 1;
return 1;
}
}
if(y != 0){
if(recursiveSolve(x, y-1) == 1){
correctPath[y][x] = 1;
return 1;
}
}
if(y != height - 1){
if(recursiveSolve(x, y+1) == 1){
correctPath[y][x] = 1;
return 1;
}
}
return 0;
}

int main(){

int x, y;

scanf("%d%d", &width, &height);

scanf("\n");

char tempchar;

for(y = 0; y < height; y++){
for(x = 0; x < width; x++){
scanf("%c", &tempchar);
maze[y][x] = tempchar;

if(maze[y][x] == 'S'){
startX = x;
startY = y;
}

if(maze[y][x] == 'F'){
endX = x;
endY = y;
}

wasHere[y][x] = 0;
correctPath[y][x] = 0;
}
scanf("\n");
}

recursiveSolve(startX, startY);
for(int i = 0; i < height; i++){
for(int j = 0; j < width; j++){
if(correctPath[i][j] == 1 && maze[i][j] != 'S'){
maze[i][j] = '.';
}
}
}
for(int i = 0; i < height; i++){
for(int j = 0; j < width; j++){
printf("%c", maze[i][j]);
}
printf("\n");
}
}

