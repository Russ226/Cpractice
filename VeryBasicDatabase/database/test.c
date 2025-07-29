#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../Person/person.h"
#include "database.c"

void test_parse_id(){
    printf("\n\n-----------------ANSI_COLOR_REDtest_parse_id------------------");
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
    printf("\n\n");
    printf("----------------test_parse_id-------------------\n\n");
}

int main(){
    test_parse_id();
       
    return 0;
}