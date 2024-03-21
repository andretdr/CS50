#include <stdio.h>;

int main(void)
{
    int *list = malloc(3 * sizeof(int)); // int is 4 bytes. BYTE is 1
    if (list == NULL)
    {
        return 1;
    }

    list[0]

    for (int i = 0; i < 3; i++)
    {
        printf("list", list[i]);
    }
}
