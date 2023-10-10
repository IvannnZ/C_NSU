/*
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <assert.h>
#include <math.h>

int is_simple(unsigned long long a) {
	for (unsigned long long i = 2; i <= sqrtf(a); i++) {
		if (a % i == 0) {
			return 0;
		}
	}
	return 1;
}

int main() {
	unsigned long long x;
	scanf("%llu", &x);
	if(x <= 2){
		return 0;
	}
	for (unsigned long long i = 2; i < x; i++) {
		if (is_simple(i) == 1) {
			printf("%d\n", i);
		}
	}
	return 0;
}*/
// this code from prev lesson