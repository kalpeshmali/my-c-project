#ifndef DLL_OP_H
#define DLL_OP_H    

/* Function declaration for double linked list operations */

int doubleLinkListOp(void);

/* Define operation codes for double linked list menu */
enum DLL_op
{
    DLL_EXIT_OP=0,          //exit operation
    DLL_DISPLAY,            //display linked list
    DLL_LENGTH,             //length of linked list
    DLL_ADD_NODE_FIRST,     //add node at first
    DLL_ADD_NODE_LAST,      //add node at last
    DLL_ADD_NODE_POS,       //add node at given position
    DLL_DELETE_NODE_FIRST,  //delete node at first
    DLL_DELETE_NODE_LAST,   //delete node at last
    DLL_DELETE_NODE_POS,    //delete node at given position
    DLL_SEARCH_ELEMENT,     //search element in linked list
    DLL_REVERSE_LINK_LIST,  //reverse linked list
};

#endif