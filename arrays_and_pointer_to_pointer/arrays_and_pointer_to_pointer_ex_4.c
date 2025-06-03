#include <stdio.h>      /* printf */
#include <stdlib.h>     /* malloc, free */
#include <ctype.h>      /* tolower */
#include <string.h>     /* strlen, memcpy */
#include <assert.h>     /* assert */

/**
 * This program duplicates all the enviromental variables in lower-case format, and prints them. 
 * 
 * It demonstrates memory manipulation and string handling in C. 
 * 
 * Author: Ben
 * Date: 2024-08
 */

void PrintEnvironmentVariables(void);
char* ToLower(char* str);
char *StrDup(const char *s);

int main(void) 
{
    PrintEnvironmentVariables(); 
    
    return 0;
}

void PrintEnvironmentVariables() 
{
    extern char **environ; 
    char **current_env = environ;
    
    while (*current_env != NULL) 
    {
        char* env_copy = StrDup(*current_env);  
        if (env_copy != NULL) 
        {
            ToLower(env_copy);   
            printf("%s\n", env_copy); 
            free(env_copy);    
        }
        current_env++;
    }    
}

char* ToLower(char* str)
{
    assert(str != NULL);

    char* p = str;
    while ('\0' != *p) 
    {
        *p = (char)tolower((unsigned char)*p);  
        p++;
    }

    return str;
}

char *StrDup(const char *s)
{

    assert(s != NULL);

	size_t size = strlen(s) + 1;

	char *d = (char *)malloc(size);
		
	
    if (d != NULL)
    {
        memcpy(d, s, size);
    }

	return d;
}


