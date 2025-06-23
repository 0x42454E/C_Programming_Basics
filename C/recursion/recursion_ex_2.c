/* Ben
reviewed by Or 30.09*/

#include <stdlib.h>
#include "recursion_ex_2.h"

node_t* FlipList(node_t* node) /* receives the first node of the list 
                                   returns the new head upon completion */
{
    node_t* flip = node;

    if (!node || !node->next) 
    {
        return NULL;
    }

    while (!flip->next)
    {
    	flip = node->next; 
    }

    flip->next = node; 
    flip = flip->next;
    node = node->next;
    node->next = NULL;

    
    return FlipList(flip);
}



