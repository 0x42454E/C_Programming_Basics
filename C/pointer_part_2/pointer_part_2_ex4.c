/**
 * This program removes trailing spaces and tabs,
 * replaces tabs with spaces, and removes consecutive double spaces from a string.
 * 
 * Author: Ben
 * Date: 2024-08
 */

#include <stdio.h>    /* printf */
#include <stdlib.h>   /* malloc */
#include <string.h>   /* strlen, strchr, strstr */

char *SpRev(char *s);


int main()
{
	char s[] = " kav  iar  ", *p;
	size_t size = strlen(s);
	p = malloc((size + 1) * (sizeof(char)));
	p[size] = '\0';
	
	p = SpRev(s);
	
	printf("%s\n", p);
	
	return 0;
}

char *SpRev(char *s)
{
	size_t i = 0, j = 1;
	char d_space[] = "  ";
	char space = ' ';
	char tab = '\t';
	char *p;
	size_t size = strlen(s);
		
	if(s[size - 1] == space)
	{
		for(i = 0; i < size - 1; ++i)
		{
			s[size - j] = s[size - (j + 1)];
			++j;
		} 
       	  i = 0;
	}
		
		while (NULL != p)
		{	
			if(NULL != (p = strchr(s, tab)))
			{
				p = strchr(s, tab);
				while('\0' != p[i + 1])
				{
				p[i] = p[i + 1];
				} 
				  i = 0;
			} 
			
			else 
			{
				p = strchr(s, space);
				while('\0' != p[i + 1] && NULL != p)
				{
				p[i] = p[i + 1];
				} 
			}
			
			p = strstr(s, d_space);
			
				while (NULL != p)
				{	
					p = strstr(s, d_space);
					if(NULL != p)
					{
						while('\0' != p[i + 2])
						{
							p[i + 1] = p[i + 2];
						} 
							  i = 0;
					} 
				}
	
 		}
	return s;
} 
