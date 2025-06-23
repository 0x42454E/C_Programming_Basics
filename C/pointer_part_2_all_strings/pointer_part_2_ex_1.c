/**
 * This function concatenates the string `src` to the end of the string `dest`.
 * It assumes `dest` has enough space to hold the resulting string.
 * It returns a pointer to the concatenated string `dest`.
 * 
 * Author: Ben
 * Date: 2024-08
 */

#include <stdio.h>   /* printf */
#include <assert.h>  /* assert */

char *StrCat(char *dest, const char *src)
{
       
       char *p = dest;
       assert('\0' != *dest && '\0' != *src);
       
       while('\0' != *p)
       {
       		++p;
       }
       
      while('\0' != *src)
      {
      		*p++ = *src++;
      }
      
      *p = '\0';
      
      return dest;
}


