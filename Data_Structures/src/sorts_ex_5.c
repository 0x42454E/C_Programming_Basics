/**
 * Implements the Counting Sort algorithm to sort an integer array.
 * Counts the occurrences of each value, computes positions, and builds the sorted output.
 * Uses dynamic memory allocation for counting and output arrays.
 *
 * Author: Ben
 * Reviewed by: Chananya
 * Date: 2024-10-07
 *
 */

#include <stdlib.h> /* calloc, free */


void CountingSort(int arr[], int size)
{
	int	i = 0;
	int	max = 0;
	int*	counting = 0;
	int*	output = (int*)calloc(size, sizeof(int));
	
	for (i = 0; i < size; ++i)
	{
		if (max < arr[i])
		{
			max = arr[i];
		}
	}	
	
	counting = (int*)calloc(max+1, sizeof(int));
	
	for (i = 0; i < size; ++i)
	{
	
		++counting[arr[i]];
	}
	
	for (i = 1; i < max+1; ++i)
	{
		counting[i] = counting[i-1] + counting[i];
	}
	
	for (i = size-1; i >= 0; --i) /* seg fault - find why */
	{
		output[counting[arr[i]] - 1] = arr[i];
		--counting[arr[i]];
	}
	
	for (i = 0; i < size; ++i)
	{
		arr[i] = output[i];
	}
}
