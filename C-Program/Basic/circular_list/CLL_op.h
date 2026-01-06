#ifndef CLL_OP_H
#define CLL_OP_H

#include <stdio.h>
/* Enumerated constants for Circular Linked List operations */
enum CLL_op
{
    CLL_EXIT_OP=0,                  //exit operation
    CLL_DISPLAY,                    //display linked list
    CLL_LENGTH,                     //length of linked list
    CLL_ADD_NODE_FIRST,             //add node at first
    CLL_ADD_NODE_LAST,              //add node at last
    CLL_ADD_NODE_POS,               //add node at given position
    CLL_DELETE_NODE_FIRST,          //delete node at first
    CLL_DELETE_NODE_LAST,           //delete node at last
    CLL_DELETE_NODE_POS,            //delete node at given position
    CLL_SEARCH_ELEMENT,             //search element in linked list
    CLL_REVERSE_LINK_LIST,          //reverse linked list
};

/* Function declaration for circular linked list operations */
int circularSingleLinkListOp(void);

#endif 
