#include <stdio.h>
#include <stdlib.h>
#include "strings.h"
#include <ctype.h>
void fix_path(char * path)
{
	
	char *pos;
	while((pos = sstr(path, "..")) != NULL) {
		for (char *i = pos - 2; pos >= 0; i--) {
			if (*(pos - 2) == ':') {
				*(pos) = 0;
				scat(path, pos + 2);
				break;
			}
			if (*i == '/' || *i == '\\') {
				i++;
				*i = 0;
				i--;
				if (*(pos + 2) == '\\' || *(pos + 2) == '/') {
					scat(path, pos + 3);
				} else {
					scat(path, pos + 2);
				}
				break;
			}
		}
	}
	while((pos = sstr(path, "\\.")) != NULL) {
		char *i = pos + 1;
		*i = 0;
		if (*(pos + 2) == '\\' || *(pos + 2) == '/') {
			scat(path, pos + 3);
		} else {
			scat(path, pos + 2);
		}
	}
	while((pos = sstr(path, "/.")) != NULL) {
		char *i = pos;
		*i = 0;
		if (*(pos + 2) == '\\' || *(pos + 2) == '/') {
			scat(path, pos + 2);
		} else {
			scat(path, pos + 1);
		}
	}
}

void input(char *paths, char *delim) {
	printf("delim: ");
	scanf("%s", delim);
	printf("paths: ");
	scanf("%s", paths);
}

int check(char *paths)
{
	if (sspn(paths, "*?\"<>|")) {
		return 1;
	}
	char *result = sstr(paths, ":\\");
	if (result != NULL) {
		if (result - paths >= 1 || result - paths <= 2) {
			int num_char = 0;
			for (int k = result - paths; k >= 0; k--) {
				if (isalpha(paths[k])) {
					num_char++;
				}
			}
			if (num_char == result - paths) {
				if (sstr(paths, "/") == 0) {
					return 0;
				}
			}
		}
	} else {
		if (sspn(paths, "\\") == 0) {
			return 0;
		}
	}
	return 1;
}

void process(char *paths, const char *delim) 
{
	char *str = stok(paths, delim);
	char *result_str = calloc(1000, sizeof(char));
	if (!check(str)) {
		fix_path(str);
		scat(result_str, str);
	}
	while ((str = stok(NULL, delim)) != NULL) {
		if (check(str)) {
			continue;
		}
		if (result_str[0] != 0) {
			scat(result_str, "+");
		}
		fix_path(str);
		scat(result_str, str);
	}
	scpy(paths, result_str);
	free(result_str);
}

void output(const char *paths)
{
	printf("new paths: %s\n", paths);
}

int main()
{
	char delim[30];
	char paths[1000];
	input(paths, delim);
	
	//if (check(paths)) {
	//	printf("Unallowed character\n");
	//	return 1;
	//}
	
	process(paths, delim);
	
	output(paths);
	
	return 0;
}
