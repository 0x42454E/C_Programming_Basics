#include <stdio.h>

#include "binary_search_tree.h"
#include "binary_search_tree_additional.h"




int main()
{
	compare_func_t cmp = CompareFunc;
	action_function_t action_func = Action;
	bst_t *root = BstCreate(cmp);
	void*	temp = NULL;
	void*	temp2 = NULL;
	const void* ptr = NULL;
	int	x = 2;
	int	z = 1;
	int 	y = 4;
	int	w = 3;
	int	o = 5;
	int	k = 6;
	int  i = 0;
	
	ptr = &x;
	
		
		printf("check is %d\n", BstInsert(root, &x));
		temp = &z;
	BstInsert(root, &z);
		temp = &o;
	BstInsert(root, &o);
		temp = &y;
	BstInsert(root, &y);
		temp = &w;
	BstInsert(root, &w);
		temp = &k;
	
		printf("check is %d\n", BstInsert(root, &k));
	
	
	
	printf("size is %lu\n", BstSize(root));
	temp = BstFind(root, temp);
	
	temp = &x;
	
	BstForEach(root, action_func, temp);
	
	BstRemove(root, ptr);
	ptr = &y;	
	
	temp = BstFind(root, temp2);
	
	/*printf("finally %d\n", *(int*)BstFind((void*)root, temp2));*/
	
	printf("check is %d\n", BstIsEmpty(root));
	
	
	
	
	BstDestroy(root);
	
	return 0;
}


int Action(void *data, void *parameter)
{
	if (!data)
	{
		return 0;
	}
	
	 *(int*)data *= *(int*)parameter;
	 
	 return 1;
}


int CompareFunc(const void *data1, const void *data2)
{
	if (!data1 || !data2)
	{
		return 1;
	}
	
	return (*(int*)data1 - *(int*)data2);
}
