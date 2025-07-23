#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "../Person/person.h"

struct Index{
    int id;
    int loc;
};

typedef struct IndexArr{
    struct Index *arr;
    size_t len;
    size_t cap;    
}IndexArr;


struct PersonDb{
    int next_id;
    FILE *file;
    IndexArr *id_index;
};



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
    for(int i =0; i < arr->len; i++){
        free(&arr->arr[i]);
    }
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

struct PersonDb *create_personDb(){
    char *db_file_path = "C:\\Users\\russ2\\Desktop\\CPractice\\VeryBasicDatabase\\testFile.txt";
    FILE *fp = fopen(db_file_path, "r+");
    if(fp == NULL){
        fp = fopen("textFile.txt" ,"a");
    }

    IndexArr *a = createDynamicArray();

    struct PersonDb *ret_Item = malloc(sizeof(struct PersonDb));
    ret_Item->file = fp;
    ret_Item->id_index = a;
    ret_Item->next_id = 0;

    return ret_Item;
}
//read

//insert
void insert_person(struct PersonDb *db, struct Person *p){
    // add to index the start location of new person
    char *insert_str =  serialize_person(p, db->next_id);
    db->next_id++;

    fseek(db->file, 0, SEEK_END);
    fprintf(db->file, insert_str);

    free(insert_str);
    free(p);
} 

//delete

//update



int main(){
    struct PersonDb *db = create_personDb();
    struct Person *person_save = create_new_person("bob", "smith", 20);
    insert_person(db, person_save);
    return 0;
}