#include <stdio.h>
#include <cs50.h>

int main(void)
{
//    const int size = 6;
    int size;
    do
    {
        size = get_int ("gimme size more then 0 :");
    }
    while (size<1);


    for (int i = 0; i < size; i++)
    {

        for (int j = 0; j < size; j++)
        {
        printf("#");
        }
    printf("\n");
    }


}
