#include <stdio.h>
#include <cs50.h>
#include <stdbool.h>

bool selectionsort(int l[]);

int main(void)
{
    int list[] = {4,5,2,7,10,0,3,6,1,6,8,3};
    int len = sizeof(list);
    bool sorted = false;
    sorted = selectionsort(list);
}

bool selectionsort(int l[])
{

    printf("hi\n");
    return true;
}
