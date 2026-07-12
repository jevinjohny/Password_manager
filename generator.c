#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <time.h>
#include "generator.h"

#define MIN_LENTGH 6

#define MAX_LENTGH 16

extern int database_count;

void generator(void)
{
    int i = 0;

    int j = 5;

    int size = 0;

    size = password_length_validation();

    printf("Generated Passwords: \n");

    while (i < size)
    {
        char str[BUFFSIZE];

        int len = 0;

        generate_password(str, &len, size);

        shuffler(str, size);

        str[len] = '\0';

        printf("\033[1;32m"); // Bright Green

        printf("%-16s\n", str);

        printf("\033[0m"); // Reset color

        i++;
    }
}

int password_length_validation(void)
{
    int size;

    while (1)
    {
        printf("Enter password length (6-16):");

        if (scanf(" %d", &size) != 1)
        {
            printf("invalid input\n");

            while (getchar() != '\n')
                ;

            continue;
        }
        if (size < MIN_LENTGH)
        {
            printf("Minimum length is %d try again\n", MIN_LENTGH);

            continue;
        }
        else if (size > MAX_LENTGH)
        {
            printf("maximum length is %d\n", MAX_LENTGH);

            continue;
        }
        break;
    }
    while (getchar() != '\n')
        ;

    return size;
}

void generate_password(char *str, int *len, int size)
{
    int option;

    str[(*len)] = random_lowercase_letters();

    (*len)++;

    str[(*len)] = random_uppercase_letters();

    (*len)++;

    char chr = random_special_characters();

    str[*len] = chr;

    (*len)++;

    str[*len] = random_digits();

    (*len)++;

    while ((*len) < size)
    {
        option = (rand() % RANDOMTYPE);

        switch (option)
        {
        case SPLCHAR:
        {
            char ch = random_special_characters();

            str[*len] = ch;

            (*len)++;

            break;
        }
        case NUMBER:
        {
            str[*len] = random_digits();

            (*len)++;

            break;
        }
        case UPPERCASE:
        {
            str[*len] = random_uppercase_letters();

            (*len)++;

            break;
        }
        case LOWERCASE:
        {
            str[*len] = random_lowercase_letters();

            (*len)++;

            break;
        }
        }
    }
}

char random_digits(void)
{
    return ('0' + (rand() % 10));
}

char random_special_characters(void)
{
    char special_characters[] = "!@#$%^&*()_+-={}[]:<>?,./";

    int index = (rand() % (sizeof(special_characters) - 1));

    return special_characters[index];
}

char random_lowercase_letters(void)
{
    char alph[] = "abcdefghijklmnopqrstuvwxyz";

    int index = (rand() % (sizeof(alph) - 1));

    return alph[index];
}

char random_uppercase_letters(void)
{
    char alph[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

    int index = (rand() % (sizeof(alph) - 1));

    return alph[index];
}

// Fisher–Yates shuffle
void shuffler(char *str, int size)
{
    int i = size - 1;

    while (i >= 0)
    {
        int j = rand() % (i + 1);

        char temp = str[i];

        str[i] = str[j];

        str[j] = temp;

        i--;
    }
}
/*
int get_keyword(char *str, int size)
{
    int len;

    while (1)
    {
        printf("Pls provide a keyword in lowercase \n");

        fgets(str, BUFFSIZE, stdin);

        str[strcspn(str, "\n")] = '\0';

        if (strchr(str, ' ') != NULL)
        {
            printf("Spaces not allowed\n");

            continue;
        }

        len = strlen(str);

        if (len == 0)
        {
            printf("keyword should not be empty\n");

            continue;
        }

        if (len > size - 2)
        {
            printf("keyword should be less than or equal to %d\n", size - 2);

            continue;
        }

        break;
    }

    return len;
}
*/




