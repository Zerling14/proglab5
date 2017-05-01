#ifndef STRINGS_H
#define STRINGS_H
#include <stdlib.h>

int slen(char *str);

char *stok(char *str, const char *delim);

size_t sspn(const char *str, const char *sym);

int scmp(const char *string1, const char *string2);

char *scpy(char *destptr, const char *srcptr);

#endif
