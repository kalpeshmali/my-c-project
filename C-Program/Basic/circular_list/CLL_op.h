#ifndef CLL_OP_H
#define CLL_OP_H

#include <stdio.h>

enum CLL_op
{
    CLL_EXIT_OP=0,
    CLL_DISPLAY,
    CLL_LENGTH,
    CLL_ADD_NODE_FIRST,
    CLL_ADD_NODE_LAST,
    CLL_ADD_NODE_POS,
    CLL_DELETE_NODE_FIRST,
    CLL_DELETE_NODE_LAST,
    CLL_DELETE_NODE_POS,
    CLL_SEARCH_ELEMENT,
    CLL_REVERSE_LINK_LIST,
};

int circularLinkListOp(void);

#endif 
