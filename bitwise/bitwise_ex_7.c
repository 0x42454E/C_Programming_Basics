/**
 * This program recieves an unsigned int and returns the closest (smaller) number divisable by 16. 
 * 
 * 
 * Author: Ben
 * Date: 2024-08
 */

unsigned int IsDevide(unsigned int a)
{
	
	return (a & ~0x0F);
}
