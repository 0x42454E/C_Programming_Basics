/**
 * This program calculates in num is the power of 2, using a loop and without a loop. 
 * Returns true or false.
 * 
 * 
 * Author: Ben
 * Date: 2024-08
 */

unsigned IsPowLoop(unsigned num)
{	
	unsigned temp = 1;
	
	while (temp < num)
	{
		temp = temp << 1;
	}
	
	if (temp == num)
	{
		num = 1;
	}
	else
	{
		num = 0;
	}
	
	return num;
}

unsigned IsPow(unsigned num)
{	
	return ((num & -num) == num); 
}
