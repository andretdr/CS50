#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    //typedef *char[512] block;
    //typedef int64_t BYTE64; //64 * 8 = 512
    int *buffer = malloc(8 * int64_t); // buffer is 512 bytes

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

    //read 512 blocks at a time
    // if first 4 bytes match pattern,
        // output to new file until the next 512 block
        // until EOF

    //read 512 blocks at a time
    while (fread(buffer, sizeof(*buffer), 1, image) != 0)
    {
        printf("",buffer[0]);
    }


    free(buffer);
    return 0;
}
