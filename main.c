#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <time.h>
#include "generator.h"
#include "banner.h"
#include "load.h"
#include "upload.h"
#include "display.h"
#include "save.h"
#include "strength.h"
#include "search.h"

int database_count = 0;

int saved = 0;

data database[MAXDATA];

int main()
{
    srand(time(NULL));

    banner();

    int option;

    while (1)
    {

        printf("=============================================================================================\n");

        printf("| %-3d. %-65s                    |\n", 1, "Generate Password");
        printf("| %-3d. %-65s                    |\n", 2, "Load Password");
        printf("| %-3d. %-65s                    |\n", 3, "Display Database");
        printf("| %-3d. %-65s                    |\n", 4, "Upload Database");
        printf("| %-3d. %-65s                    |\n", 5, "Save Database");
        printf("| %-3d. %-65s                    |\n", 6, "Strength Checker");
        printf("| %-3d. %-65s                    |\n", 7, "Search Password");
        printf("| %-3d. %-65s                    |\n", 8, "Delete Password");
        printf("| %-3d. %-65s                    |\n", 9, "Exit");

        printf("=============================================================================================\n");

        printf("\nEnter your choice: ");

        scanf("%d", &option);

        switch (option)
        {
        case 1:
        {
            generator();

            break;
        }
        case 2:
        {
            load_password(database);

            break;
        }
        case 3:
        {
            display(database, database_count);

            break;
        }
        case 4:
        {
            upload(database, &database_count);

            break;
        }
        case 5:
        {
            save_password(database);

            break;
        }
        case 6:
        {
            strength_checker();

            break;
        }
        case 7:
        {
            search(database, database_count);

            break;
        }
        case 8:
        {
            // delete();

            break;
        }
        case 9:
        {
            return 0;
        }
        default:
        {
            printf("Enter the correct option\n");
        }
        }
        printf("\n");
    }
}