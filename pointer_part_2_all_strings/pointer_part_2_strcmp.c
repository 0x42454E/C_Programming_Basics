/**
 * Custom implementation of StrCmp to compare the lengths of two strings.
 * Returns the difference between the lengths of s1 and s2.
 * 
 * Author: Ben
 * Reviewed 6.8.24 by Alex
 */

#include <stdio.h>   /* printf */
#include <assert.h>  /* assert */

int StrCmp(const char *s1, const char *s2)
{
	const char *run1 = s1;
	const char *run2 = s2;
	char length1, length2;
	
	assert(s1 != NULL || s2 != NULL);
	
	while(*run1 != '\0')
	{
		++run1;
	}
	
	while('\0' != *run2)
	{
		++run2;
	}
	
	length1 = run1 - s1, length2 = run2 - s2;
	
	return (length1 - length2);
}
