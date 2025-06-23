/**
 * Implementation of a hash table using an array of singly linked lists (buckets).
 * Supports create, destroy, insert, remove, find, size, empty check, and foreach operations.
 *
 * Author: Ben
 * Date: 2024-09-29
 *

 */

#include <stdio.h>   /* fprintf */
#include <stdlib.h>  /* malloc, free */
#include "singly_linked_list.h"
#include "singly_linked_list_2.h"
#include "hash_table.h"

struct table
{
	size_t	size;
	slist_t** bucket;
	match_func_t	compare;
	hash_function_t	function;
};

/* Creates a hash table and returns it.
   Returns NULL upon failure. */   
hash_t *HashCreate(const size_t size, hash_function_t function, match_func_t compare) 
{
	size_t		i = 0;
	hash_t*		table = (hash_t*)malloc(sizeof(hash_t));
	if (!table)
	{
		fprintf(stderr, "In HashCreate, malloc failed\n");
		return NULL;
	}	
	
	table->size = size;
	table->compare = compare;
	table->function = function;
	table->bucket = (slist_t**)malloc(sizeof(slist_t));
	if (!table->bucket)
	{
		fprintf(stderr, "In HashCreate, malloc bucket failed\n");
		return NULL;
	}	
	
	for (; i < size; ++i)
	{
		table->bucket[i] = SListCreate();
	}
	
	return table;
}

/* Destroys the hash table.
   Call when done working with the table. 
   Time Complexity: O(n) 
   Note: It is legal to destroy NULL.*/
void HashDestroy(hash_t* table) 
{
	size_t 	i = 0;
	
	if (!table)
	{
		fprintf(stderr, "In HashCreate, malloc failed\n");
		return;
	}
	
	for (; i <= table->size; ++i)
	{
		SListDestroy(table->bucket[i]);
	}
	
	free(table->bucket);
	free(table);
}

/* Removes the list referred to by index.
   Returns true upon success and false upon failure.
   O(n) */
int HashRemove(const void* key, hash_t* table) 
{	
	if (!table)
	{
		fprintf(stderr, "In HashRemove, table input failed\n");
		return 0;
	}
	
	SListRemove(HashFind(table, table->compare, table->function, table->bucket[table->function((void*)key)]));
	
	return 1;
}

/* Inserts data as a new node, to before the element referred to by cur.
   Returns an iterator to the new element, or list end upon failure. 
   Time Complexity: O(1) */
int HashInsert(const void* key, hash_t* table, const void* data)
{	
	void* 	check = SListInsert(table->bucket[table->function((void*)key)], table->bucket[table->function((void*)key)]->dummy, (void*)data);
	if (!check)
	{
		fprintf(stderr, "In HashInsert, insert failed\n");
		return 0;
	}
	
	return 1;
}

/* Returns the total number of elements in the list. 
   Time Complexity: O(n) */
size_t HashSize(hash_t* table)
{
	size_t	i = 0;
	size_t	sum = 0;
	
	if (!table)
	{
		fprintf(stderr, "In HashSize, table input failed\n");
		return 0;
	}
	
	for (; i < table->size; ++i)
	{
		sum += SListCount(table->bucket[i]);
	}
	
	return sum;
}

/* Returns 1 if the list is empty, 0 if it's not.
   Time Complexity: O(n) */
int HashIsEmpty(hash_t* table)
{
	int  	result = 0;
	size_t	i = 0;
	
	for (; i < table->size; ++i)
	{
		result += (NULL == table->bucket[i]->first) ? 1 : 0;
	}
	
	if (result)
	{
		result = 1;
	}
	
	return result;
}

/* In the range of the list, find and return the first element 
   whose data matches the key when compared using the is_match_func function.
   The is_match_func function should return 1 if the data matches.
   Returns the first element that matches, or false if not found.
   O(n) */                                       
void* HashFind(hash_t* table, match_func_t is_match_func, hash_function_t function, const void *key)
{
	void*	result = NULL;
	size_t	i = 0;
	
	
	for (; i < table->size; ++i)
	{
		result = SListFind(table->bucket[i]->first, table->bucket[i]->dummy, is_match_func, (void*)key);
	
		if (result != table->bucket[i]->dummy)
		{
			break;
		}
	}
	
	return result;
}

/* Sends the data from each element in the hash table (in order) to the 
   function action_func, along with param. Stops if action_func 
   fails (return != 0), even if not all elements have been sent.
   Returns the value returned from the last call to action_func.
   Time Complexity: O(n) */                                
int HashForEach(hash_t* table, action_func_t action_func, const void *param)
{
	int 	result = 0;
	size_t	i = 0;
	
	for (; i < table->size; ++i)
	{
		result = SListForEach(table->bucket[i]->first, table->bucket[i]->dummy->next, action_func, (void*)param); 
		if (result)
		{
			break;
		}
	}
	
	return result;
}

