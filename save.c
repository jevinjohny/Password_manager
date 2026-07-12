#include <stdio.h>
#include "save.h"
#include "tea.h"
#include <stdlib.h>
#include <string.h>

extern int database_count;

extern int saved;

void save_password(data *entry)
{
    FILE *fp = fopen("password.txt", "w");

    if (!fp)
    {
        printf("file open failed\n");

        return;
    }

    if (database_count==0)
    {
        printf("\nDatabase is empty\n");
        return;
    }

    for (int i = 0; i < database_count; i++)
    {
        fprintf(fp, "%s;%s;", entry[i].website, entry[i].username);

        unsigned int v[2];

        int nblocks = (strlen(entry[i].password) + 7) / 8;

        char buffer[8];

        for (int j = 0; j < nblocks; j++)
        {
            memset(buffer, 0, 8);

            int n = strlen(entry[i].password) - (j * 8);

            if (n < 8)
                memcpy(buffer, entry[i].password + (j * 8), n);
            else
                memcpy(buffer, entry[i].password + (j * 8), 8);

            password_wrapper(buffer, v);

            tea_encrypt(v, tea_key);

            fprintf(fp, "%08X%08X", v[0], v[1]);
        }
        fprintf(fp, "\n");
    }
    
    fseek(fp, 0, SEEK_SET);

    fclose(fp);

    printf("\033[1;32m"); // Bright Green

    printf("Database Saved...\n");

    printf("\033[0m"); // Reset Green
}
