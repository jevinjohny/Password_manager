#include <stdio.h>
#include <string.h>
#include "tea.h"
#include "load.h"

const unsigned int tea_key[4] = {0x12345678, 0x9ABCDEF0, 0xA1B2C3D4, 0x56789ABC};

void password_wrapper(char *orgpass, unsigned int *block)
{
    memset(block, 0, 8);

    memcpy(block, orgpass, strlen(orgpass));
}

void tea_encrypt(unsigned int *v, const unsigned int *key)
{
    unsigned int left = v[0];

    unsigned int right = v[1];

    int delta = 0x9E3779B9;

    int sum = 0;

    for (int i = 0; i < 32; i++)
    {
        sum = sum + delta;

        left = left + (((right << 4) + key[0]) ^ (right + sum) ^ ((right >> 5) + key[1]));

        right = right + (((left << 4) + key[2]) ^ (left + sum) ^ ((left >> 5) + key[3]));
    }

    v[0] = left;

    v[1] = right;
}

void tea_decrypt(unsigned int *v, const unsigned int *key)
{
    unsigned int left = v[0];

    unsigned int right = v[1];

    unsigned int delta = 0x9E3779B9;

    unsigned int sum = delta << 5;

    for (int i = 0; i < 32; i++)
    {
        right = right - (((left << 4) + key[2]) ^ (left + sum) ^ ((left >> 5) + key[3]));

        left = left - (((right << 4) + key[0]) ^ (right + sum) ^ ((right >> 5) + key[1]));

        sum = sum - delta;
    }

    v[0] = left;

    v[1] = right;
}