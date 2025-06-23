/**
 * This program sets the terminal to non-canonical, no-echo mode and uses
 * a function pointer lookup table (LUT) to handle character input.
 * It prints messages when 'A' or 'T' keys are pressed, and exits on ESC.
 * 
 * Author: Ben
 * Date: 2024-08
 */

#include <stdio.h>   /* printf, getchar */
#include <stdlib.h>  /* system, exit */
#include <unistd.h>  /* for completeness, not directly used here */

typedef void (*ptr)(void);

void ESC();
void T();
void A();
void V();
void StartLut(ptr a[]);


int main()
{	
	char c;
	ptr arr[256];
	system("stty -icanon -echo\n");
	
	StartLut(arr);
		
	
	while(1)
	{
		c = getchar();
		arr[(unsigned char)c]();
	}
	
	return 0;
}



void ESC()
{
	system("stty icanon echo");
	exit(1);
}

void T()
{
	printf("T-pressed\n");
}


void A()
{
	printf("A-pressed\n");
}

void V()
{
	
}

void StartLut(ptr a[])
{
	int i;
	
	for(i = 0; i < 256; ++i)
		{
			a[i] = V;
		}
		
	a[65] = A;
	a[97] = A;
	a[116] = T;
	a[84] = T;
	a[27] = ESC;
}
