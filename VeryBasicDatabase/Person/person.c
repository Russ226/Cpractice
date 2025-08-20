#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "person.h"



struct Person *create_new_person(char* firstName, char* lastName, unsigned int age){
    if(sizeof(firstName) < 1 || sizeof(lastName) < 1){
        return NULL;
    }

    struct Person *ret_item = malloc(sizeof(struct Person));
    ret_item->firstName = firstName;
    ret_item->lastName = lastName;
    ret_item->age = age;

    return ret_item;
}

struct Person *create_new_person_wth_id(char* firstName, char* lastName, unsigned int age, unsigned int id){
    if(sizeof(firstName) < 1 || sizeof(lastName) < 1){
        return NULL;
    }

    struct Person *ret_item = malloc(sizeof(struct Person));
    ret_item->firstName = firstName;
    ret_item->lastName = lastName;
    ret_item->age = age;
    ret_item->id = id;

    return ret_item;
}

void free_person(struct Person *p){
    //free(p->firstName);
    //free(p->lastName);
    free(p);
}

char *convert_int_str(int v){
    char* ret_item = malloc(sizeof(char) * 20);
    sprintf(ret_item, "%d", v);

    return ret_item;
}

char *serialize_person(struct Person *p, int id){
    char* serialized = malloc(sizeof(p) + sizeof(int) + 8 * 4);
    char* converted_age = convert_int_str(p->age);
    char* converted_id = convert_int_str(id);

    strcpy(serialized, "(");
    strcat(serialized, converted_id);
    strcat(serialized, ",");
    strcat(serialized, p->firstName);
    strcat(serialized, ",");
    strcat(serialized, p->lastName);
    strcat(serialized, ",");
    strcat(serialized, converted_age);
    strcat(serialized, ")");

    free(converted_id);
    free(converted_age);

    return serialized;
}

void print_person(struct Person *p){
    printf("\nId: %d\nFirst Name: %s\nLast Name:%s\nAge:%d\n", p->id, p->firstName, p->lastName, p->age);
}