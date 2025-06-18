/* Ben
reviewed by Chananya 7.10 */
#include <stddef.h>

size_t BinarySearch(size_t arr[], size_t low, size_t high, size_t search)
{
	size_t mid;
	
	while(low <= high)
	{	
		mid = low + (high - low) / 2;
		
		if (arr[mid] == search)
		{
			return mid;	
		}
		
		if (arr[mid] < search)
		{
			low = mid + 1;
		}
		else
		{
			high = mid - 1;
		}
	}
	
	return -1;
}

size_t BinarySearchRecursive(size_t arr[], size_t low, size_t high, size_t search)
{
	size_t mid = low + (high - low) / 2;
	
	
		if (arr[mid] == search)
		{
			return mid;	
		}
		
		if (arr[mid] < search)
		{
			return BinarySearchRecursive(arr, mid + 1, high, search);
		}
		else
		{
			return BinarySearchRecursive(arr, low, mid - 1, search);
		}
		
	return -1;
}


