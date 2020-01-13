#include<stdio.h>

int AA[100];
int BB[100];
int CC[100];

int main(){

int r;

scanf("%d", &r);

for(int i = 0; i < r; i++){
	for(int j = 0; j < r; j++){
		int temp;
		scanf("%d", &temp);
		AA[i*r+j] = temp;
	}
}

for(int i = 0; i < r; i++){
	for(int j = 0; j < r; j++){
		int temp;
		scanf("%d", &temp);
		BB[i*r+j] = temp;
	}
}

for(int i = 0; i < r; i++){
	for(int j = 0; j < r; j++){
		
		for(int k = 0; k < r; k++){
			CC[i*r+j] += AA[i*r+k] * BB[k*r+j];
		}
	}
}

for(int i = 0; i < r; i++){
	for(int j = 0; j < r; j++){
		printf("%d ", CC[i*r+j]);
	}
	printf("\n");
}
}
