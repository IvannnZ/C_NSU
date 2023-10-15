#include <stdio.h>
#include "stdlib.h"

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
    int len_str = len(str);
    for (int i = len_str - 2; i>=0; i--){
        if (str[i]==' '){
            c++;
        } else{
            return c;
        }
    }
}

int count(char *str, char ch){
    int c = 1;
    int len_str = len(str);
    for (int i = 0; i < len_str;i++){
        if (str[i]==ch){
            c++;
        }
    }
    return c;
}

int lenfr(char *str, int slen){
    int c=0;
    int len_str = len(str);
    for (int i = slen; i<len_str; i++){
        if (str[i]!=' '){
            c++;
        } else{
            return c;
        }
    }
    return c;
}

void printStr_Arr(char** str_arr, int len){
    printf("[");
    for (int i = 0; i<len;i++){
        printf("'%s' ,", str_arr[i]);
    }
    printf("\b\b]");
}

void freeStr_Arr(char** str_arr, int len){
    for (int i = 0; i<len;i++){
        free(str_arr[i]);
    }
    free(str_arr);
}

void is_null(char *str){
    if (str==NULL) {
        free(str);
        exit(1);
    }
}

char *trim(char *str){
    int c1 = len1(str);
    int len_str = len(str), len_str2= len2(str);

    char *str2 = (char*) malloc(len_str + 2 - len1(str)- len2(str));
    is_null(str2);
    for (int i = c1; i<(len_str- len_str2 - 1);i++){
        str2[i-c1] = str[i];
    }
    free(str);
    return str2;
}

char **split(char *str, int *lenret){
    str = trim(str);
    *lenret = count(str, ' ');
    char **arr_str = (char **) malloc(sizeof(char*) * (*lenret));
    is_null(str);
    int c=1, c2=0;
    char *str3 = (char*)malloc(sizeof(char) * lenfr(str, 0));
    is_null(str);
    arr_str[0]=str3;
    for (int i = 0; i<len(str); i++){
        if (str[i]==' '){
            str3 = (char*)malloc(sizeof(char) * lenfr(str, i));
            is_null(str);
            arr_str[c] = str3;
            c2=0;
            c++;
        } else{
            str3[c2] = str[i];
            c2++;
        }
    }
    return arr_str;
}

int main() {

    char *str = NULL;
    int lens = 0;

    printf("Enter line: ");
    getline(&str, &lens, stdin);// I googling this function to make dynamic len of str

    is_null(str);

    int len;
    char **str_arr = split(str, &len);
    printStr_Arr(str_arr, len);

    freeStr_Arr(str_arr, len);
    return 0;

}