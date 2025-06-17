/**
 * This program compares a string with its reversed version using the SwCmp function.
 * If the strings are equal, it prints "success!".
 * 
 * Author: Ben
 * Date: 2024-08
 */

#include <stdio.h>    /* printf */
#include <stdlib.h>   /* malloc, free */
#include <string.h>   /* strlen, strcmp */
#include <assert.h>   /* assert */


int main()
{
	const char s[] = "llllllo";
	
	size_t size = strlen(s);
	
	int result = SwCmp(s, size);
	
	if(result == 0)
	printf("success!\n");
	
	printf("result is: %d\n", result);
	
	return 0;
}

int SwCmp(const char* src, size_t len)
{	
	int result;
	const char *runner = src;
	char *s = malloc((len + 1) * sizeof(char));
	*(s + len) = '\0';
	assert(NULL != src);
	
	while('\0' != *runner && len > 0)
	{
		s[len - 1] = *runner;
		--len;
		++runner;	
	}
	
	
	result = strcmp(src, s);
	
	free(s);
	
	return result;
}
