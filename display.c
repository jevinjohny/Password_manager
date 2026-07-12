#include <stdio.h>
#include <string.h>
#include "save.h"
#include "display.h"

void display(data *database, int count)
{
    if (count == 0)
    {
        printf("\nNO DATA FOUND\n");

        return;
    }

    printf("\n");

    printf("+----+--------------------------------+------------------------------+----------------------+\n");

    printf("| %-2s | %-30s | %-28.30s | %-20.30s |\n", "No", "Website", "Username", "Password");

    printf("+----+--------------------------------+------------------------------+----------------------+\n");

    for (int i = 0; i < count; i++)
    {
        printf("| %-2d | %-30.30s | %-28.30s | ", i + 1, database[i].website, database[i].username);

        printf("\033[1;32m"); // Bright Green

        printf("%-20.30s ", database[i].password);

        printf("\033[0m"); // Reset color

        printf("|\n");

        printf("+----+--------------------------------+------------------------------+----------------------+\n");
    }
}
