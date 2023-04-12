// Modifies the volume of an audio file

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

// Number of bytes in .wav header
const int HEADER_SIZE = 44;

int main(int argc, char *argv[])
{
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

    float factor = atof(argv[3]);

    uint8_t header[HEADER_SIZE];

    for (int i = 0; i < HEADER_SIZE; i++)
    {
        fread(&header[i], sizeof(uint8_t), 1, input);
        fwrite(&header[i], sizeof(uint8_t), 1, output);
    }

    // printf("%ld\n", ftell(input));

    int16_t buffer;

    while (fread(&buffer, sizeof(int16_t), 1, input))
    {
        int16_t a = buffer * factor;
        fwrite(&a, sizeof(int16_t), 1, output);
    }

    // Close files
    fclose(input);
    fclose(output);
}
