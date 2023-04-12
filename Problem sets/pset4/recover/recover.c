#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

typedef uint8_t BYTE;

int main(int argc, char *argv[])
{
    if (argc == 1)
    {
        printf("Usage: ./recover image\n");
        return 1;
    }

    FILE *file = fopen(argv[1], "r");
    if (!file)
    {
        return 1;
    }

    BYTE *data = malloc(512 * sizeof(BYTE));

    while (!(feof(file)))
    {
        fread(data, sizeof(BYTE), 512, file);
        if (data[0] == 0xff && data[1] == 0xd8 && data[2] == 0xff && (data[3] & 0xf0) == 0xe0)
        {
            // printf("break");
            break;
        }
    }

    int i = 0, flag = 0;
    // char outfile[10];
    // sprintf(outfile, "%03i.jpg", 0);
    // FILE *img = fopen("outfile", "w");
    // fwrite(data, sizeof(BYTE), 512, img);
    free(data);
    // free(outfile);
    // fclose(img);
    fseek(file, -512, SEEK_CUR);


    BYTE *check = malloc(512 * sizeof(BYTE));
    FILE *img;
    while (!(feof(file)))
    {
        fread(check, sizeof(BYTE), 512, file);
        char outfile[10];
        if (check[0] == 0xff && check[1] == 0xd8 && check[2] == 0xff && (check[3] & 0xf0) == 0xe0)
        {
            // FILE *c;
            // fclose(img);
            if (flag != 0)
            {
                // printf("00%d.jpg", i);
                // fclose(c);
                fclose(img);
                sprintf(outfile, "%03i.jpg", i);
                img = fopen(outfile, "w");
                fwrite(check, sizeof(BYTE), 512, img);
                i++;
            }
            else
            {
                // printf("000.jpg");
                flag = 1;
                // fclose(c);
                sprintf(outfile, "%03i.jpg", i);
                img = fopen(outfile, "w");
                fwrite(check, sizeof(BYTE), 512, img);
                i++;
            }
        }
        else
        {
            // printf("continue");
            fwrite(check, sizeof(BYTE), 512, img);
        }
    }
    free(check);
    fclose(img);
}