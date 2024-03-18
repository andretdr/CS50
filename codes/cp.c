#include <stdio.h>
#include <stdint.h>

typedef uint8_t BYTE;

int main(int argc, char *argv[]) // cp src destination
{
    FILE *src = fopen(argv[1], "rb"); //read binary, not strings
    FILE *dst = fopen(argv[2], "wb");

    BYTE b;

    while (fread(&b, sizeof(b), 1, src) != 0) //fread each byte for you, reading it byte by byte to address of b, 1 byte at a time. while still have bytes to read
    {
        fwrite(&b, sizeof(b), 1, dst);
    }

    fclose(dst);
    fclose(src);

}
