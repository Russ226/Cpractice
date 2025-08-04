#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../Person/person.h"
#include "database.c"

void test_parse_id(){
    printf("\n\n-----------------test_parse_id------------------");
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
    
    printf("\n");
    printf("id of person bob: %d\n", id_1);
    printf("id of person dan: %d\n", id_2);
    printf("id of person robert: %d\n", id_3);
    printf("\n");
    printf("----------------test_parse_id-------------------\n\n");

    free(db);
    free_person(person_save1);
    free_person(person_save2);
    free_person(person_save3);
}

void test_parse_person(){
    struct PersonDb *db = create_personDb();
    struct Person *person_save1 = create_new_person("bob", "smith", 20);
    struct Person *person_save2 = create_new_person("dan", "sai", 33);
    struct Person *person_save3 = create_new_person("robert", "chuscki", 33);

    insert_person(db, person_save1);
    insert_person(db, person_save2);
    insert_person(db, person_save3);

    printf("\n\n-----------------test_parse_person------------------");
    for(int i=0; i<db->id_index->len; i++){
        struct Person *Parsed_person = parse_person(db->file, db->id_index->arr[i].loc);

        print_person(Parsed_person);
        free(Parsed_person);
    }
    printf("----------------test_parse_person-------------------\n\n");
    
    free(db);
}

int main(){
    test_parse_id();
    test_parse_person();
  
    return 0;
}