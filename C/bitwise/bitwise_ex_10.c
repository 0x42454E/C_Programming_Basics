#include <stdio.h> /* printf */

/**
 * This program recieves a float number and prints it bits. 
 * 
 * It demonstrates the complexity of the float number in bitwise operations compared to ints. 
 * 
 * 
 * Author: Ben
 * Date: 2024-08
 */

	typedef union FloatBits
	{
		float f;
		unsigned int u;
	}FloatBits;
	
void PrintBits(unsigned int num)
{	
	int i;
	
    for (i = (sizeof(num) * 8 - 1); i >= 0; --i) 
    {
        printf("%d", (num >> i) & 1);
    }
    printf("\n");
}

int main()
{
	 FloatBits fb;
	 
	 fb.f = 8.6;
	
	PrintBits(fb.u);
	
	return 0;
	
}

	
	


