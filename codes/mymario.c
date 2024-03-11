#include <stdio.h>
#include <cs50.h>

int main (void)
{
    int bricks;
    do
        {
            bricks = get_int ("give me a number higher then 0 please! ");
        }
    while (bricks < 1);

    for (int i = 0; i < 2*bricks+2; i++) // columns
    {


        for (int j = 0; j < bricks; j++) // rows
        {
            int blanks = bricks-i-1; // number of blanks on this row
            if (j < blanks)
                printf (" ");
            else
                printf ("#");

        }
        printf ("\n");
    }

}
