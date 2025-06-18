/**
 * Implementation of Fibonacci number calculation using both recursion and iteration.
 *
 * FibonacciRecursion: Computes the Fibonacci number at a given index recursively.
 * FibonacciIteratively: Computes the Fibonacci number at a given index using an iterative loop.
 *
 * Author: Ben
 * Date: 2024-09
 */

int FibonacciRecursion(int element_index)
{	
	if (0 == element_index)
	{
		return 0;
	}
	else if (1 == element_index)
	{
		return 1;
	}
	else
	{
		return (FibonacciRecursion(element_index - 1)) + (FibonacciRecursion(element_index - 2)); 
	}
}

int FibonacciIteratively(int element_index)
{
	  int i;
	  int t1 = 0;
	  int t2 = 1;
	  int next = t1 + t2;
	  	
	  if (0 == element_index)
	  {
	  	return 0;
	  }
	  else if (1 == element_index)
	  {
	  	return 1;
	  }

	  for (i = 3; i <= element_index; ++i) 
	  {
		    t1 = t2;
		    t2 = next;
		    next = t1 + t2;
	  }

	  return next;
}
