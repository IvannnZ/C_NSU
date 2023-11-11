
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void swap(int* a, int* b) {
	int c = *a;
	*a = *b;
	*b = c;
}

int printArr(int* a, int al) {
	for (int i = 0; i < al; i++) {
		for (int j = 0; j < al; j++) {
			printf("%d\t", a[ ( i * al ) + j ]);
		}
		printf("\n");
	}
	printf("\n");

}

int main() {
	int a[4][4];
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			printf("%d - %d:", i, j);
			scanf("%d", &a[i][j]);
		}
	}

	printArr(a, 4);

	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			if (i > j) {
				printf("%d,%d = ", a[i][j], a[j][i]);
				swap(&a[i][j], &a[j][i]);
				printf("%d,%d\n", a[i][j], a[j][i]);
			}
		}
	}


	printArr(a, 4);
	
	return 0;
}