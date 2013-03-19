#include "../../utils/xstring.h"
#include <stdio.h>

int
main(void)
{
	char string[] = " ns ";
	
	printf("%s\n", remove_ends_whitespace_line(string));

	return 0;
}
