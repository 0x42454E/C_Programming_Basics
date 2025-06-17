#include <stdio.h>
#include <stdlib.h>

/**
 * This program defines a composite data structure containing integers,
 * floats, and strings, and operates on an array of these structures.
 * 
 * It includes functionality to initialize the array, add values to its
 * numeric fields, print the contents, and clean up allocated memory.
 * 
 */

	typedef struct
	{
		int 	x;
		int 	y;
	}num;
	
	 typedef struct 
	{
		float 	x;
		float	y;
	}real_num;
		
	typedef struct 
	{
		char	 str[20];
		char	*ptr;
	}string;
	
	typedef struct 
	{
		num numbers;
		real_num real_numbers;
		string string;
	}structs;
	
	structs new_structs[10];
	

void PrintArray()
{
	int 	i = 0;
	
	for (i = 0; i < 10; ++i)
	{
		printf("%d ", (new_structs[i].numbers.x + new_structs[i].numbers.y));
		printf("%f ", (new_structs[i].real_numbers.x + new_structs[i].real_numbers.y));
		printf("%s\n", new_structs[i].string.str);
	}
}

void ArrayInitialization()
{
	int 	i = 0;
	 
	 for (; i < 10; ++i)
	 {
	 	new_structs[i].numbers.x = 1;
	 	new_structs[i].real_numbers.x = 1.1;
	        sprintf(new_structs[i].string.str, "hello"); 
	 }
}

void Add()
{
	int 	add_value = 10;
	int 	i = 0;
	
	for (; i < 10; ++i)
	 {
	 	new_structs[i].numbers.x += add_value;
	 	new_structs[i].numbers.y += add_value;
	 	new_structs[i].real_numbers.x += add_value;
	 	new_structs[i].real_numbers.y += add_value;
	        sprintf(new_structs[i].string.str, "hello%d", add_value); 
	 }
}

void Cleanup()
{
	int 	i = 0;
	
	for (; i < 10; ++i)
	{
		free(new_structs[i].string.str);
	}
}
