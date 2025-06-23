/**
 * This program swasp 2 variables without using a third temp variable. 
 * 
 * 
 * Author: Ben
 * Date: 2024-08
 */

void SwapValue(int *x, int *y)
{
 
    *x = *x ^ *y;
    *y = *x ^ *y;
    *x = *x ^ *y;
    
}
