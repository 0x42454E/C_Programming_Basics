/**
 * This program reads an integer from the user,
 * reverses its digits, and prints the reversed number.
 * 
 * Author: Ben
 * Date: 2024-08
 */

#include <stdio.h>  /* printf, scanf */

int flip(int);

int main()
{
	int f;	
	
	printf("input a digit so flip:");
	scanf("%d", &f);
	
	flip(f);
	
	return 0;
}

int flip(int a)
{
	int reverse = 0, remainder;

	while (a != 0)
	{
	remainder = a % 10;
	reverse = reverse * 10 + remainder;
	a /= 10;
	}
	
	printf("%d\n", reverse);

}
