#include <stdio.h>
#include <cs50.h>

int main(void)
{
    string s = get_string("s: "); // strings is char*, therefore is a pointer, therefore it stores an address, not the value itself
    string t = get_string("t: ");

    if (s* == *t)
    {
        printf("Same\n");
    }
    else
    {
        printf("Different\n");
    }

    printf("%p\n",s); // show address
    printf("%p\n",t); // show address
}
