/**
 * Custom implementation of Strlen which calculates the length of a
 * null-terminated string by counting characters until the terminator.
 * 
 * Author: Ben
 * Reviewed by: Alex
 * Date: 2024-08
 */

#include <stdio.h>    /* printf */
#include <assert.h>   /* assert */

size_t Strlen(const char *a)
{
	size_t count = 0;
	assert(*a != '\n');
	
	while (*a != '\0')
	{
		++count;
	}
	
	return count;
}
