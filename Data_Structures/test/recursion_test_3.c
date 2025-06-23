#include <stdio.h>
#include "stack.h"
#include "recursion_ex_3.h"

int main()
{
	int 	x = 11;
	int	y = 6;
	int 	z = 4;
	int	xx = 20;
	int	yy = 12;
	int	zz = 1;
	
	stack_t* stack = StackCreate(sizeof(int), 6);
	stack_t* filler = StackCreate(sizeof(int), 6);
	
	void*	ptr = NULL;
	
	ptr = &x;
	StackPush(stack, ptr);
	
	ptr = &y;	
	StackPush(stack, ptr);
	
	ptr = &z;
	StackPush(stack, ptr);
	
	ptr = &xx;
	StackPush(stack, ptr);
	
	ptr = &yy;
	StackPush(stack, ptr);
	
	ptr = &zz;
	StackPush(stack, ptr);
	
	stack = SortStack(stack, filler);
	
	printf("%d\n", *(int*)StackPeek(stack));
	
	StackPop(stack);
	StackPop(stack);
	
	printf("%d\n", *(int*)StackPeek(stack));
	
	
	printf("%d\n", *(int*)StackPeek(stack));
	
	
	printf("%d\n", *(int*)StackPeek(stack));
	
	StackDestroy(stack);
	
	return 0;
}
