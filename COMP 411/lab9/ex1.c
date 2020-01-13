#include<stdio.h>

void makepatterns(int n, int current, char pattern[]);

int main(){
	int n;
	scanf("%d", &n);
	char pattern[n];
	pattern[n] = '\0';
	makepatterns(n, 0, pattern);
}

void makepatterns(int n, int current, char pattern[]){
	if(current == n){
		for(int i = 0; i < n; i++){
			printf("%d", pattern[i]);
		}
		printf("\n");
	} else {
		pattern[current] = 0;
		makepatterns(n, current + 1, pattern);
		pattern[current] = 1;
		makepatterns(n, current + 1, pattern);
}
}
