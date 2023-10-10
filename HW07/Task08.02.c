
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <malloc.h>

void printArr(int* a, size_t al) {
	for (size_t i = 0; i < al; i++) {
		printf("%d ", a[i]);
	}
	printf("\n");
}


int main() {
	int* arr, * arr2;
	int size = 1, sizer = 0, x;
	arr = (int*)malloc(sizeof(int) * size);
	while (1)
	{
		scanf("%d", &x);
		if (x == 0) {
			break;
		}
		if ((sizer + 1) > size) {
			arr2 = (int*)malloc(size * 2 * sizeof(int));
			for (int i = 0; i < size; i++) {
				arr2[i] = arr[i];
			}
			free(arr);
			arr = arr2;
			size *= 2;
		}
		arr[sizer] = x;
		sizer++;
	}
	if (sizer < size) {
		arr2 = (int*)malloc(sizer * sizeof(int));
		for (int i = 0; i < sizer; i++) {
			arr2[i] = arr[i];
		}
		free(arr);
		arr = arr2;
	}
	printArr(arr, sizer);
}