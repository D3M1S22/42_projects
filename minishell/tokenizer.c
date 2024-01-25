#include <stddef.h>
#include <string.h>
#include <stdio.h>

char *cus_strsep(char **stringp, const char *delim)
{
	char *s;
	const char *spanp;
	int c, sc;
	char *tok;

	if ((s = *stringp) == NULL)
		return (NULL);
	for (tok = s;;) {
		c = *s++;
		spanp = delim;
		do {
			if ((sc = *spanp++) == c) {
				if (c == 0)
					s = NULL;
				else
					s[-1] = 0;
				*stringp = s;
				return (tok);
			}
		} while (sc != 0);
	}
	/* NOTREACHED */
}

int main(){
	char var[] = "cat -ls | gay";
	
	char *token;
	char *remaining = var;
	
	while ((token = cus_strsep(&remaining, "|")) != NULL)
		printf("%s\n", token);
	return (0);
}