#include <stdio.h>
#include <cs50.h>

int main(void)
{
//    const int size = 6;
    const int size = get_int ("gimme size :");

    for (int i = 0; i < size; i++)
    {

        for (int j = 0; j < size; j++)
        {
        printf("#");
        }
    printf("\n");
    }


}
