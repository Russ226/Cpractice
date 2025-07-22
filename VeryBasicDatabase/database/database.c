#include <stdio.h>
#include <stdlib.h>








struct Index{
    int id;
    int loc;
};

struct PersonDb{
    int next_id;
    FILE *file;
    IndexArr id_index;
};

typedef struct IndexArr{
    struct Index *arr;
    size_t len;
    size_t cap;    
}IndexArr;

void insertArr(IndexArr *arr, struct Index i){
    if(arr->len == arr->cap){
        arr->cap *= 2;
        size_t newArrSize = sizeof(struct Index) * (arr->cap); 
        arr->arr = realloc(arr->arr, newArrSize);
        assert(sizeof(arr->arr) == newArrSize);
    }
   
    arr->arr[arr->len] = i;
    arr->len++;
}

void deleteArr(IndexArr *arr){
    // TODDO free each indivdual pointer in array
    free(arr->arr);
    arr->arr = NULL;
    free(arr);
    arr = NULL;
    printf("testing assert arr == null: %d\n",  arr == NULL);
}

IndexArr* createDynamicArray(){
    IndexArr *d_arr = malloc(sizeof(IndexArr) * 5);
    d_arr->arr = malloc(sizeof(int));
    d_arr->len = 0;
    d_arr->cap = 1;
    return d_arr;
}
