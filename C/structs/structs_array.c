#include <stdio.h> /* printf */

/**
 * This program creates a structs type "print_me" 
 * that holds an int and a pointer to a function Print(int).
 * 
 * Then creates an array of struct print_me, each one holding a
 * different int value, and uses the print function.
 * 
 * Author: Ben
 * Date: 2024-08
 */
 
typedef void (* fun_ptr)(int);

void Print(int a);

int main()
{
	int i = 0;
	
	typedef struct 
	{
		int a;
		fun_ptr print_ptr;
	} print_me;
	
	print_me arr_struct[10];
	
	for (; i < 10; ++i)
	{
	 	arr_struct[i].a = i;
	  	arr_struct[i].print_ptr = Print;
	}
	
	for (i = 0; i < 10; ++i)
	{
		arr_struct[i].print_ptr(arr_struct[i].a);
	}
	
	return 0;
}

void Print(int a)
{
	printf("%d\n", a);
}
