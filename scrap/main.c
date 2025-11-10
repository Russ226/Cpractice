#include <stdlib.h>
#include <stdio.h>
#include <stddef.h>
#include <string.h>
#include <unistd.h>
void func(){
    printf("L0\n");
    if (fork() == 0) {
        printf("L1\n");
        fork();
        printf("L2\n");
    }
    printf("Bye\n");
}
int main(){
    func();
    return 0;
}