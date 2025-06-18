#include <stddef.h>
#include <stdio.h>

#include "singly_linked_list.h"
#include "singly_linked_list_2.h"

int main()
{
	int 	x = 11;
	int	y = 12;
	int	z = 13;
	int 	xy = 14;
	int	result = 0;
	
	void*	ptr = &x;
	
	size_t  count = 0;
	
	slist_iter_t runner;
	slist_iter_t iter;
	slist_iter_t iter2;
	slist_iter_t iter3;
	slist_iter_t iter4;
	slist_iter_t iter5;
	
	match_func_t match = Find;
	
	slist_t *slist = SListCreate();
	iter = SListInsert(slist, slist->dummy, ptr);
	ptr = &y;
	iter2 = SListInsert(slist, iter, ptr);
	ptr = &z;
	iter3 = SListInsert(slist, iter2, ptr);
	ptr = &z;
	iter4 = SListInsert(slist, iter3, ptr);
	ptr = &xy;
	iter5 = SListInsert(slist, iter4, ptr);
	

	
	ptr = &y;
	runner = SListFind(iter, iter4, match, ptr);
	
	count = SListCount(slist);
	printf ("SListCount result is %lu\n", count);
	
	runner = SListBegin(slist);
	printf ("SListBegin result is %d\n", *(int*)runner->data);
	
	runner = SListEnd(slist);
	printf ("SListEnd result is %d\n", *(int*)runner->data);
	
	runner = SListNext(iter2);
	printf ("SListNext result is %d\n", *(int*)runner->data);
		
	result = SListIterIsEqual(iter, iter2);
	printf ("SListIterIsEqual result is %d\n", result);
	
	ptr = SListGetData(iter);
	printf ("SListNext result is %d\n", *(int*)ptr);
	
	ptr = &y;
	
	runner = iter; 
	
	SListSetData(iter, ptr);
	printf ("SListSetData result is %d\n", *(int*)runner->data);
	
	runner = SListRemove(iter2);
	printf ("SListRemove result is %d\n", *(int*)runner->data);
	
	runner = SListRemove(iter);
	printf ("SListRemove result is %d\n", *(int*)runner->data);
	
	result =  SListIsEmpty(slist);
	printf ("SListIsEmpty result is %d\n", result);
	
	SListDestroy(slist);
	
	return 0;
}

int Find(const void *data, void *param)
{
	int result = 0;
	
	result = *(int*)data;
	
	if (result == *(int*)param)
	{
		printf("result of Find %d\n", result);
		return result;
	}
	
	return 0;
}
