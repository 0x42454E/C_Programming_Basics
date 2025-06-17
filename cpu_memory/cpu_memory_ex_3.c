/**
 * A simple program to detect the endianness of the system using a macro.
 * It checks whether the least significant byte of a multi-byte integer is stored first (little-endian)
 * or last (big-endian).
 * 
 * Author: Ben
 * Date: 2024-08
 * 
 */

#include <stdio.h> /* printf */

#define number_1 1

#define LEAST_SIGNIFICANT_BYTE (*(unsigned char*)number_1)

#define __IS_LITTLE_ENDIAN__() (LEAST_SIGNIFICANT_BYTE == 1)

int main()
{
	
	if (__IS_LITTLE_ENDIAN__())
	{
		printf("Is Little E\n");
	} 
	  else
	{
		printf("Not\n");
	}
	
	return 0;
}	

