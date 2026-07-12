#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define BUFFSIZE 50
#define RANDOMTYPE 4


enum
{
    SPLCHAR,
    NUMBER,
    UPPERCASE,
    LOWERCASE
};

int password_length_validation();
int get_keyword(char *str,int size);
char random_digits(void);
void generate_password(char *str,int *len,int size);
char random_special_characters(void);
void shuffler(char *str, int size);
void generator(void);
char random_lowercase_letters(void);
char random_uppercase_letters(void);

