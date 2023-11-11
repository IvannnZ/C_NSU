
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <malloc.h>


void swap(int* a, int* b) {
	int c = *a;
	*a = *b;
	*b = c;
}

int len(int a) {
	int c=1,C = 10;
	while (C <= a) {
		C *= 10;
		c++;
		//printf("%d  %d  %d\n", a, c, C);
	}
	//printf("len: %d\n", c);
	return c;
}


void scanArr(int* a, size_t al) {
	//printf("%d", al);
	for (size_t i = 0; i < al; i++) {
		scanf("%d", &(a[i]));
		//printf("%d, %d\n", a[i], i);
	}
}

void printArr(int* a, size_t al) {
	for (size_t i = 0; i < al; i++) {
		printf("%d ", a[i]);
	}
	printf("\n");
}

void rewertArr(int* a, size_t al) {
	for (size_t i = 0; i < al/2; i++) {
		swap(&a[i], &a[(al - i - 1)]);
	}
}
int maxlnArr(int* a, size_t al) {
	int maxx = 0;
	maxx = a[0];
	for (size_t i = 1; i < al; i++) {
		if (a[i] > maxx) {
			maxx = a[i];
		}
	}
	return maxx;
}
int findArr(int* a, size_t al, int x) {
	for (size_t i = 0; i < al; i++) {
		if (a[i] == x) {
			return i;
		}
	}
	return -1;
}

void extractDigits(int* a, int al, int x) {
	for (int i = len(x) - 1; i >= 0; i--) {
		a[i] = x % 10;
		x = x / 10;
		//printf("From extractDigits %d\n",x);
	}
}

int compareArrays(int* a, int al, int* b, int bl) {
	if (al != bl) {
		if (al > bl) {
			return 1;
		}
		else{
			return -1;
		}
	}

	for (size_t i = 0; i < al; i++) {
		if ((a[i] > b[i])) {
			return 1;
		}
		if (a[i] < b[i]) {
			//printf("%d, %d\n", a[i], b[i]);
			return -1;
		}
	}
	return 0;
}

int main() {
	int* a, al, x, *b, bl;
	//scanf("%d", &al);


	printf("Enter len. of first massive:");
	scanf("%d", &al);//why it didn`t work?
	a = calloc(al, sizeof(int));
	scanArr(&a, al);
	printArr(&a, al);
	rewertArr(&a, al);
	printArr(&a, al);
	printf("max: %d \n", maxlnArr(&a, al));

	printf("Enter X1: ");
	scanf("%d", &x);
	printf("Index of x: %d\n", findArr(&a, al, x));

	printf("Enter X2: "); 
	scanf("%d", &x);

	extractDigits(&a, al, x);

	printArr(&a, al);

	printf("Enter. len of second massive");
	scanf("%d", &bl);
	b = malloc(bl * sizeof(int));
	scanArr(&b, bl);
	printArr(&b, bl);

	printf("answ: %d", compareArrays(&a, al, &b, bl));

		//for (int i = al-1; i >= 0; i--) {// in internet i found free(a), I understand that it`s incorect, but am I correct?
	//	printf("%d\n", i);
	//	free(a[i]);
	//}
	
	//free(&a);
	//return 0;
}