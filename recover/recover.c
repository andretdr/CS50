#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

int main(int argc, char *argv[])
{
    //typedef *char[512] block;
//    typedef uint8_t BYTE;
//    BYTE b;
    int *buffer = malloc(1); // buffer is 512 bytes

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
//    while (fread(buffer, sizeof(*buffer), 1, image) != 0)
//

for (int i = 0; i < 10000; i++)
{
fread(buffer, 1, 1, image);
        printf("%i \n", *buffer);
}


    free(buffer);
    return 0;
}
