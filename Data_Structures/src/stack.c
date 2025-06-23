/**
 * Implements a generic stack data structure with dynamic memory management.
 * Supports typical stack operations: create, destroy, push, pop, peek, size, capacity, and empty check.
 *
 * Author: Ben
 * Reviewed by: Shay
 * Date: 2024-09-22
 *
 */

#include <stdlib.h>  /* malloc, free */
#include <string.h>  /* memcpy */
#include <stdio.h>   /* fprintf, stderr */
#include "stack.h"

struct stack
{
	void*	start_memory;    /* Pointer to the beginning of allocated stack memory */
	void*	curr_addr;       /* Pointer to current top position in stack */
	size_t	element_size;    /* Size of each element */
	size_t	capacity;        /* Current used size in bytes */
	size_t	full_capacity;   /* Maximum capacity in elements */
};


/* Function to create a stack */
stack_t* StackCreate(size_t element_size, size_t capacity)
{
	size_t	total_size = sizeof(stack_t) + (capacity * element_size); 
	stack_t* stack = (stack_t*)malloc(total_size);
		
	if (element_size <= 0 || capacity <= 0)
	{
		fprintf(stderr, "incorrect input in StackCreate\n");
		return NULL;
	}
	
	if (!stack)
	{
		fprintf(stderr, "malloc failed\n");
		return NULL;
	}
	
	stack->start_memory = (char*)stack + sizeof(stack_t);
	stack->curr_addr = stack->start_memory;
	stack->element_size = element_size;
	stack->capacity = 0;
	stack->full_capacity = capacity;
	
	return stack;
}

/* Function to destroy the stack */
void StackDestroy(stack_t *stack)
{
	if (!stack)
	{
		fprintf(stderr, "StackDestroy wrong input\n");
		return;
	}
	
	free(stack->start_memory);
}

/* Function to pop an element from the stack */
void StackPop(stack_t *stack)
{
	if (!stack)
	{
		fprintf(stderr, "StackPop wrong input\n");
		return;
	}
	
	if (!stack->capacity)
	{
		fprintf(stderr, "StackPop error. empty stack\n");
		return;
	}
	
	stack->curr_addr = (char*)stack->curr_addr - stack->element_size;
	stack->capacity -= stack->element_size;	
}

/* Function to push an element onto the stack */
void StackPush(stack_t *stack, void *element)
{
	if (!stack)
	{
		fprintf(stderr, "StackPush wrong input\n");
		return;
	}
	
	if (stack->capacity == stack->full_capacity)
	{
		fprintf(stderr, "stack full\n");
		return;
	}
	
	memcpy(stack->curr_addr, element, stack->element_size);
	stack->curr_addr = (char*)stack->curr_addr + stack->element_size;
	stack->capacity += stack->element_size;
}

/* Function to peek the top element of the stack */
void* StackPeek(stack_t *stack)
{
	if (!stack)
	{
		fprintf(stderr, "StackPeek wrong input\n");
		return NULL;
	}
	
	return (char*)stack->curr_addr - stack->element_size;
}

/* Function to get the current size of the stack */
size_t StackSize(stack_t *stack)
{
	if (!stack)
	{
		fprintf(stderr, "StackSize wrong input\n");
		return -1;
	}
	
	return stack->full_capacity;
}

/* Function to check if the stack is empty */
int StackIsEmpty(stack_t *stack)
{
	int result = 0;
	
	if (!stack)
	{
		fprintf(stderr, "StackIsEmpty wrong input\n");
		return -1;
	}
	
	if (stack->capacity)
	{
		result = 1;
	}
	
	return result;
}

/* Function to get the capacity of the stack */
size_t StackCapacity(stack_t *stack)
{
	if (!stack)
	{
		fprintf(stderr, "StackCapacity wrong input\n");
		return -1;
	}
	
	return stack->full_capacity - stack->capacity;
}
