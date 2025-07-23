#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include "Person/person.h"
/*
    int fseek(FILE *pointer, long int offset, int position);

    SEEK_END: It denotes the end of the file.
    SEEK_SET: It denotes starting of the file.
    SEEK_CUR: It denotes the file pointer's current position. 

*/

void test_serialization();

int main(){
    test_serialization();
    return 0;
}

void test_serialization(){
    struct Person *test_person = create_new_person("bob", "smith", 20);

    char *result = serialize_person(test_person, 0);
    char expected[] ="(0,bob,smith,20)";
    assert(strcmp(result, expected) == 0);

}