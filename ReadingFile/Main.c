#include <stdio.h>
#include <stdlib.h>

int main(){
    FILE * fp = fopen("C:\\Users\\russ2\\Desktop\\CPractice\\ReadingFile\\testFile.txt", "rt");

    if(fp == NULL) {
        printf("Not able to open the file.");
    }

    // Store the content of the file
    char myString[100];

    // Read the content and print it and set cursor
    fgets(myString, 100, fp);
    printf("%s", myString);
    // reset cursor to beginning of the file
    fseek(fp, 0, SEEK_SET);

    fgets(myString, 100, fp);
    printf("%s", myString);

    // Close the file
    fclose(fp);
    return 0;
}