/* Ben
reviewed by Chananya 7.10 */
void BubbleSort(int arr[], int size)
{
	int i = 0;
	int temp = 0;
	int count = 0;
	
	
	while (1)
	{
		if (arr[i] > arr[i+1])
		{
			temp = arr[i];
			arr[i] = arr[i+1];
			arr[i+1] = temp;
			count = 0;
			i = 0;
		}
		
		++i;
		++count;
		
		if (count == size - 1)
		{
			break;
		}
	}
	
	return;
}
