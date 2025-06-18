/* Ben
reviewed by Or 30.09*/
#include <string.h>

char* StrStr(char *haystack, char *needle)
{
	char* temp = haystack;
	while (*haystack == *needle)
	{
		
		
		if (!haystack || !needle || !strncmp(haystack++, needle++, 1))
		{
			if (strncmp(haystack--, needle--, 1))
			{
				temp = NULL;
			}
				return temp;
		}
	}
	
	return StrStr(haystack + 1, needle);
}



