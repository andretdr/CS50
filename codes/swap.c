#include <stdio.h>
#include <stdlib.h>
#include <cs50.h>

void swap (int *a, int *b);

int main(void)
{
    int x = get_int("gimme X: ");
    int y = get_int("gimme Y: ");
    swap (&x, &y);

    printf("X is now %i\n",x);
    printf("Y is now %i\n",y);

}

void swap (int *a, int *b) // address of a, address of b
{
    int temp = *a; //*a means goto address of a
    *a = *b;
    *b = temp;
}
