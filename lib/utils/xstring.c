#include "xstring.h"

char *remove_ends_whitespace_line(char *string)
{
	char *start;
	char *end;
	
	start = string;
	while (*start == ' ' || *start == '\t')
		start++;

	end = start + strlen(start) - 1;
	while (*end == ' ' || *end == '\t' && end > start)
		end--;
	
	*(end+1) = '\0';

	return start;
}
