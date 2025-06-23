/**
 * This program implements ByteMirror.
 * 
 * Using a loop and without using a loop.
 * 
 * 
 * Author: Ben
 * Date: 2024-08
 */

#include <stdio.h> /* printf */

void ByteMirror(unsigned num)
{
	unsigned temp = 0;
	
	while (num != 0)
	{
		temp <<= 1;
			
		if ((num & 1) == 1)
		{
			temp ^= 1;
		}
		
	    num >>= 1;
	}
	
	printf("mirror is (temp)%u\n", temp);
}

int MirrorSwapNibbles(int x)
{

	 x = (((x & 0x1) << 3) | ((x & 0x2) << 1) | ((x & 0x4) >> 1) | ((x & 0x8) >> 3));
 
   	 x = (((x >> 4) & 0x0F) | ((x & 0x0F) << 4));
    
    
	 return x; 
}