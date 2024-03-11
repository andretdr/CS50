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

    for (int i = 0; i < bricks; i++) // columns
    {


        for (int j = 0; j < bricks; j++) // rows
        {
            int n = i+1; // number of bricks on this row
            if (j < bricks)
            printf (" ");
            else
            printf ("#");
        }
        printf ("\n");
    }

}
