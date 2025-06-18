#include <stdio.h>
#include <stdlib.h>
#include "singly_linked_list.h"
#include "singly_linked_list_2.h"
#include "hash_table.h"

#define BASE (256)

const size_t	size = 5;

size_t Algorithm(void* key);
int CompareHow(const void *data, void *param);
int Multiply(void *data, void *param);


int main() 
{
	int		result = 0;
	
	size_t		check = 0;
	char		data1[] = "10";
	char		data2[] = "20";
	char		data3[] = "30";
	char		data4[] = "40";
	char		data5[] = "50";
	
	void*		data = NULL;
	const void*	ptr = NULL;
	
	match_func_t  compare = CompareHow;
	hash_function_t function = Algorithm;
	action_func_t action_func = Multiply;
	
	hash_t*	table = HashCreate(size, function, compare);
	if (!table)
	{
		fprintf(stderr, "failed creating table in main\n");
		return 0;
	}
	
	result = HashIsEmpty(table);
	printf("Hash is Empty if 1; result = %d\n", result);

	ptr = &data1;
	result = HashInsert(ptr, table, ptr); 
	printf("1\n");
	if (!result)
	fprintf(stderr, "failed inserting data1 table in main\n");

	printf("2\n");
	ptr = &data2;
	result = HashInsert(ptr, table, ptr); 
	if (!result)
	fprintf(stderr, "failed inserting data2 table in main\n");
		
	ptr = &data3;	
	result = HashInsert(ptr, table, ptr); 
	if (!result)
	fprintf(stderr, "failed inserting data3 table in main\n");

	ptr = &data4;
	result = HashInsert(ptr, table, ptr); 
	if (!result)
	fprintf(stderr, "failed inserting data4 table in main\n");
	
	printf("3\n");	
	ptr = &data5;	
	result = HashInsert(ptr, table, ptr); 
	if (!result)
	fprintf(stderr, "failed inserting data5 table in main\n");
	printf("4\n");
	                             
	result = HashForEach(table, Multiply, (void*)ptr);
	printf("HashForEach result = %d\n", result);	


	ptr = &data3;	
	result = HashRemove(ptr, table);
	printf("HashRemove result true or false = %d\n", result);	

	ptr = &data2;	
	result = HashRemove(ptr, table);
	printf("HashRemove result true or false = %d\n", result);	
	
	
	check = HashSize(table);
	printf("Hash size is %lu\n", check);	


	ptr = &data4;                                    
	data = HashFind(table, compare, function, ptr); 
	printf("Expected esult of find is 50 == %s\n", *(char*)data);	


	HashDestroy(table);
	
	return 0;
}



size_t Algorithm(void* key) 
{ 
    size_t	   h = 0;
    unsigned char* us;

    us = (unsigned char*)key;
       
    while(*us != '\0') 
    {
         h = (h * BASE + *us) % size;
       	 ++us;
    } 
   
   return h;
}

int CompareHow(const void *data, void *param)
{
	int result = 0;
	
	result = *(int*)data;
	
	if (result == *(int*)param)
	{
		printf("result of CompareHow %d\n", result);
		return result;
	}
	
	return 0;
}

int Multiply(void *data, void *param)
{	
	return 0;
}



