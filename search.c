#include <stdio.h>
#include <string.h>
#include "search.h"
#include "display.h"
#include <stdio_ext.h>

void search(data *database, int count)
{
    char str[50];

    printf("Enter the website\n");

    scanf(" %49[^\n]", str);

    __fpurge(stdin);

    if (strlen(str)>40)
    {
        printf("\nMaximum length of website is 40 pls try again\n");

        return;
    }

    int flag = 1;

    int j = 0;

    for (int i = 0; i < count; i++)
    {
        if (strstr(database[i].website, str) != NULL)
        {
            if (flag)
            {
                printf("\n");

                printf("+----+--------------------------------+------------------------------+----------------------+\n");

                printf("| %-2s | %-30s | %-28.30s | %-20.30s |\n", "No", "Website", "Username", "Password");

                printf("+----+--------------------------------+------------------------------+----------------------+\n");

                flag = 0;
            }
            printf("| %-2d | %-30.30s | %-28.30s | ", j + 1, database[i].website, database[i].username);

            printf("\033[1;32m"); // Bright Green

            printf("%-20.30s ", database[i].password);

            printf("\033[0m"); // Reset color

            printf("|\n");

            printf("+----+--------------------------------+------------------------------+----------------------+\n");

            j++;
        }
    }
    if (flag)
    {
        printf("No data found...\n");
    }
}
