#ifndef SLL_OP_H
#define SLL_OP_H

#include <stdio.h>

/* Enumerated constants for single linked list operations */
enum SLL_op
{
    EXIT_LINK_LIST_OP=0,        //exit operation
    DISPLAY_LINK_LIST,          //display linked list
    LENGTH_LINK_LIST,           //length of linked list
    ADD_NODE_FIRST,             //add node at first
    ADD_NODE_LAST,              //add node at last
    ADD_NODE_POS,               //add node at given position
    DELETE_NODE_FIRST,          //delete node at first
    DELETE_NODE_LAST,           //delete node at last
    DELETE_NODE_POS,            //delete node at given position
    SEARCH_ELEMENT,             //search element in linked list
    REVERSE_LINK_LIST,          //reverse linked list
};

/* Function declaration for single linked list operations */
int singleLinkListOp(void);

#endif 
