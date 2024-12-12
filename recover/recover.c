// recover JPEG from a memory card by HASSAN ZAKIE

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    // Accept a single comand-line argument
    if (argc != 2)
    {
        printf("Usage: ./recover FILE\n");
        return 1;
    }

    // Open the memory card
    FILE *card = fopen(argv[1], "r");
    if (card == NULL)
    {
        printf("Could not open %s.\n", argv[1]);
        return 2;
    }

    // Setting up parameter
    uint8_t buffer[512];    // Create a buffer for a block of data
    int jpeg = 0;           // counting jpeg
    char filename[8] = {0}; // string for filename
    FILE *output = NULL;

    // While there's still data left to read from the memory card
    while (fread(buffer, 1, 512, card) == 512)
    {
        // Check if JPEG is found
        if (buffer[0] == 0xFF && buffer[1] == 0xD8 && buffer[2] == 0xFF &&
            (buffer[3] & 0xF0) == 0xE0)
        {
            // close card if JPEG is found before and written into ###.jpg
            if (output != NULL)
            {
                fclose(output);
            }
            sprintf(filename, "%03d.jpg", jpeg++);

            // Open a new card (output) file for wrinting jpeg
            output = fopen(filename, "w");
        }

        // Create JPEGs from the data
        if (output != NULL)
        {
            fwrite(buffer, 1, 512, output);
        }
    }

    // Close last opened card
    if (output != NULL)
    {
        fclose(output);
    }

    // Close input file
    fclose(card);

    return 0;
}
