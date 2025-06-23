/**
 * This program increments by 1 using bitwise operations. 
 * 
 * 
 * Author: Ben
 * Date: 2024-08
 */

#include <stdlib.h> /* abs */


int Inc(int num)
{
	num = abs(~num);
	return num;
}
