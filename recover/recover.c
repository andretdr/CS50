#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>
//#include <string.h>

void append(char name[], int n);

int main(int argc, char *argv[])
{
    typedef uint8_t BYTE;
    BYTE buffer[512];
    BYTE b = 0;

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

    int blockcount = 0;
    int n = 0;
    int namelength = 7;
    char filename[namelength];
    FILE *photo = fopen("001.jpg", "w");

    // header check
    while (fread(&b, 1, 1, image) != 0)
    {
        buffer[blockcount] = b;
        blockcount ++;
        if (blockcount == 512)
        {
            if ((buffer[0] == 255) && (buffer[1] == 216) && (buffer[2] == 255) && (buffer[3] >= 224) && (buffer[3] <= 239))
            {
                if (n > 0)
                {
                    fclose(photo);
                }
                n++;

                sprintf(filename, "%i.jpg", n); // convert n to string, REMBER TO padd the zeros
                append(filename, namelength); // convert n to string, REMBER TO padd the zeros
                //printf(filename);

                //printf("%s \n",filename);
                photo = fopen(filename, "w");

            }

            for (int i = 0; i < 512; i ++)
            {
                fwrite(&buffer[i], 1, 1, photo);
            }

            blockcount = 0;
        }
    }
    return 0;
}

void append(char name[], int n)
{
    char temp[n];
    int length = 0;
    while (name[length] != '\0')
    {
        length++;
    }
    for (int i = 0; i < n - length; i++)
    {
        temp[i] = '0';
    }
    for (int i = 0; i < n ; i++)
    {
        temp[i + n - length] = name[i];
    }
    for (int i = 0; i < n ; i++)
    {
        name[i] = temp[i];
    }
}
