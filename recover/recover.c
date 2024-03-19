#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    //typedef *char[512] block;


    if (argc != 2)
    {
        printf("Usage: ./recover image\n");
        return 1;
    }

    // Open file
    FILE *image = fopen(argv[1], "r");
    if (input == NULL)
    {
        printf("Could not open file.\n");
        return 1;
    }






    return 0;
}
