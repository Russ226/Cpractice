#include <stdlib.h>
#include <stdio.h>
#include <assert.h>



typedef struct DynamicArray{
    int *arr;
    size_t len;
    size_t cap;    
}DynamicArray;

void insertArr(DynamicArray *arr, int i){
    if(arr->len == arr->cap){
        arr->cap *= 2;
        size_t newArrSize = sizeof(int) * (arr->cap); 
        arr->arr = realloc(arr->arr, newArrSize);
        assert(sizeof(arr->arr) == newArrSize);
    }
   
    arr->arr[arr->len] = i;
    arr->len++;
}

void deleteArr(DynamicArray *arr){
    free(arr->arr);
    arr->arr = NULL;
    free(arr);
    arr = NULL;
    printf("testing assert arr == null: %d\n",  arr == NULL);
}

DynamicArray* createDynamicArray(){
    DynamicArray *d_arr = malloc(sizeof(DynamicArray));
    d_arr->arr = malloc(sizeof(int));
    d_arr->len = 0;
    d_arr->cap = 1;
    return d_arr;
}


int main(){
    printf("starting....\n");
    DynamicArray *test = createDynamicArray();

    insertArr(test, 1);

    printf("element number one: %d\n", test->arr[0]);

    insertArr(test, 2);

    printf("element number one: %d\n", test->arr[1]);

    deleteArr(test);
    test = NULL;
    printf("testing assert arr == null: %d\n",  test == NULL);
  
    return 0;
}