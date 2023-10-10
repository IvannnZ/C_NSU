/*
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>

int evklid(int x, int y) {
	if (x == y) {
		return x;
	}
	if (x < y) {
		y = y - x;
	}
	else
	{
		x = x - y;
	}

	return (evklid(x, y));

}

int main() {
	int x, y, h;
	
	scanf("%d", &x);
	scanf("%d", &y);



	if (fmin(x,y) <= 2) {// y is lesser than x, so we need check only y
		return 0;
		printf("do I need to write reasons for departure?");//yes i know that that after return, and this message didn`t send
		//p.s. why i don`t write it in coment
	}

	printf("%d", evklid(x,y));


	return 0;
}
*/