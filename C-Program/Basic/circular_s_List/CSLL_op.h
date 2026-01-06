#ifndef CSLL_OP_H
#define CSLL_OP_H

#include <stdio.h>
/* Enumerated constants for Circular Linked List operations */
enum CSLL_op
{
    CSLL_EXIT_OP=0,                  //exit operation
    CSLL_DISPLAY,                    //display linked list
    CSLL_LENGTH,                     //length of linked list
    CSLL_ADD_NODE_FIRST,             //add node at first
    CSLL_ADD_NODE_LAST,              //add node at last
    CSLL_ADD_NODE_POS,               //add node at given position
    CSLL_DELETE_NODE_FIRST,          //delete node at first
    CSLL_DELETE_NODE_LAST,           //delete node at last
    CSLL_DELETE_NODE_POS,            //delete node at given position
    CSLL_SEARCH_ELEMENT,             //search element in linked list
    CSLL_REVERSE_LINK_LIST,          //reverse linked list
};

/* Function declaration for circular linked list operations */
int circularSingleLinkListOp(void);

#endif 
