#ifndef __SLIST_ADDITIONAL_H__
#define __SLIST_ADDITIONAL_H__

#include "singly_linked_list.h"

int Multiply(void *data, void *param);
int Find(const void *data, void *param);

struct slist
{
	slist_iter_t	first;
	slist_iter_t	dummy;
	
};

struct slist_node
{
	void*		data;
	slist_iter_t	next;
};








#endif 		/* __SLIST_ADDITIONAL_H__ */
