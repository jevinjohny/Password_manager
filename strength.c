#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include "strength.h"
#include <stdio_ext.h>

void strength_checker()
{
    char str[50];

    printf("enter the password to check the strength:");

    scanf(" %49[^\n]", str);

    __fpurge(stdin);
    
    if (strlen(str)>40)
    {
        printf("\nMaximum password length is 40 pls try again\n");

        return;
    }

    int points = 0;

    int isup = 0, islow = 0, isspecial = 0, isdigi = 0;

    for (int i = 0; str[i] != '\0'; i++)
    {
        if (isup == 0 && isupper(str[i]))
        {
            points++;

            isup = 1;
        }
        else if (islow == 0 && islower(str[i]))
        {
            points++;

            islow = 1;
        }
        else if (isspecial == 0 && !isalnum(str[i]) && !isspace(str[i]))
        {
            points++;

            isspecial = 1;
        }
        else if (isdigi < 2 && isdigit(str[i]))
        {
            points++;

            isdigi++;
        }
    }

    printf("points is %d\n", points);

    if (points == 5)
    {
        printf("Password strength : ");

        printf("\033[1;32m"); // Bright Green

        printf("Very Strong\n");

        printf("\033[0m"); // Reset color
    }
    else if (points == 4)
    {
        printf("Password strength : ");

        printf("\033[1;32m"); // Bright Green

        printf("Strong\n");

        printf("\033[0m"); // Reset color
    }
    else if (points == 3)
    {
        printf("Password strength : ");

        printf("\033[1;33m");

        printf("Medium\n");

        printf("\033[0m");
    }
    else if (points == 2)
    {
        printf("Password strength : ");

        printf("\033[1;31m");

        printf("Weak\n");

        printf("\033[0m");
    }
    else
    {
        printf("Password strength : ");

        printf("\033[1;31m");

        printf("Very Weak\n");

        printf("\033[0m");
    }
}
