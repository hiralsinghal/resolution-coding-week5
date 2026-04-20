#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define INPUT_LENGTH 100

char *FILENAME = "contact_book_data.csv";

int add_new_entry();

int main () {
    add_new_entry();

    return 0;
}

int add_new_entry() {
    FILE *fptr;

    fptr = fopen(FILENAME, "a");

    char name[INPUT_LENGTH] = "name_here";
    char address[INPUT_LENGTH] = "address_here";
    char email[INPUT_LENGTH] = "input_here";
    char number[INPUT_LENGTH] = "number_here";

    fprintf(fptr)
}