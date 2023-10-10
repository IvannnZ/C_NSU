
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <malloc.h>

void printArr(int* a, size_t al) {
	for (size_t i = 0; i < al; i++) {
		printf("%d ", *(a + i) );
	}
	printf("\n");
}

void scanArr(int* a, size_t al) {
	for (size_t i = 0; i < al; i++) {
		scanf("%d", &(a[i]));
	}
}

int* concat (int* a, int* al, int* b, int bl) {
	//a = (int*)realloc(a, (*al + bl));
	int* c = (int*)malloc(sizeof(int) * ((*al) + bl));
	for (int i = 0; i < *al; i++) {
		c[i] = a[i];
	}
	for (int i = *al; i < (*al + bl); i++) {
		c[i] = b[ ( i - *al ) ];
	}

	free(a);
	*al += bl;
	
	free(b);
	return c;
}

int main() {
	int al, bl;

	printf("al: ");
	scanf("%d", &al);
	int* a = (int*)malloc(al * sizeof(int));
	if (a == NULL) {
		return 0;
	}
	scanArr(a, al);
	
	printf("bl: ");
	scanf("%d", &bl);
	int* b = (int*)malloc(sizeof(int) * bl);
	if (b == NULL) {
		return 0;
	}
	scanArr(b, bl);


	a = concat(a, &al, b, bl);
	
	printArr(a, al);
	
	free(a);
	return 0;
}	