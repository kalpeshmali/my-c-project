/* 
    @file   CDLL_Def.c 
    @brief  Definition of Circular Double Linked List functions
    @author kalpesh mali
*/

#include "CDLL_Def.h"
#include <stdlib.h>
#include <stdio.h>

/*  Define the global tail pointer exactly once */
CDLLNODE *CDLLtail = NULL;

/* Function to create a new node 
@brief Create a new node and initialize it with user input
@returns Pointer to the newly created node or NULL on failure
@param void */

CDLLNODE * CDLLcreateNode(void)
{
    CDLLNODE * newnode = (CDLLNODE*) malloc (sizeof(CDLLNODE));
    return newnode;
}

/* Function to reverse the circular double linked list
 *@brief Reverse the order of nodes in the circular double linked list
 *@return 1 on success, 0 if the list is empty
 *@param void */

int CDLLReverse(void)
{
    return 1;
}
/* Function to search an element in the circular double linked list
 *@brief Search for a specific element in the circular double linked list
 *@return 1 on success, 0 if the list is empty or element not found
 *@param void */

int CDLLsearchElement(void)
{
    return 1;
}

/* Function to calculate the length of the circular double linked list
 *@brief Calculate the number of nodes in the circular double linked list
 *@return Length of the circular double linked list
 *@param void */

int CDLLLength(void)
{
    int count = 0;
    return count;
}

/* Function to add a node at a specific position in the circular double linked list
 *@brief Add a new node at the specified position in the circular double linked list
 *@return 1 on success, 0 on failure
 *@param void */

int CDLLaddNodePos(void)
{
    return 1;
}

/* Function to add a node at the end of the circular linked list
 *@brief Add a new node at the end of the circular linked list
 *@return 1 on success, 0 on failure
 *@param void */

int CDLLaddNodeLast(void)
{
    return 1;
}

/* Function to add a node at the beginning of the circular double linked list
 *@brief Add a new node at the beginning of the circular double linked list
 *@return 1 on success, 0 on failure
 *@param void */

int CDLLaddNodeFirst(void)
{
    return 1;
}

/* Function to display the circular double linked list
 *@brief Print all elements in the circular double linked list
 *@param void */

void CDLLdisplay(void)
{
    
}

/* Function to delete a node from the beginning of the circular double linked list
 *@brief Delete the first node from the circular double linked list
 *@return 1 on success, 0 if the list is empty
 *@param void */

int CDLLdeleteNodeFirst(void)
{
   return 1;
}

/* Function to delete a node from the end of the circular double linked list
 *@brief Delete the last node from the circular double linked list
 *@return 1 on success, 0 if the list is empty
 *@param void */

int CDLLdeleteNodeLast(void)
{
    return 1;
}

/* Function to delete a node from a specific position in the circular double linked list
 *@brief Delete the node at the specified position in the circular double linked list
 *@return 1 on success, 0 on failure
 *@param void */

int CDLLdeleteNodePos(void)
{
    return 1;
}