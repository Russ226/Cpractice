#include <stdlib.h>
#include <stdio.h>

struct lazy{
    int i;
    int y;
};


int main(){


    for(int i = 0; i < 100000000; i++){
        for(int y = 0; y < 100000000; y++){
            struct lazy *l = malloc(sizeof(struct lazy));

            l->i = i;
            l->y = y;

            free(l);
        }
    }

    return 0;
}