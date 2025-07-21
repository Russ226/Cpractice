#include <stdio.h>
#include <stdlib.h>
/*
    int fseek(FILE *pointer, long int offset, int position);

    SEEK_END: It denotes the end of the file.
    SEEK_SET: It denotes starting of the file.
    SEEK_CUR: It denotes the file pointer's current position. 

*/
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

char *serialize_person(struct person *p){
    char* serialized=malloc(sizeof(p->firstName) + );
}

int main(){

    return 0;
}