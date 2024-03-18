// Modifies the volume of an audio file

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

// Number of bytes in .wav header
const int HEADER_SIZE = 44;
typedef uint8_t BYTE;
typedef int16_t BYTE16;

int main(int argc, char *argv[])
{

    BYTE b;
    BYTE16 bb;

    // Check command-line arguments
    if (argc != 4)
    {
        printf("Usage: ./volume input.wav output.wav factor\n");
        return 1;
    }

    // Open files and determine scaling factor
    FILE *input = fopen(argv[1], "r");
    if (input == NULL)
    {
        printf("Could not open file.\n");
        return 1;
    }

    FILE *output = fopen(argv[2], "w");
    if (output == NULL)
    {
        printf("Could not open file.\n");
        return 1;
    }

    float factor = atof(argv[3]); // converts the string into a float number. the factor to multiply by

    // Copy header from input file to output file//
    for (int i = 0, n = HEADER_SIZE; i < n; i++) // for each byte up to 44
    {
        fread(&b, sizeof(b), 1, input);
        fwrite(&b, sizeof(b), 1, output);
    }


    // TODO: Read samples from input file and write updated data to output file
    while (fread(&bb, sizeof(bb), 1, input) != 0) //fread each byte for you, reading it byte by byte to address of b, 1 byte at a time. while still have bytes to read
    {
        BYTE16 temp = bb * 2;
        fwrite(&bb, sizeof(bb), 1, output);
    }






    // Close files
    fclose(input);
    fclose(output);
}
