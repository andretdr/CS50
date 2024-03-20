#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>

int main(int argc, char *argv[])
{

    typedef uint8_t BYTE;
    BYTE buffer[512];
    BYTE b = 0;

//    int *header = malloc(1); // buffer is 1 bytes
//    int *body = malloc(508); // body is 508 bytes


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
    int blockcount = 0;
    int n = 0;

    // header check
    while (fread(&b, 1, 1, image) != 0)
    {
        buffer[blockcount] = b;
        blockcount ++;
        if (blockcount == 512)
        {
            if ((buffer[0] == 255) && (buffer[1] == 216) && (buffer[2] == 255) && (buffer[3] >= 224) && (buffer[3] <= 239))
            {
                n++;
                opennew = true;
                fclose(filename);


            }

            for (int i = 0; i < 512; i ++)
            {
                fwrite(buffer[i], 1, 1, filename);
            }


                    if (openew)
        {
            if (n > 1) // if not the 1st jpg, then close the prev file
            {

            }
                // save to new file
                sprintf(filename, "0%i".jpg, n); // convert n to string, REMBER TO padd the zeros

                FILE *photo = fopen(str, "w");

        }





            blockcount = 0;
        }
    }





  /*      char filename[8];

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
                        n++;
                        opennew = true; //open and write newfile
                    }
                }
            }
        }
        if (openew)
        {
            if (n > 1) // if not the 1st jpg, then close the prev file
            {
                fclose(filename);
            }
                // save to new file
                sprintf(filename, "0%i".jpg, n); // convert n to string, REMBER TO padd the zeros

                FILE *photo = fopen(str, "w");

        }




*/



//    free(header);
//    free(body);
    return 0;
}
