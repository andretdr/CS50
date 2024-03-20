#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>

int main(int argc, char *argv[])
{

    BYTE b[4] = {0, 0, 0, 0};
    int *header = malloc(1); // buffer is 1 bytes
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

    bool opennew = false;
    int n = 0;

    // header check
    while (fread(header, 1, 1, image) != 0)
    {
        if (*header == 255)
        {
            b[0] = *header;
            if ((fread(header, 1, 1, image) != 0) && (*header == 216))
            {
                b[1] = *header;
                if ((fread(header, 1, 1, image) != 0) && (*header == 255))
                {
                    b[2] = *header;
                    if ((fread(header, 1, 1, image) != 0) && (*header >= 224) && (*header <= 239))
                    {
                        b[3] = *header;
                        opennew = true; //open and write newfile
                    }
                }
            }
        }


    }


    free(header);
    free(body);
    return 0;
}
