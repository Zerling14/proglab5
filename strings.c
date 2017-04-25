#include "strings.h"

int slen(char *str)
{
	int str_p = 0;
	while (str[str_p] != 0) {
		str_p++;
	}
	return str_p;
}
