#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int MAX_TEXT_LENGTH = 200;

int min(int a, int b, int c){
    if(a <= b && a <= c) return a;
    else if(b <= a && b <= c) return b;
    else return c;
}

int max(int a, int b){
    if(a >= b) return a;
    else return b;
}

int distance(char* a, int a_length, char* b, int b_length) {
    int temp;
    if(min(a_length, b_length, __INT32_MAX__) == 0) return max(a_length, b_length);
    else{
        //if(a[a_length-1] == b[b_length-1]) temp = __INT32_MAX__;
        return (a[a_length-1] == b[b_length-1])?
            min(distance(a, a_length-1, b, b_length)+1, distance(a, a_length, b, b_length-1)+1, distance(a, a_length-1, b, b_length-1)):
            min(distance(a, a_length-1, b, b_length)+1, distance(a, a_length, b, b_length-1)+1, distance(a, a_length-1, b, b_length-1)+1);
    }
}

int main() {
    char* a = malloc(MAX_TEXT_LENGTH*sizeof(char));
    char* b = malloc(MAX_TEXT_LENGTH*sizeof(char));
    scanf("%[^\n]", a);
    scanf("%c\n", b); // reads \n
    scanf("%[^\n]", b);
    printf("%d\n", distance(a, strlen(a), b, strlen(b)));
}