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
    }
   
    arr->arr[arr->len] = i;
    arr->len++;
}

void delete_item(DynamicArray *arr, int index){
    if(index >= arr->len || arr->len == 0){
        return;
    }

    for (int i = index; i < arr->len - 1; i++) {
        arr->arr[i] = arr->arr[i + 1];
    }

    arr->len--;
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

void print_arr(DynamicArray *arr){
    for(int i = 0; i < arr->len; i++){
        printf("print index of arr %d with value %d \n", i, arr->arr[i]);
    }

    printf("\n\n");
}


int main(){
    printf("starting....\n");
    DynamicArray *test = createDynamicArray();

    insertArr(test, 1);

    insertArr(test, 2);

    insertArr(test, 3);
    insertArr(test, 4);
    insertArr(test, 5);

    print_arr(test);

    delete_item(test, 2);

    print_arr(test);
    
  
    return 0;
}