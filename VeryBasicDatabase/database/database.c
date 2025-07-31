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
} 

//delete

//update

//parser
struct Person *parse_person(FILE *f, int loc){
    
    char* string_temp;
    int temp_char;
    int comma_counter = 0;

    int id, age;
    char* first_name;
    char* last_name;

    fseek(f, loc, SEEK_SET);
    do{
        int string_cap = sizeof(char)*10;
        string_temp =  (char*)malloc(string_cap);
        int column_counter = 0;

        do{
            temp_char = getc(f);
            if(column_counter == string_cap){
                string_cap *=2;
                string_temp = realloc(string_temp, string_cap);
            }
            if(temp_char == ',' || temp_char == ')'){
                //prevents for str copying junk to new string
                string_temp[column_counter] = '\0';
                break;
            }


            string_temp[column_counter] = temp_char;
            column_counter++;
        }
        while(temp_char != EOF);

        switch(comma_counter){
            case 0:
                id = atoi(string_temp);
                break;
            case 1:
                first_name = malloc(sizeof(string_temp));
                strcpy(first_name, string_temp);
                break;
            case 2:
                last_name = malloc(sizeof(string_temp));
                strcpy(last_name, string_temp);
                break;
            case 3:
                age = atoi(string_temp);
                break;
            default:
                printf("something went wrong parsing person");
                break;
        }
        free(string_temp);
        comma_counter++;
    }
    while(temp_char != EOF && temp_char != ')');

    return create_new_person_wth_id(first_name, last_name, age, id);
}

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

