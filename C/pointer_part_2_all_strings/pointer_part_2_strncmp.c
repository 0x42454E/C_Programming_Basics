/**
 * Custom implementation of StrNCmp which compares up to n characters
 * between two strings and returns 0 if equal, 1 if s1 > s2, or -1 if s1 < s2.
 * 
 * Author: Ben
 * Reviewed by: Alex
 * Date: 2024-08
 */

#include <stdio.h>   /* printf */
#include <assert.h>  /* assert */
#include <string.h>  /* strlen */

int StrNCmp(const char *s1, const char *s2, size_t n)
{
	int result = 0;
	size_t i = 0;
	
	assert('\0' != *s1 && '\0' != *s2);
	
	if(*s1 > *s2)
	{
		result = 1;
	}
	else if(*s1 < *s2)
	{
		result = -1;
	}	
	else
	{
		while(*s1 == *s2 && '\0' != *s1 && '\0' != *s2 && n > i)
		{
			if(*s1 > *s2)
			{
				result = 1;
				break;
			}
			else if(*s1 < *s2)
			{
				result = -1;
				break;
			}
					
				++s1;
				++s2;
				++i;
			}
			}
     return result;
}	
