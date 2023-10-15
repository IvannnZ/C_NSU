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
		//exit (0);
	}
}

void rebild(int * arr1, int * arr2, int arrL){
	for (int i=0; i<arrL; i++){
		arr1[i]=arr2[i];
	}
}

int main()
{
	int s;
	//printf("s:");
	scanf("%d", &s);
	int arrLM=1, arrL=0;
	int * arr1 = (int *)malloc(sizeof(int) * arrLM);
	while(s!=0){
		if (arrL>arrLM){
			arrLM *=2;
			int * arr2=(int *)malloc(sizeof(int) * arrLM);
			is_NULL(arr2);
			rebild(arr2, arr1, arrL);
			free(arr1);
			arr1 = arr2;
		}
		arr1[arrL] = s;
		arrL++;
		//printf("s:");
		scanf("%d", &s);
	}
	if (arrL<arrLM){
		int * arr2 = (int *)malloc(sizeof(int)*arrL);
		rebild(arr2, arr1, arrL);
		free(arr1);
		arr1=arr2;
	}
	printArr(arr1, arrL);
	free(arr1);
	return 0;
}//i want to try write this type, and also i didn`t read that need to use realloc))
