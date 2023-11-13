#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <malloc.h>

void Is_Null(int *arr) {
    if (arr == NULL) {
        exit(0);
    }
}


void printArr(int *a, size_t al) {
    for (size_t i = 0; i < al; i++) {
        printf("%d ", *(a + i));
    }
    printf("\n");
}

void scanArr(int *a, size_t al) {
    //int x;
    for (size_t i = 0; i < al; i++) {
        scanf("%d", &(a[i]));
    }
}

int findSubArr(int *arr1, int arr1L, int *arr2, int arr2L) {
    for (int i = 0; i < (arr1L - arr2L + 1); i++) {
        if (arr1[i] == arr2[0]) {
            for (int j = 1; j < arr2L; j++) {
                if (arr1[i + j] != arr2[j]) {
                    j = arr2L;
                }
                if (j == (arr2L - 1)) {
                    return (i);
                }

            }
        }
    }
    return -1;
}


int* removeSubArr(int *arr1, int *arr1L, int *arr2, int arr2L) {
    while (1) {
        int adrr = findSubArr(arr1, *arr1L, arr2, arr2L);
        if (adrr != -1) {
            int move = 0;
            int *arr3 = malloc(sizeof(int) * (*arr1L - arr2L));
            Is_Null(arr3);
            for (int i = 0; i < *arr1L - arr2L; i++) {
                if (i == adrr) {
                    move = arr2L;
                }
                arr3[i] = arr1[i + move];
            }
            *arr1L -= arr2L;
            free(arr1);
            arr1 = arr3;//Почему тут не присваевается в арр1 арр3, если смотреть не из этой функции, это же адреса, они же очищаются
        } else {
            return arr1;
        }
    }
}

int main() {
    int arr1L;
    printf("arr1L:");
    scanf("%d", &arr1L);
    int *arr1 = (int *) malloc(sizeof(int) * arr1L);
    Is_Null(arr1);
    scanArr(arr1, arr1L);

    int arr2L;
    printf("arr2L:");
    scanf("%d", &arr2L);
    int *arr2 = (int *) malloc(sizeof(int) * arr2L);
    Is_Null(arr2);
    scanArr(arr2, arr2L);

    int *arr3 = removeSubArr(arr1, &arr1L, arr2, arr2L);

    printArr(arr3, arr1L);

    free(arr2);
    free(arr3);
    return 0;
}



/*
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <malloc.h>

void Is_Null(int *arr) {
    if (arr == NULL) {
        exit(0);
    }
}


void printArr(int *a, size_t al) {
    for (size_t i = 0; i < al; i++) {
        printf("%d ", *(a + i));
    }
    printf("\n");
}

void scanArr(int *a, size_t al) {
    //int x;
    for (size_t i = 0; i < al; i++) {
        scanf("%d", &(a[i]));
    }
}

int *removeSubArr(int *arr1, int arr1L, int *arr2, int arr2L) {
    int *arr3;
    for (int i = 0; i <= arr1L - arr2L; i++) {
        if (arr1[i] == arr2[0]) {
            for (int j = 1; j < arr2L; j++) {
                if (arr1[i + j] != arr2[j]) {
                    j = arr2L;
                } else {
                    if (j + 1 == arr2L) {
                        arr3 = malloc(sizeof(int) * (arr1L - arr2L));
                        Is_Null(arr3);
                        int K = 0;
                        for (int k = 0; k < arr1L; k++) {
                            if (i == k) {
                                k += arr2L;
                                K = arr2L;
                            }
                            arr3[k - K] = arr1[k];
                        }
                        return arr3;
                    }
                }
            }
        }
    }
}

int main() {
    int arr1L;
    printf("arr1L:");
    scanf("%d", &arr1L);
    int *arr1 = (int *) malloc(sizeof(int) * arr1L);
    Is_Null(arr1);
    scanArr(arr1, arr1L);

    int arr2L;
    printf("arr2L:");
    scanf("%d", &arr2L);
    int *arr2 = (int *) malloc(sizeof(int) * arr2L);
    Is_Null(arr2);
    scanArr(arr2, arr2L);

    int *arr3 = removeSubArr(arr1, arr1L, arr2, arr2L);

    printArr(arr3, arr1L - arr2L);

    free(arr1);
    free(arr2);
    free(arr3);
    return 0;
}*/