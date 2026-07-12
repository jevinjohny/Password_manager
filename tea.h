#ifndef TEA_H
#define TEA_H

extern const unsigned int tea_key[4];

void tea_encrypt(unsigned int *v, const unsigned int *key);

void tea_decrypt(unsigned int *v, const unsigned int *key);

void password_wrapper(char *orgpass, unsigned int *block);

#endif