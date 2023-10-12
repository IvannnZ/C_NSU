#include <stdio.h>
#include "stdlib.h"

void is_NULL(char *a){
    if (a==NULL){
        exit (1);
    }
}

int len(char *str){
    int c=0;
    while (str[c]!='\0'){
        c++;
    }
    return c;
}

int len1(char *str){// this function count ' ' in start of strring
    int c=0;
    while (str[c]==' '){
        c++;
    }
    return c;
}

int len2(char *str){// this function count ' ' in end of strring
    int c=0;
    for (int i = len(str)-2; i>=0; i--){
        if (str[i]==' '){
            c++;
        } else{
            return c;
        }
    }
}

void is_null(char *str){
    if (str==NULL) {
        free(str);
        exit(1);
    }
}
char *trim(char *str){
    int c1 = len1(str);
    char *str2 = (char*) malloc(len(str)+2- len1(str)- len2(str));
    is_null(str2);
    for (int i = c1; i<(len(str)- len2((str)-1));i++){
        str2[i-c1] = str[i];
    }
    free(str);
    return str2;
}

int main() {

    char *str = NULL;
    size_t lens = 0;

    printf("Enter line: ");
    getline(&str, &lens, stdin);// I googling this function to make dynamic len of str

    str = trim(str);
    printf("%s", str);

    free(str);
    return 0;

}