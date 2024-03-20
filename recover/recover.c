#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

int main(int argc, char *argv[])
{
    //typedef *char[512] block;
//    typedef uint8_t BYTE;
//    BYTE b;
    int *headercheck = malloc(4); // buffer is 4 bytes
    int *body = malloc(508); // body is 508 bytes

    if (argc != 2)
    {
        printf("Usage: ./recover image\n");
        return 1;
    }

    // Open file
    FILE *image = fopen(argv[1], "r");
    if (image == NULL)
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
        fread(buffer, 1, 1, image);
        if ((buffer>) && (buffer<))
        {
            printf("%i \n", *buffer);

        }
        fread(body, 508, 1, image);
    }


    free(buffer);
    free(body);
    return 0;
}
