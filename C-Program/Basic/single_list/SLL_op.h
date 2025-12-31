#ifndef SLL_OP_H
#define SLL_OP_H

#include <stdio.h>

enum SLL_op
{
    EXIT_LINK_LIST_OP=0,
    DISPLAY_LINK_LIST,
    LENGTH_LINK_LIST,
    ADD_NODE_FIRST,
    ADD_NODE_LAST,
    ADD_NODE_POS,
    DELETE_NODE_FIRST,
    DELETE_NODE_LAST,
    DELETE_NODE_POS,
    SEARCH_ELEMENT,
    REVERSE_LINK_LIST,
};

int singleLinkListOp(void);

#endif 
