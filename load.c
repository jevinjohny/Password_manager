#include <stdio.h>
#include "load.h"
#include <stdio_ext.h>
#include <string.h>
#include <stdlib.h>

extern int database_count;

int getwebsite(data *entry)
{
    printf("Enter the website name\n");

    char str[50];

    scanf(" %49[^\n]", str);

    __fpurge(stdin);

    if (strlen(str) > 40)
    {
        printf("\nMaximum website length is 40 pls try again\n");

        return 1;
    }
    else if (strstr(str, ";") != NULL)
    {
        printf("\nWebsite name should not contain ';' pls try again\n");

        return 1;
    }
    strcpy(entry->website, str);

    return 0;
}

int getusername(data *entry)
{
    printf("Enter the username\n");

    char str[50];

    scanf(" %49[^\n]", str);

    __fpurge(stdin);

    if (strlen(str) > 40)
    {
        printf("\nMaximum username length is 40 pls try again\n");

        return 1;
    }
    else if (strstr(str, ";") != NULL)
    {
        printf("\nUsername name should not contain ';' pls try again\n");

        return 1;
    }
    strcpy(entry->username, str);

    return 0;
}

int getpassword(data *entry)
{
    printf("Enter the password\n");

    char str[50];

    scanf(" %49[^\n]", str);

    __fpurge(stdin);

    if (strlen(str) > 40)
    {
        printf("\nMaximum password length is 40 pls try again\n");

        return 1;
    }
    else if (strstr(str, ";") != NULL)
    {
        printf("\nPassword should not contain ';' pls try again\n");

        return 1;
    }
    strcpy(entry->password, str);

    return 0;
}

void load_password(data *entry)
{
    if (database_count >= MAXDATA)
    {
        printf("Database is full....\n");

        return;
    }

    if (getwebsite(&entry[database_count]))
    {
        return;
    }

    if (getusername(&entry[database_count]))
    {
        return;
    }

    if (getpassword(&entry[database_count]))
    {
        return;
    }

    database_count++;

    printf("\033[1;32m"); // Bright Green

    printf("Password added successfully...\n");

    printf("\033[0m"); // Reset Green
}