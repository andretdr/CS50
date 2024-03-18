#include <stdio.h>
#include <cs50.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
    FILE *file = fopen("phonebook.csv", "a"); //read, write, appending
    if (file == NULL) // anytime pointer is returned, check for NULL
    {
        return 1;
    }

    char *name = get_string("Name: ");
    char *number = get_string("Number: ");

    fprintf(file, "%s,%s\n", name, number);

    fclose(file);

}
