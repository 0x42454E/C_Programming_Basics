/**
 * Custom implementation of StrCpy to copy a string from src to dest.
 * Copies characters until the null terminator is reached.
 * 
 * Author: Ben
 * Reviewed by: Alex
 * Date: 2024-08
 */

#include <stdio.h>    /* printf */
#include <assert.h>   /* assert */

char *StrCpy(char *dest, const char *src)
{
	
	assert('\0' != *src);
	
	while ('\0' != *src)
	{
		*dest = *src;
		++src;
		++dest;
	}
	
	return dest;
}

