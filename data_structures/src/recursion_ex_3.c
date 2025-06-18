/**
 * Implements sorting of a stack using an auxiliary stack and recursion.
 *
 * SortStack: Recursively sorts elements in the main stack using the filler stack for temporary storage.
 * StackCheck: Helper function to verify and transfer elements between stacks to assist sorting.
 *
 * Uses stack operations from the "stack.h" library:
 * - StackPeek: Returns the top element without removing it.
 * - StackPop: Removes the top element.
 * - StackPush: Adds an element to the top.
 * - StackIsEmpty: Checks if the stack is empty.
 * - StackCapacity: Returns stack capacity.
 *
 * Author: Ben
 * Date: 2024-09-30
 */

#include "stack.h"
#include "recursion_ex_3.h"

#define MAGIC_NUMBER 0xFFF00FFF

size_t	 check = 0;

stack_t* SortStack(stack_t *stack, stack_t *filler)	
{	
	void*	temp_one = NULL;
	void*	temp_two = NULL;
	
	if (MAGIC_NUMBER == check)
	{
		return stack;
	}
	
	while (0 != StackIsEmpty(stack))
	{
		temp_one = StackPeek(stack);
		
		StackPop(stack);

		temp_two = StackPeek(stack);
		
		if (*(int*)temp_one > *(int*)temp_two)
		{
			if (check < *(int*)temp_one)
			{
				check = *(int*)temp_one;
			}
			StackPush(filler, temp_one);
		}
		else
		{
			if (check < *(int*)temp_two)
			{
				check = *(int*)temp_two;
			}
			StackPush(filler, temp_two);
			StackPush(stack, temp_one);
		}
	}	
	
	stack = StackCheck(filler, stack);
	SortStack(stack, filler);
	
	return NULL;
}

stack_t* StackCheck(stack_t* stack, stack_t* filler)
{
	void*	temp_one = NULL;
	void*	temp_two = NULL;
	
	temp_one = StackPeek(stack);
	StackPop(stack);
	temp_two = StackPeek(stack);
	
	while (*(int*)temp_one < *(int*)temp_two)
	{
		StackPush(filler, temp_one);
		temp_one = temp_two;
		StackPop(stack);
		temp_two = StackPeek(stack);
		
		if ((check == *(int*)StackPeek(stack) && StackCapacity(stack) == 8))
		{
			StackPush(filler, StackPeek(stack));
			temp_one = NULL;
			temp_two = NULL;
			check = MAGIC_NUMBER;
			return filler;
		}
	}
	
	while (!StackIsEmpty(stack)) 
	{
		temp_one = StackPeek(stack);
		StackPush(filler, temp_one);	
		StackPop(filler);
	}
	
	return filler;
}
					
