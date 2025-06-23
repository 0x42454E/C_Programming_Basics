/**
 * This program copies a string from source to destination using a custom
 * StrCpy function, then prints the copied string.
 * 
 * Author: Ben
 * Date: 2024-08
 */

#include <stdio.h>   /* printf */
#include <assert.h>  /* assert */

char *StrCpy(char *dst, const char *src);

int main()
{
	char s[] = "source";
	
	char d[20];
	
	StrCpy(d, s);
	
	printf("%s\n", d);
	
	return 0;
}

char *StrCpy(char *dst, const char *src)
{
	char *runner = dst;
	
	assert(NULL != dst && NULL != src);
	
	while(*src != '\0')
	{
		*runner++ = *src++;
	}
	*runner = '\0';
	return (char *)dst;
}

