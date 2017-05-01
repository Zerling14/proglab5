#include "strings.h"
#include <stdio.h>
int slen(char *str)
{
	int str_p = 0;
	int count = 0;
	while (str[str_p] != 0) {
		if(str[str_p] == 0xFFFFFFD0) {
			str_p++;
			continue;
		}
		str_p++;
		count++;
	}
	return count;
}
