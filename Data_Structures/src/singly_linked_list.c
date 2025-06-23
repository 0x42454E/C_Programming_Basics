/* Ben
reviewed by Chananya 29.9 */ 
#include <stdio.h>
#include <stdlib.h>
#include "singly_linked_list.h"
#include "singly_linked_list_2.h"

/* Creates an empty list and returns it.
   Returns NULL upon failure.
   Call SListDestroy when done working with the list. */
slist_t *SListCreate(void) 
{
	slist_t* slist = (slist_t*)malloc(sizeof(slist_t));
	slist->dummy = (slist_iter_t)malloc(sizeof(slist_iter_t));
	if (!slist)
	{
		fprintf(stderr, "Failure creating list\n");
		return NULL;
	}
	else if (!slist->dummy)
	{
		fprintf(stderr, "Failure creating list\n");
		return NULL;
	}
	
	slist->dummy->next = NULL;
	slist->first = NULL;
	
	return slist;
}

/* Destroys the list.
   Call when done working with the list. 
   Time Complexity: O(n) 
   Note: It is legal to destroy NULL.*/
void SListDestroy(slist_t *list) 
{
	slist_iter_t 	runner = list->first;
	void*		temp = NULL;
	
	if (!list->first)
	{
		free(list);
		printf("Boom\n");
		return;
	}
	
	while (runner->next != list->dummy && !temp)
	{	
		temp = runner;
		runner = runner->next;
		free(temp);
	}
	
	free(runner);
	free(list->dummy);
	free(list);
	printf("HAHA\n");
}

/* Returns an iterator to the first element.
   If the list is empty returns SListEnd.
   Time Complexity: O(1) */
slist_iter_t SListBegin(const slist_t *list)
{
	if (NULL == list->first)
	{
		return list->dummy;
	}
	
	return list->first;
}

/* Returns an iterator to beyond the last element (out of range).
   Time Complexity: O(1) */
slist_iter_t SListEnd(const slist_t *list) 
{
	return list->dummy->next;
}

/* Returns an iterator to the element following cur.
   Do not use or go beyond SListEnd().    
   Time Complexity: O(1) */
slist_iter_t SListNext(slist_iter_t iter) 
{
	return iter->next;
}

/* Returns true if both iterators refer to the same element. */
int SListIterIsEqual(slist_iter_t one, slist_iter_t other) 
{
	return one == other ? 1 : 0;
}

/* Returns the data from the element referred to by iter. */
void *SListGetData(slist_iter_t iter) 
{
	return iter->data;
}

/* Sets the data in the node refered to by iter. */
void SListSetData(slist_iter_t iter, void *data) 
{
	iter->data = data;
}

/* Inserts data as a new element, to before the element referred to by cur.
   Returns an iterator to the new element, or SListEnd(list) upon failure. 
   Time Complexity: O(1) */
slist_iter_t SListInsert(slist_t *list, slist_iter_t where, void *data) 
{
	slist_iter_t current = (slist_iter_t)malloc(sizeof(slist_iter_t));
	if (!current)
	{
		fprintf(stderr, "Can't insert. Empty list.\n");
		return list->dummy;
	}
	else if (!list->dummy->next || where == list->dummy->next)
	{
		list->dummy->next = current;
		current->next = list->dummy;
		list->first = current;
	}
	else if (where == list->first)
	{
		list->first = current;
	}
	
	current->data = data;
	current->next = where->next;
	where->next = current;
	
	return current;
}

/* Removes the node referred to by cur.
   Returns an iterator to the element following cur.
   O(1) */
slist_iter_t SListRemove(slist_iter_t iter) 
{
	slist_iter_t	temp = iter->next;
	if (iter->next == iter->next->next)
	{
		iter->next->next = NULL;		
	}
	
	iter->next = iter->next->next;
	free(temp);
	
	return iter->next;
}

/* Returns 1 if the list is empty, 0 if it's not.
   Time Complexity: O(1) */
int SListIsEmpty(const slist_t *list) 
{	
	return NULL == list->first ? 1 : 0;
}

int Sum(void *data, void *param) 
{
	(*(size_t*)param)++;
	
	return 0;
}

/* Returns the number of elements in the list. 
   Time Complexity: O(n) */
size_t SListCount(const slist_t *list)
{
	size_t 	count = 0;
	void*	temp = &count;
	int 	result = 0;
	action_func_sll_t cal_count = Sum;
	
	if (!list->dummy->next)
	{
		fprintf(stderr, "Can't count. Empty list.\n");
		return 0;
	}
	
	result = SListForEach(list->first, list->dummy, cal_count, temp);
	
	return count;
}


/* In the range between begin and end, find and return the first element 
   whose data matches param when compared using the is_match_func function.
   The is_match_func function should return 1 if the data matches.
   Returns the first element that matches, or to if not found.
   O(n) */
slist_iter_t SListFind(slist_iter_t from, slist_iter_t to,  match_func_sll_t is_match_func, void *param) 
{
	slist_iter_t runner = from;
	int	     result = 0;
	
	while (runner != to)
	{
		result = is_match_func(runner->data, param);
		if (result)
		{
			break;
		}
		
		runner = runner->next;
	}
	
	return runner;
}
                       
/* Sends the data from each element in the list (in order) to the 
   function action_func, along with param. Stops if action_func 
   fails (return != 0), even if not all elements have been sent.
   Returns the value returned from the last call to action_func.
   Time Complexity: O(n) */
	
int SListForEach(slist_iter_t from, slist_iter_t to, action_func_sll_t action_func, void *param) 
{
	int 		result = 0;
	slist_iter_t	runner = from;
	
	if (NULL == from || NULL == to || NULL == runner)
	{
		return 0;
	}
	
	while (1)
	{
		result = action_func(runner->data, param);
		runner = runner->next;
		
		if (runner == to->next || result != 0)
		{
			break;
		}
	}
	
	return result;	
}
                
                
