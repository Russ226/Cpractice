#include <stdio.h>
#include <stdlib.h>
#include <string.h>
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
    }
   
    arr->arr[arr->len] = i;
    arr->len++;
}

void delete_item(IndexArr *arr, int index){
    if(index >= arr->len || arr->len == 0){
        return;
    }

    for (int i = index; i < arr->len - 1; i++) {
        arr->arr[i] = arr->arr[i + 1];
    }

    arr->len--;
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
    d_arr->arr = malloc(sizeof(struct Index));
    d_arr->len = 0;
    d_arr->cap = 1;
    return d_arr;
}

struct PersonDb *create_personDb(){
    char *db_file_path = "C:\\Users\\russ2\\Desktop\\CPractice\\VeryBasicDatabase\\database\\textFile.txt";
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
    struct Index new_ind;
    char *insert_str =  serialize_person(p, db->next_id);
    new_ind.id = db->next_id;
    db->next_id++;

    fseek(db->file, 0, SEEK_END);
    int loc_id = ftell(db->file) + 1;
    fprintf(db->file, insert_str);

    new_ind.loc = loc_id;

    insertArr(db->id_index, new_ind);

    free(insert_str);
    free(p);
} 

//delete

//update


int get_id(FILE *f, int loc){
    char *str_id =malloc(sizeof(char)*4);
    int temp;
    int counter = 0;
    fseek(f, loc, SEEK_SET);
    do{
        temp = getc(f);
        if(temp == ','){
            break;
        }

        str_id[counter] = temp;
        counter++;
    }
    while(temp != EOF);
    
    int ret_item = atoi(str_id);
    free(str_id);
    return ret_item;
}

int main(){
    struct PersonDb *db = create_personDb();
    struct Person *person_save1 = create_new_person("bob", "smith", 20);
    struct Person *person_save2 = create_new_person("dan", "sai", 33);
    struct Person *person_save3 = create_new_person("robert", "chuscki", 33);
    
    insert_person(db, person_save1);
    insert_person(db, person_save2);
    insert_person(db, person_save3);

    int id_1 = get_id(db->file, db->id_index->arr[0].loc); 
    int id_2 = get_id(db->file, db->id_index->arr[1].loc); 
    int id_3 = get_id(db->file, db->id_index->arr[2].loc);
    
    printf("\n\n");
    printf("id of person bob: %d\n", id_1);
    printf("id of person dan: %d\n", id_2);
    printf("id of person robert: %d\n", id_3);
       
    return 0;
}