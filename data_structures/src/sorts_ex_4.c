/**
 * Implements the Insertion Sort algorithm to sort an integer array in ascending order.
 * Builds the sorted array one element at a time by inserting elements into their correct position.
 *
 * Author: Ben
 * Date: 2024-10-07
 *
 */


/*void InsertionSort(int arr[], int size)
{
	int 	i = 0;
	int 	j = 0;
	int	temp = 0;
	int	select = 0;
	int	new_index = 0;
	
	for (i = 0; i < size; ++i)
	{
		for (j = i; j < size; ++j)
		{	
			if (arr[i] > arr[j])
			{
				new_index = j;
				if (i && 0 == temp)
				{
					temp = 1;
				}
			}
		}
		
		if (1 == temp)
		{
			temp = 0;
		}
		
		select = arr[new_index];
		arr[new_index] = arr[i];
		arr[i] = select;	
	}
}*/

void InsertionSort(int arr[], int size)
{
	int  key = 0;
	int  i = 0;
	int  j = 0;
	
    for (i = 1; i < size; ++i) 
    {
       key = arr[i];
       j = i - 1;


        while (j >= 0 && arr[j] > key) 
        {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}
