#ifndef PERSON_H
#define PERSON_H

struct Person;

struct Person *create_new_person(char* firstName, char* lastName, unsigned int age);
void free_person(struct Person *p);
char *serialize_person(struct Person *p, int id);
char *convert_int_str(int v);



#endif