#include <stdio.h>
#include "upload.h"
#include "tea.h"
#include <string.h>

extern int saved;

void upload(data *database, int *count)
{
    FILE *fp = fopen("password.txt", "r");

    if (fp == NULL)
    {
        printf("\nFile failed to open\n");

        return;
    }

    fseek(fp, 0, SEEK_END);

    if (ftell(fp) == 0)
    {
        printf("\nFile is empty\n");

        fclose(fp);

        return;
    }

    fseek(fp, 0, SEEK_SET);

    saved = 1;

    int scan;

    while (*count < MAXDATA && fscanf(fp, " %49[^;];%49[^;];%49[^\r\n]",
                                      database[*count].website,
                                      database[*count].username,
                                      database[*count].password) == 3)
    {
        if (saved)
        {
            unsigned int block[2];

            int nblocks = (strlen(database[*count].password) + 15) / 16; // hex length of one block

            char decstr[50] = {0}; // after decrypting automatically null character will be there

            for (int j = 0; j < nblocks; j++)
            {
                sscanf(database[*count].password + (j * 16), "%8X%8X", &block[0], &block[1]);

                tea_decrypt(block, tea_key);

                memcpy(decstr + (j * 8), block, 8);
            }
            strcpy(database[*count].password, decstr);
        }
        (*count)++;
    }

    fclose(fp);

    if ((*count == 0))
    {
        printf("No data found\n");

        return;
    }
    printf("\033[1;32m"); // Bright Green

    printf("Upload finished\n");

    printf("\033[0m"); // Reset
}
