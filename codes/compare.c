#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int x = get_int("gimme number :");
    int y = get_int("gimme another :");

    if (x < y)
    {
        printf ("X is less then Y\n");
    }
    else
        if (x > y)
        {
            printf ("X is more then Y\n");
        }
        else
        {
            printf ("They are equal\n");
        }


}
