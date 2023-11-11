/*
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void evilScanf(int* P0, int* P1, int* P2) {
    int N0, N1, N2;
    scanf("%d", &N0);
    scanf("%d", &N1);
    scanf("%d", &N2);
    if (N0 > 0) {
        *P1 = N1;
        *P2 = N2;
    }
    else 
    {
        *P1 = *P0;
        *P2 = N0 * N1 * N2 * (*P1) * (*P2);
    }
    *P0 = N0;
}

int main() {
    int a , b, c;
    scanf("a: %d", &a);
    scanf("b: %d", &b);
    scanf("c: %d", &c);

    evilScanf(&a, &b, &c);
    
    printf("%d %d %d \n", a, b, c);
    
    return 0;
}*/