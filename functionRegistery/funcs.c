#include <stdio.h>

void test(){
    printf("this is a test \n");
}

int fact(int n){
    if(n == 0){
        return 1;
    }

    if(n < 0){
        return -11;
    }

    return n * fact(n - 1);
}

