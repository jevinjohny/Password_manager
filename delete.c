#include <stdio.h>
#include "load.h"
#include "delete.h"
#include <stdio_ext.h>
#include <string.h>
#include <stdlib.h>
#include "search.h"

extern int database_count;

void delete_password(data *entry)
{
    char str[50];

    printf("Enter the website\n");

    scanf(" %49[^\n]", str);

    __fpurge(stdin);

    if (strlen(str) > 40)
    {
        printf("\nMaximum length of website is 40 pls try again\n");

        return;
    }

    int flag = 1;

    int j = 0;

    int ind = 0;

    int arr[database_count];

    for (int i = 0; i < database_count; i++)
    {
        if (strstr(entry[i].website, str) != NULL)
        {
            arr[ind++] = j + 1;
            if (flag)
            {
                printf("\n");

                printf("+----+--------------------------------+------------------------------+----------------------+\n");

                printf("| %-2s | %-30s | %-28.30s | %-20.30s |\n", "No", "Website", "Username", "Password");

                printf("+----+--------------------------------+------------------------------+----------------------+\n");

                flag = 0;
            }
            printf("| %-2d | %-30.30s | %-28.30s | ", j + 1, entry[i].website, entry[i].username);

            printf("\033[1;32m"); // Bright Green

            printf("%-20.30s ", entry[i].password);

            printf("\033[0m"); // Reset color

            printf("|\n");

            printf("+----+--------------------------------+------------------------------+----------------------+\n");

            j++;
        }
    }
    if (flag)
    {
        printf("No data found...\n");
        return;
    }

    data ptr;

    int option;

    printf("Enter the data to be deleted\n");

    int found = 0;

    while (1)
    {
        scanf(" %d", &option);

        __fpurge(stdin);

        for (int i = 0; i < ind; i++)
        {
            if (arr[i] == option)
            {
                found = 1;

                break;
            }
        }

        if (found)
        {
            break;
        }
        else
        {
            printf("pls give the correct option\n");
        }
    }

    for (int i = option - 1; i < database_count - 1; i++)
    {
        ptr = entry[i];

        entry[i] = entry[i + 1];

        entry[i + 1] = ptr;
    }

    --database_count;

    printf("\033[1;32m"); // Bright Green

    printf("Password Deleted Successfully\n");

    printf("\033[0m"); // Reset color
}
