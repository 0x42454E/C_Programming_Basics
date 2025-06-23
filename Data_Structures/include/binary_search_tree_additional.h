#ifndef __BINARY_SEARCH_TREE_ADDITIONAL_H__
#define __BINARY_SEARCH_TREE_ADDITIONAL_H__
#include "binary_search_tree.h"

bst_t *NewNode(void* data, compare_func_t cmp);
bst_t *SwitchValues(bst_t* bst, int data);


int CompareFunc(const void *data1, const void *data2);
int Action(void *data, void *parameter);




#endif /*__BINARY_SEARCH_TREE_ADDITIONAL_H__*/
