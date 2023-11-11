#include <stdio.h>
#include <stdlib.h>
#include <setjmp.h>

void is_null(char *str){
    if (str==NULL) {
        free(str);
        exit(1);
    }
}

int is_valid(char c, int base) {
    if (base <= 10) {
        return (c >= '0') && (c - '0' < base);
    } else {
        return (c >= '0' && c < 'A' + (base - 10));
    }
}



int to_int(char num){
    if (num>= '0' && num <= '9'){
        return num - '0';
    } else {
        return num-'A'+10;
    }
}

int s2i(char* num, int base, jmp_buf* env) {
    int result = 0;
    int c = 0;

    if (num[c] == '-') {
        c++;
    }

    while (num[c] != '\n') {
        if (!is_valid(num[c], base)) {
            if (env != NULL) {
                longjmp(*env, 1);
            } else {
                exit(1);
            }
        }
        result = result * base + to_int(num[c]);
        c++;
    }
    if (num[0] == '-') {
        result *= -1;
    }

    return result;
}

int main() {


    char *input = NULL;
    int lens = 0;

    printf("Enter line: ");
    getline(&input, &lens, stdin);// I googling this function to make dynamic len of str

    is_null(input);

    int base;
    printf("Ebter base: ");
    scanf("%d", &base);

    jmp_buf jmpBuffer;

    printf("%d", s2i(input, base, &jmpBuffer));
    free(input);

    return 0;
}
