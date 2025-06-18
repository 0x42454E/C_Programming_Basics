/* Ben
reviewed by Chananya 7.10 */
#include <stdio.h>

void SelectionSort(int arr[], int size)
{
	int 	i = 0;
	int 	j = 0;
	int	temp_index = 0;
	int	select = 0;
	
	for (i = 0; i < size; ++i)
	{
		select = arr[i];
		
		for (j = i; j < size; ++j)
		{
			if (select > arr[j])
			{
				select  = arr[j];
				temp_index = j;
			}
		}
		
		
		j = arr[i];
		arr[i] = select;
		arr[temp_index] = j;
	}
}
