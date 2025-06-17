/**
 * Compares two strings ignoring case differences.
 * Returns 0 if equal, 1 if s1 > s2, and -1 if s1 < s2.
 * 
 * Author: Ben
 * Date: 2024-08
 */

#include <stdio.h>     /* printf */
#include <string.h>    /* strlen, strcpy */
#include <ctype.h>     /* tolower */
#include <assert.h>    /* assert */

int StrCaseCmp(const char *s1, const char *s2)
{
	int i = 0;
	int length1 = strlen(s1) + 1;
	int length2 = strlen(s2) + 1;
	int result = 0;
	char str1[length1];
	char str2[length2];
	
	strcpy(str1, s1);
	strcpy(str2, s2);
	
	assert('\0' != *s1 && '\0' != *s2);
	
	while(i < length1 && i < length2)
	{	
		str1[i] = tolower(str1[i]);
		str2[i] = tolower(str2[i]);
		++i;
	}
	
	i = 0;
	
	while('\0' != str1[i] && '\0' != str2[i])
	{
		if(str1[i] > str2[i])
		{
			result = 1;
			break;	
		}
		if(str1[i] < str2[i])
		{
			result = -1;
			break;
		}
			++i;
	}
		if(result == 0 && length1 < length2)
			result = -1;
		if(result == 0 && length1 > length2)
			result = 1;
		
		return result;
}

