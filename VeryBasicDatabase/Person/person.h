#ifndef PERSON_H
#define PERSON_H

struct Person{
    unsigned int id;
    char* firstName;
    char* lastName;
    unsigned int age;
};

struct Person *create_new_person(char* firstName, char* lastName, unsigned int age);
struct Person *create_new_person_wth_id(char* firstName, char* lastName, unsigned int age, unsigned int id);
void free_person(struct Person *p);
char *serialize_person(struct Person *p, int id);
char *convert_int_str(int v);
void print_person(struct Person *p);



#endif