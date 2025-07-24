#include <stdio.h>
#include <stdlib.h>
/*
    fopen() - create a new file or open a existing file
    fclose() - close a file
    getc() - reads a character from a file
    putc() - writes a character to a file
    fscanf() - reads a set of data from a file
    fprintf() - writes a set of data to a file
    getw() - reads a integer from a file
    putw() - writes a integer to a file
    fseek() - set the position to desire point
    ftell() - gives current position in the file
    rewind() - set the position to the beginning point

    r - open a file in read mode
    w - opens or create a text file in write mode
    a - opens a file in append mode
    r+ - opens a file in both read and write mode
    a+ - opens a file in both read and write mode
    w+ - opens a file in both read and write mode


*/

void read_from_file(){
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

}


int main(){
    FILE *fp = fopen("C:\\Users\\russ2\\Desktop\\CPractice\\ReadingFile\\testFile2.txt", "w");
    char  *write_str1 = "test 1";
    printf("\n\n");
    printf("size of file before write 1: %d\n ", ftell(fp));

    fprintf(fp, write_str1);
    fseek (fp, 0, SEEK_END);
    printf("size of string to write 1: %d\n", sizeof(write_str1));
    printf("size of file after write 1: %d\n", ftell(fp));


    return 0;
}