#include <stdio.h>    /* printf */


/**
 * This program defines macros to find the maximum of two and three integers,
 * then uses the two-argument macro to find and print the bigger of two values.
 * 
 * Author: Ben
 * Date: 2024-08
 */
#define __MAX2__(a, b) (((a) > (b)) ? (a) : (b))         /* macro for max of two */
#define __MAX3__(a, b, c) (__MAX2__(__MAX2__(a, b), c))   /* macro for max of three */


int main()
{
	int 	a = 2;
	int 	b = 3;
	int 	result = 0;
	
	result = __MAX2__(b, a);
	
	printf("the biggest is %d\n", result);
	
	return 0;
}
