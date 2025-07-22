#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "person.h"

struct Person{
    char* firstName;
    char* lastName;
    unsigned int age;
};

struct Person *create_new_person(char* firstName, char* lastName, unsigned int age){
    if(sizeof(firstName) < 1 || sizeof(firstName) < 1){
        return NULL;
    }

    struct Person *ret_item = malloc(sizeof(struct Person));
    ret_item->firstName = firstName;
    ret_item->lastName = lastName;
    ret_item->age = age;

    return ret_item;
}

void free_person(struct Person *p){
    free(p->firstName);
    free(p->lastName);
    free(p);
}

char *convert_int_str(int v){
    char* ret_item = malloc(sizeof(char) * 20);
    sprintf(ret_item, "%d", v);

    return ret_item;
}

char *person_row_rep(struct Person *p){
    char* serialized = malloc(sizeof(p) + 8 * 4);
    char* converted_int = convert_int_str(p->age);

    strcpy(serialized, "(");
    strcat(serialized, p->firstName);
    strcat(serialized, ",");
    strcat(serialized, p->lastName);
    strcat(serialized, ",");
    strcat(serialized, converted_int);
    strcat(serialized, ")");

    free(converted_int);
    return serialized;
}