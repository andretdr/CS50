#include <stdio.h>
#include <cs50.h>

int add(int a, int b);
int subtract (int a, int b);
float divide (int a, int b);

int main(void)
{
    int x = get_int ("x: ");
    int y = get_int ("y: ");

    printf("x+y = %i\n", add(x,y));
    printf("x-y = %i\n", subtract(x,y));
    printf("x/y = %f\n", divide(x,y));
}

int add(int a, int b)
{
    return (a+b);
}

int subtract (int a, int b)
{
    return (a-b);
}

float divide (int a, int b)
{
    return ((float)a/(float)b);
}

