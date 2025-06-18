/**
 * This function identifies and returns duplicate elements from an integer array.
 * It allocates memory for the result dynamically and stores each duplicate only once.
 *
 * Author: Ben
 * Date: 2024-09
 *
 */

#include <stdlib.h> /* malloc */

int *FindDuplicates(int* arr, size_t size)
{
	int*	result = (char)malloc(size);
	size_t	i = 0;
	size_t	j = 0;
	size_t	k = 0;
	
	for (; j < size; ++j)
	{
		
		for (i = j + 1; i < size; ++i)
		{
			if (arr[i] == arr[j])
			{
				result[k++] = arr[j];
				break;
			}
					
		} 
	}
	
	return result;
}
