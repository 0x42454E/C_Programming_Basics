#include <stdio.h>
#include <stdlib.h>
#include "sorts.h"

int main()
{
	int* arr = (int*)malloc(5000*sizeof(int));
	int size = 5000;
	int i = 0;
	/*printf("%lu\n", BinarySearch(arr, 0, 7, 5));
	printf("%lu\n", BinarySearchRecursive(arr, 0, 7, 5));*/
	
	for (i = 0; i < size; ++i)
	{
		arr[i] = (rand() % 100) + 1;
	}
	
	QuickSort(arr, 0, size-1);
	
	while (size--)
	{	
		printf("%d ", arr[size]);
	}
	
	printf("\n");
	
	return 0;
}


