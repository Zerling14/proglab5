#include "strings.h"
#include <stdio.h>
#include <stdlib.h>

int slen(char *str)
{
	int str_p = 0;
	int count = 0;
	while (str[str_p] != 0) {
		/*
		if(str[str_p] == 0xFFFFFFD0) {
			str_p++;
			continue;
		}
		*/
		str_p++;
		count++;
	}
	return count;
}

char *str_stok = NULL;
char *stok(char *str, const char *delim)
{
	if (str != NULL) {
		str_stok = str;
	}
	if (str_stok == NULL) {
		return NULL;
	}
	for (int i = 0; str_stok[i] != 0; i++) {
		for (int j = 0; delim[j] != 0; j++) {
			if (str_stok[i] == delim[j]) {
				str_stok[i] = 0;
				char *result = str_stok;
				str_stok = str_stok + i + 1;
				return result;
			}
		}
	}
	if (str_stok != NULL) {
		char *result = str_stok;
		str_stok = NULL;
		return result;
	} else {
		return NULL;
	}
}

char *scpy(char *destptr, const char *srcptr)
{
	int i = 0;
	for (; srcptr[i] != 0; i++) {
		destptr[i] = srcptr[i];
	}
	destptr[i] = 0;
	return destptr;
}

int scmp(const char *string1, const char *string2) 
{
	for (int i = 0;; i++) {
		if (string1[i] == 0 && string2[i] == 0) {
			return 0;
		}
		int result = string1[i] - string2[i];
		if (result != 0) {
			return result;
		}
	}
	return 0;
}

size_t sspn(const char *str, const char *sym)
{
	size_t result = 0;
	for (int i = 0; str[i] != 0; i++) {
		for (int j = 0; sym[j] != 0; j++) {
			if (str[i] == sym[j]) {
				result++;
			}
		}
	}
	return result;
}







