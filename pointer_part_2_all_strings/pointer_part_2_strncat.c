/**
 * Custom implementation of StrnCat which appends up to n characters
 * from the source string to the end of the destination string.
 * 
 * Author: Ben
 * Reviewed by: Alex
 * Date: 2024-08
 */

#include <stdio.h>   /* puts */
#include <assert.h>  /* assert */

char *StrnCat(char *dest, const char *src, size_t n)
{
       size_t i = 0;
       assert('\0' != *dest && '\0' != *src);
       
       char *p = dest;
       
       while('\0' != *p)
       {
       		++p;
       }
       
      while('\0' != *src && i < n)
      {
      		*p++ = *src++;
      		++i;
      }
      
      *p = '\0';
      
      return dest;
}
