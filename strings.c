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
int p_stok = 0;
char *stok(char *str, const char *delim)
{
	if (str != NULL) {
		p_stok = 0;
		str_stok = str;
	}
	if (str_stok == NULL) {
		return NULL;
	}
	for (int i = p_stok; str_stok[i] != 0; i++) {
		for (int j = 0; delim[j] != 0; j++) {
			if (str[i] == delim[j]) {
				p_stok = i;
				char * result = str_stok + i;
				return str;
			}
		}
	}
}

char *scpy(char *destptr, const char *srcptr)
{
	for (int i = 0; srcptr[i] != 0; i++) {
		destptr[i] = srcptr[i];
	}
	destptr[i] = 0;
	return destptr;
}








