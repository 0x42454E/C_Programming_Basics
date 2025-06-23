/**
 * Custom implementation of StrDup which duplicates a string by allocating
 * memory and copying the content from the source string.
 * 
 * Author: Ben
 * Reviewed by: Alex
 * Date: 2024-08
 */

#include <stdio.h>   /* printf */
#include <stdlib.h>  /* malloc */
#include <string.h>  /* strlen */
#include <assert.h>  /* assert */

char *StrDup(const char *s)
{
	
	assert('\0' != *s);
	
	size_t size = strlen(s);
	char *d = (char *)malloc(size);
	
	for(size_t i = 0; i < size; ++i)
	{
		d[i] = s[i];
	}
	
	return d;
}

