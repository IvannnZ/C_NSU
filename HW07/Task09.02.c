#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <malloc.h>

void printArr(int* a, size_t al) {
	for (size_t i = 0; i < al; i++) {
		printf("%d ", *(a + i));
	}
	printf("\n");
}

void scanArr(int* a, size_t al) {
	//int x;
	for (size_t i = 0; i < al; i++) {
		scanf("%d", &(a[i]));
	}
}

int * findSubArr(int* arr1, int arr1L, int* arr2, int arr2L) {
	for (int i = 0; i < arr1L - arr2L; i++) {
		if (arr1[i] == arr2[0]) {
			for (int j = 1; j < arr2L; j++) {
				if (arr1[i+j] != arr2[j]) {
					j = arr2L;
				}
			}
			return (&(arr1[i]));
		}
	}
}

int main() {
	int arr1L;
	printf("Start\n");
	printf("arr1L:");
	scanf("%d", &arr1L);
	int* arr1 = (int*)malloc(sizeof(int) * arr1L);
	if (arr1 == NULL){
		return 0;
	}
	scanArr(arr1, arr1L);

	int arr2L;
	printf("arr2L:");
	scanf("%d", &arr2L);
	int* arr2 = (int*)malloc(sizeof(int) * arr2L);
	if (arr2 == NULL){
		return 0;
	}
	scanArr(arr2, arr2L);
	printf("Answ: %ls", findSubArr(arr1, arr1L, arr2, arr2L));// i can`t print link
	free(arr1);
	free(arr2);
	return 0;
}