/* Ben
reviewed by Chananya 7.10 */

void QuickSort(int *arr, int low, int high)
{
  	int pivot, i, j, temp;
  	
  	if(low < high) 
  	{
	    pivot = low; 
	    i = low;
	    j = high;
	    
	    while(i < j)
	    {
		      while(arr[i] <= arr[pivot] && i <= high)
		      {
				++i;
		      }

		      while(arr[j] > arr[pivot] && j >= low)
		      {
				j--;
		      }

		      if(i < j) 
		      {
				temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;
		      }
	    }

		    temp = arr[j];
		    arr[j] = arr[pivot];
		    arr[pivot] = temp;
		   
		    QuickSort(arr, low, j-1);
		    QuickSort(arr, j+1, high);
	  }
}
    
    
    



