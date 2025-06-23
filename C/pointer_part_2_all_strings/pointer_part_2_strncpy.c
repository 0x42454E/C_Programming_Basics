/**
 * Custom implementation of StrNCpy which copies up to n characters
 * from the source string to the destination string.
 * 
 * Author: Ben
 * Reviewed by: Alex
 * Date: 2024-08
 */

#include <stdio.h>    /* printf */
#include <string.h>   /* strlen */
#include <assert.h>   /* assert */

char *StrNCpy(char *dest, const char *src, size_t n)
{
	size_t i;
	assert(NULL != src && 0 != n);
	
	for(i = 0; i < n && ('\0' != *dest && '\0' != *src); ++i)
	{
		*dest++ = *src++;
	}
	
	return dest;
}

