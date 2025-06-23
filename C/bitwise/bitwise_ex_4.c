/**
 * This program recieves and array of unsigned ints 
 * and only prints ints that are exactly 3 bits on. 
 * 
 * 
 * Author: Ben
 * Date: 2024-08
 */

#include <stdio.h> /* printf */
#include <stdlib.h> /* size_t */

void ThreeBits(unsigned int *arr, size_t size)
{
	unsigned int count = 0;
	size_t i = 0;
	
	for (; i < size; ++i)
	{
		while (arr[i])
		{
			count += arr[i] & 1;
			arr[i] >>= 1;
		}
		
		if (3 == count)
		{
			printf("arr[%lu] is 3 bits\n", i);
		}
		
		count = 0;
	}	
}
