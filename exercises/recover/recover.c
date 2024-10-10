#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

unsigned char buffer[512];
int jpeg_count = 0;
char filename[8];
int reading = 0;
FILE *img;

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("Usage: ./recover IMAGE\n");
        return 1;
    }

    // Open forensic file
    FILE *file = fopen(argv[1], "r");
    if (file == NULL)
    {
        printf("Could not open file.\n");
    }

    while (fread(buffer, 1, 512, file) == 512)
    {
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0)
        {
            if (reading == 1)
            {
                int fclose(FILE *img);
            }

            sprintf(filename, "%03i.jpg", jpeg_count);
            img = fopen(filename, "w");
            jpeg_count++;

            reading = 1;

            fwrite(buffer, 1, 512, img);
        }
        else if (reading == 1)
        {
            fwrite(buffer, 1, 512, img);
        }
    }
}