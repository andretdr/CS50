#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>
//#include <string.h>

void append(char name[], int n);

int main(int argc, char *argv[])
{
    typedef uint8_t BYTE;
    BYTE buffer[512] = {0};
    BYTE b = 0;
    BYTE *bufferint = malloc(512);

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
    const int namelength = 8;
    char filename[namelength] = {"000.jpg"}; // memleak error, syscall param openat(filename) ... I dint initialize this string
    FILE *photo = fopen(filename, "w");
    if (photo == NULL)
    {
        printf("Could not open file.\n");
        return 1;
    }

    // header check
    //while (fread(&b, 1, 1, image) != 0)
    while (fread(bufferint, 1, 512, image) != 0)
    {
        //buffer[blockcount] = b;
        //blockcount ++;
        //if (blockcount == 512)
        //{
            if ((bufferint[0] == 255) && (bufferint[1] == 216) && (bufferint[2] == 255) && (bufferint[3] >= 224) && (bufferint[3] <= 239))
            {
                printf("new file");
                if (n >= 0)
                {
                    fclose(photo);
                }
                sprintf(filename, "%i.jpg", n); // convert n to string, REMBER TO padd the zeros
                //printf("%s\n",filename);
                append(filename, namelength); // convert n to string, REMBER TO padd the zeros
                //printf("%s\n",filename);

                photo = fopen(filename, "w");
                if (photo == NULL)
                {
                    printf("Could not open file.\n");
                    return 1;
                }
                n++;
            }
            fwrite(&bufferint, 1, 1, photo);

          //  for (int i = 0; i < 512; i ++)
          //  {
          //      fwrite(&buffer[i], 1, 1, photo);
          //  }

          //  blockcount = 0;
    }

    //printf("exit");

    free(bufferint);
    fclose(photo);
    fclose(image);
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
    for (int i = 0; i < n - length -1; i++)
    {
        temp[i] = '0';
    }
    for (int i = 0; i < n ; i++)
    {
        temp[i + n - length -1] = name[i];
    }
    for (int i = 0; i < n ; i++)
    {
        name[i] = temp[i];
    }
}
