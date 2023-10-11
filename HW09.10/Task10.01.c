#define _CRT_SECURE_NO_WARNINGS
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

void is_null(char *str){
    if (str==NULL) {
        free(str);
        exit(1);
    }
}
char *rem_space(char *str){
    int c=0;
    for (int i = 0; i<len(str);i++){
        if (str[i]==' '){
            c++;
        }
    }
    if (c==0){
        return str;
    }
    char *str2 = (char*)malloc((len(str) - 1 - c)*sizeof(char));
    is_null(str2);
    int C=0;
    for (int i=0; i<(len(str)); i++){
        if (str[i]==' '){
            C++;
        } else {
            str2[i-C]=str[i];
        }
    }
    free(str);
    return str2;
}

int palindrom(char *str){
    str = rem_space(str);
    is_null(str);

    for (int i=0;i<len(str);i++){
        printf("%c", str[i]);
    }
    for (int i=0; i<((len(str)-1)/2); i++){
        if (str[i]!=str[len(str)-2-i]){
            return 0;
        }
    }
    return 1;
}
int main() {

    char *str = NULL;
    size_t lens = 0;

    printf("Enter line: ");
    getline(&str, &lens, stdin);// I googling this function to make dynamic len of str

    if (palindrom(str)){
        printf("It`s palendrom");
    } else{
        printf("It isn`t palendrom");
    }

    free(str);
    return 0;

}