/*
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <assert.h>
#include <math.h>

int func(unsigned int a) {
	int c = 0;
	for (unsigned int i = 2; i <= a; i++) {
		if (a % i == 0) {
			c ++;
			//printf("i: %d\n", i);
		}
	}
	return c;
}

int main() {
	unsigned long long x;
	scanf("%llu", &x);
	if (x <= 2) {
		printf("Nuber invalid\n");
		return 0;
	}

	printf("%d", func(x));

	return 0;
}*/