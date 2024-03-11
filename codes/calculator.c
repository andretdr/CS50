#include <stdio.h>
#include <cs50.h>

int add(int x, int y);
int subtract (int x, int y);

int main(void)
{
    int x = get_int ("x: ");
    int y = get_int ("y: ");

    printf("x+y = %i\n", add(x,y));
    printf("x-y = %i\n", subtract(x,y));
}

int add(int x, int y)
{
    return (x+y);
}

int subtract (int x, int y)
{
    return (x-y);
}


