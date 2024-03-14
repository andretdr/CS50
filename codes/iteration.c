#include <cs50.h>
#include <stdio.h>

void draw(int n);

int main(void)
{
    int h = get_int("Height: ");
    draw(h);
}

void draw(int n)
{

    if (n > 0)
    {
        draw(n - 1);
    }

    for (int i = 0; i < n; i++)
    {
        printf("#");
    }
    print("\n");


}
