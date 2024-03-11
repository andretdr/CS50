#include <stdio.h>
#include <cs50.h>

int main (void)
{
    int totalBricks;
    do
        {
            totalBricks = get_int ("give me a number higher then 0 please! ");
        }
    while (totalBricks < 1);

    for (int i = 0; i < totalBricks; i++) // columns
    {


        for (int j = 0; j < 2*totalBricks+2; j++) // rows
        {
            int blanks = totalBricks-i-1; // number of blanks on this row
            int bricks = totalBricks - blanks;
            if ((j < blanks) || ((j-totalBricks-1) > bricks) || (j == totalBricks) || (j == totalBricks +1))
                printf (" ");
            else
                printf ("#");

        }
        printf ("\n");
    }

}
