/**
 * This program tests the custom implementation of StrChr,
 * which locates the first occurrence of character c in string s.
 * Prints "success" if the character is found at the expected position.
 * 
 * Author: Ben
 * Reviewed by: Alex
 * Date: 2024-08
 */

#include <stdio.h>     /* printf */
#include <assert.h>    /* assert */

char *StrChr(const char *s, int c)
{

	assert('\0' != *s);
	
	while('\0' != *s && c != *s)
	{
		++s;
	}
	
	return (*s == c) ? (char *)s : NULL;
}
