#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define INPUT_LENGTH 100

char *FILENAME = "contact_book_data.csv";

typedef struct Contact {
    char name[INPUT_LENGTH];
    char address[INPUT_LENGTH];
    char email[INPUT_LENGTH];
    char number[INPUT_LENGTH];
} Contact;

Contact contact_array[100];

int add_new_entry();
int list_contacts();
void print_contact(const Contact *contact);
int read_from_csv(Contact contact_array[]);

int list_contacts() {
    int contact_count = read_from_csv(contact_array);

    for (int i = 0; i < contact_count; i++) {
        print_contact(&contact_array[i]);
    }

    return 0;
}

void print_contact(const Contact *contact) {
    printf("Name: %s\n", contact->name);
    printf("Address: %s\n", contact->address);
    printf("Email: %s\n", contact->email);
    printf("Number: %s\n", contact->number);
    printf("\n");
}


int add_new_entry() {
    FILE *fptr;

    fptr = fopen(FILENAME, "a");

    char name[INPUT_LENGTH] = "name_here";
    char address[INPUT_LENGTH] = "address_here";
    char email[INPUT_LENGTH] = "input_here";
    char number[INPUT_LENGTH] = "number_here";

    fprintf(fptr, "\n%s,%s,%s,%s", name, address, email, number);
    fclose(fptr);

    printf("\nSaved contact!\n\n");

    return 0;
}

int read_from_csv(Contact contact_array[]) {
    FILE *fptr;
    char buffer[(INPUT_LENGTH * 4 + 5)];
    int i = 0;

    fptr = fopen(FILENAME, "r");
    if (fptr == NULL) {
        printf("Could not open %s\n", FILENAME);
        return 0;
    }

    while (fgets(buffer, sizeof(buffer), fptr)) {
        char *p = buffer;
        while (*p == ' ' || *p == '\t' || *p == '\r' || *p == '\n') p++;
        if (*p == '\0') continue;

        char *new_line_pointer = strchr(buffer, '\n');
        if (new_line_pointer) *new_line_pointer = '\0';

        char *field = strtok(buffer, ",");
        int x = 0;

        while (field != NULL) {
            if (x == 0) {
                strncpy(contact_array[i].name, field, INPUT_LENGTH -1);
                contact_array[i].name[INPUT_LENGTH -1] = '\0';
            } else if (x == 1) {
                strncpy(contact_array[i].address, field, INPUT_LENGTH -1);
                contact_array[i].address[INPUT_LENGTH -1] = '\0';
            } else if (x == 2) {
                strncpy(contact_array[i].email, field, INPUT_LENGTH -1);
                contact_array[i].email[INPUT_LENGTH -1] = '\0';
            } else if (x ==  3) {
                strncpy(contact_array[i].number, field, INPUT_LENGTH -1);
                contact_array[i].number[INPUT_LENGTH -1] = '\0';
            }
            x++;
            field = strtok(NULL, ",");
        }

        i++;

        if (i >= 100) break;
    }

    fclose(fptr);

    return i;
}

int main(int argc, char *argv[]) {
    if (argc > 1) {
        FILENAME = argv[1];
    }
}