#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <malloc.h>

void printArr(int* a, size_t al) {
	for (size_t i = 0; i < al; i++) {
		printf("%d ", *(a + i));
	}
	printf("\n");
}

void is_NULL(int *a){
	if (a==NULL){
		//exit 0;
	}
}

void is_NULL2(int **a){
	if (a==NULL){
		//exit 0;
	}
}


int main(){
	int al;
	printf("al:");
	scanf("%d", &al);
	int **a = (int **)malloc(sizeof(int*)*al);
	is_NULL2(a);
	for (int i = 0; i<al; i++){
		int *b=(int*)malloc(sizeof(int) * (i+1));
		is_NULL(b);
		b[0]=1;
		for (int j = 1; j<i;j++){
			b[j] = (a[i-1][j] + a[i-1][j-1]);
		}
		b[i]=1;
		a[i] = b;
	}
	
	for (int i = 0; i<al; i++){

		for (int h = 0; h<((al-i-1))/2; h++){
			printf("    ");
		}
		if (i%2==al%2){
			printf("  ");
		}// i try make 
		for (int j = 0; j<i+1;j++){
			printf("%d    ", a[i][j]);
		}
		printf("\n");
	}

	for (int i = 0; i<al; i++){
		free(a[i]);
	}
	free(a);
	return 0;
}