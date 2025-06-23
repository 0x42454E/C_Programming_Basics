#include <string.h>  /* strncpy */
#include <stdio.h>   /* printf sprintf */
#include <stdlib.h>  /* free */

 /**
 * This program defines a composite data structure containing integers,
 * floats, and strings, and operates on an array of these structures.
 * 
 * It includes functionality to initialize the array, add values to its
 * numeric fields, print the contents, and clean up allocated memory.
 * 
 * 
 * 
 * Author: Ben
 * Date: 2024-08
 */
 

int main()
{
	int 	i = 0;
	
	typedef void (*function_t)(void *);
	
	typedef struct 
	{
		void 		*var;
		function_t 	add;
		function_t 	print;
		function_t 	clean;
	}input_struct_t;
	
	input_struct_t array_elements[3];

	int 	int_val = 4;
	float 	float_val = 4.18f;
	char 	str_val[100] = "my string";
    
         array_elements[0].var = &int_val;
   	 array_elements[0].add = AddInt;
  	 array_elements[0].print = PrintInt;
   	 array_elements[0].clean = NULL;

   	 array_elements[1].var = &float_val;
   	 array_elements[1].add = AddFloat;
   	 array_elements[1].print = PrintFloat;
    	 array_elements[1].clean = NULL;

    	 array_elements[2].var = str_val;
   	 array_elements[2].add = AddString;
  	 array_elements[2].print = PrintString;
    	 array_elements[2].clean = Free;
	
	for (; i < 3; ++i)
	{
		array_elements[i].add(array_elements[i].var);
		array_elements[i].print(array_elements[i].var);
	}
	
	if (array_elements[i].clean)
        {
            array_elements[i].clean(array_elements[i].var);
        }
	

	
	return 0;
}


void AddInt(void *var)
{
	*(int *)var += 10;
}

void AddFloat(void *var)
{
	*(float *)var += 10.0f;
}

void AddString(void *var)
{
	 char temp[100];
	 sprintf(temp, "%s%d",(char *)var, 10); 
	 strncpy((char *)var, temp, 99);
	 ((char *)var)[99] = '\0';
}
	
void PrintInt(void *var)
{
	printf("%d\n", *(int *)var);
}

void PrintFloat(void *var)
{
	printf("%f\n", *(float *)var);
}

void PrintString(void *var)
{
	printf("%s\n", (char *)var);
}

void Free(void *var)
{
	free(var);
}
