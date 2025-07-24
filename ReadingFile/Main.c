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

void read_test_number_from_file(){
    FILE *fp = fopen("C:\\Users\\russ2\\Desktop\\CPractice\\ReadingFile\\testFile2.txt", "r+");
    char  *write_str1 = "test 1";
    char  *write_str2 = "test 2";
    char  *write_str3 = "test 3";
    printf("\n\n");
    printf("size of file before write 1: %d\n ", ftell(fp));
    
    fprintf(fp, write_str1);
    int write1 = ftell(fp);
    
    fprintf(fp, write_str2);
    int write2 = ftell(fp);

    fprintf(fp, write_str3);
    int write3 = ftell(fp);

    fseek(fp, write1-1, SEEK_SET);
    printf("write 1 number: %c\n", getc(fp));

    fseek(fp, write2-1, SEEK_SET);
    printf("write 2 number: %c\n", getc(fp));

    fseek(fp, write3-1, SEEK_SET);
    printf("write 3 number: %c\n", getc(fp));
}

int main(){
    

    return 0;
}