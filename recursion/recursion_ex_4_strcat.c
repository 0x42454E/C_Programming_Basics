/**
 * Recursive implementation of string concatenation.
 *
 * StrCat: Appends the source string (src) to the end of the destination string (dest) recursively.
 *
 * Uses no external libraries; relies solely on pointer dereferencing and recursion.
 *
 * Author: Ben
 * Date: 2024-09-30
 */

#include "recursion_ex_4_str.h"

void StrCat(char* dest, char* src)
{
	(*dest) ? StrCat(++dest, src) : (*dest++ = *src++) ? StrCat(dest, src) : 0 ;
}




