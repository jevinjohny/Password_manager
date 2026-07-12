#ifndef LOAD_H
#define LOAD_H
#include <stdio.h>

#define MAXDATA 100

typedef struct
{
    char website[50];
    char username[50];
    char password[50];
} data;

void load_password(data *entry);

int getwebsite(data *entry);

int getusername(data *entry);

int getpassword(data *entry);

#endif