/**
 * Custom implementation of StrStr which finds the first occurrence of the 
 * substring needle in the string haystack.
 * 
 * Author: Ben
 * Reviewed by: Alex
 * Date: 2024-08
 */

#include <stdio.h>    /* printf */
#include <string.h>   /* strlen */
#include <assert.h>   /* assert */

char *StrStr(const char *haystack, const char *needle)
{
	size_t size = strlen(needle);
	size_t n = 0;
	assert(NULL != needle && NULL != haystack);
	while('\0' != *haystack)
	{
		while(*haystack == *needle)
		{
			if(n == size)
			break;
				
			++haystack;
			++needle;
			++n;
		}		
	
	++haystack;
	needle -= n;
	n = 0; 
	}
	
		return (char *)(needle - n);
}
