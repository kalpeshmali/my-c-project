#ifndef CDLL_OP_H
#define CDLL_OP_H

#include <stdio.h>
/* Enumerated constants for Circular Linked List operations */
enum CDLL_op
{
    CDLL_EXIT_OP=0,                  //exit operation
    CDLL_DISPLAY,                    //display linked list
    CDLL_LENGTH,                     //length of linked list
    CDLL_ADD_NODE_FIRST,             //add node at first
    CDLL_ADD_NODE_LAST,              //add node at last
    CDLL_ADD_NODE_POS,               //add node at given position
    CDLL_DELETE_NODE_FIRST,          //delete node at first
    CDLL_DELETE_NODE_LAST,           //delete node at last
    CDLL_DELETE_NODE_POS,            //delete node at given position
    CDLL_SEARCH_ELEMENT,             //search element in linked list
    CDLL_REVERSE_LINK_LIST,          //reverse linked list
};

/* Function declaration for circular double linked list operations */
int circularDoubleLinkListOp(void);

#endif 
