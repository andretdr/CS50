#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

int main(void)
{
    int numbers[] = {20, 100, 10, 5, 100, 1, 50};

    int n = get_int("gimme number: ");
    int i = 0;
    int j = sizeof(numbers);
    bool found = false;

    while ((i < j) && (!found))
    {
        if (numbers[i] == n)  // for string comparison, strcmp(string1,string2) == 0 if equals, 1 if string1 > string2, 2 if string1 < string2
        {
            found = true;
        }
        i++;
    }

    if (found)
    {
        printf("found\n");
        return 0;
    }
    else
    {
        printf("not Found\n");
        return 1;
    }
}
