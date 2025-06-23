/**
 * This program calculates the number of set bits in an integer. 
 * 
 * Implemented using a loop and without it.
 * 
 * 
 * Author: Ben
 * Date: 2024-08
 */


int CountBitLoop(int num)
{

	int count = 0;
	
	while (num > 0)
	{
		count += num & 1;
		num >>= 1;
	}
	
	return count;
}

int CountBit(int num)
{
	if (num == 0)
	{
		return 0;
	}
	
	return ((num & 1) + CountBit(num >> 1));
}
