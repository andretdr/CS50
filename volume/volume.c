// Modifies the volume of an audio file

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

// Number of bytes in .wav header
const int HEADER_SIZE = 44;
typedef uint8_t BYTE;

int main(int argc, char *argv[])
{

    BYTE b;

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
        fread(&b, sizeof(b), 1, src);
        fwrite(&b, sizeof(b), 1, dst);
    }

    while (fread(&b, sizeof(b), 1, src) != 0) //fread each byte for you, reading it byte by byte to address of b, 1 byte at a time. while still have bytes to read
    {
        
        fwrite(&b, sizeof(b), 1, dst);
    }




    // TODO: Read samples from input file and write updated data to output file

    // Close files
    fclose(input);
    fclose(output);
}
