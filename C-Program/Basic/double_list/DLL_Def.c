/* @file DLL_Def.c 
   @author kalpesh mali
*/
/*header files*/
#include <stdlib.h>
#include <stdio.h>
#include "DLL_Def.h"

/* Global head pointer for the double linked list */
DLLNODE *DLLhead = NULL;

/* Function to create a new node
 *@brief Create a new node and initialize it with user input
 *@return Pointer to the newly created node or NULL on failure
 *@param void */

DLLNODE *DLLcreateNode(void)
{
    DLLNODE *newnode = (DLLNODE *)malloc(sizeof(DLLNODE));
    if (newnode == NULL)
    {
        printf("malloc failure to create a new node\n");
        return NULL;
    }
    else
    {
        printf("ENTER THE NUMBER : ");
        scanf("%d", &newnode->data);
        printf("\n");
        newnode->next = NULL;
        newnode->prev = NULL;
        return newnode;
    }
    return NULL;
}

/* Function to reverse the double linked list
 *@brief Reverse the order of nodes in the double linked list
 *@return 1 on success, 0 if the list is empty
 *@param void */

int DLLReverse(void)
{
    if (DLLhead == NULL)
    {
        printf("LINK LIST IS EMPTY \n");
        return 0;
    }
    else
    {
        DLLNODE *prev = NULL;
        DLLNODE *curr = NULL;
        DLLNODE *nextt = NULL;

        curr = DLLhead;

        while (curr != NULL)
        {
            nextt = curr->next;
            curr->next = prev;
            curr->prev = nextt;
            prev = curr;
            curr = nextt;
        }
        DLLhead = prev;
    }
    return 1;
}

/* Function to search an element in the double linked list
 *@brief Search for a specific element in the double linked list
 *@return 1 on success, 0 if the list is empty or element not found
 *@param void */

int DLLsearchElement(void)
{
    if (DLLhead == NULL)
    {
        printf("LINK LIST IS EMPTY\n");
        return 0;
    }
    else
    {
        DLLNODE *trav = DLLhead;
        int num = 0, count = 1;
        printf("ENTER THE ELEMENT TO SEARCH : ");
        if (scanf("%d", &num) != 1)
        {
            printf("INVALID INPUT\n");
            return 0;
        }
        while (trav != NULL)
        {
            if (trav->data == num)
            {
                printf("ELEMENT %d FOUND AT POSITION %d\n", num, count);
                return 1;
            }
            trav = trav->next;
            count++;
        }
        printf("ELEMENT %d NOT FOUND IN LINK LIST\n", num);
    }
    return 1;
}

/* Function to get the length of the double linked list
 *@brief Get the number of nodes in the double linked list
 *@return Length of the list
 *@param void */

int DLLLength(void)
{
    int length = 0;
    DLLNODE *trav = DLLhead;
    while (trav != NULL)
    {
        length++;
        trav = trav->next;
    }
    return length;
}

/* Function to display the double linked list
 *@brief Print all elements in the double linked list
 *@return void
 *@param void */

void DLLdisplay(void)
{
    if (DLLhead == NULL)
    {
        printf("LINK LIST IS EMPTY\n");
        return;
    }
    else
    {
        DLLNODE *trav = DLLhead;
        printf("LINK LIST ELEMENTS ARE : \n");
        while (trav != NULL)
        {
            printf("%d ", trav->data);
            trav = trav->next;
        }
        printf("\n");
    }
}

/* Function to add a node at a specific position in the double linked list
 *@brief Add a new node at the specified position in the double linked list
 *@return 1 on success, 0 on failure
 *@param void */

int DLLaddNodePos(void)
{
    int length = DLLLength();
    if (length == 0)
    {
        printf("LINK LIST IS EMPTY. ADDING NODE AT FIRST POSITION\n");
        return DLLaddNodeFirst();
    }
    int pos = 0, count = 1;
    printf("ENTER THE POSITION TO ADD NODE (1 to %d) : ", length + 1);
    scanf("%d", &pos);
    if ((pos < 1) || (pos > length + 1))
    {
        printf("INVALID POSITION\n");
        return 0;
    }
    if (pos == 1)
    {
        return DLLaddNodeFirst();
    }
    else if (pos == length + 1)
    {
        return DLLaddNodeLast();
    }
    else
    {
        DLLNODE *newNode = DLLcreateNode();
        if (newNode == NULL)
        {
            printf("MEMORY ALLOCATION FAILED\n");
            return 0;
        }
        DLLNODE *trav = DLLhead;
        while (count < pos - 1)
        {
            trav = trav->next;
            count++;
        }
        newNode->next = trav->next;
        newNode->prev = trav;
        trav->next->prev = newNode;
        trav->next = newNode;
    }
    return 1;
}

/* Function to add a node at the end of the double linked list
 *@brief Add a new node at the end of the double linked list
 *@return 1 on success, 0 on failure
 *@param void */

int DLLaddNodeLast(void)
{
    DLLNODE *newNode = DLLcreateNode();
    if (newNode == NULL)
    {
        printf("MEMORY ALLOCATION FAILED\n");
        return 0;
    }
    if (DLLhead == NULL)
    {
        DLLhead = newNode;
        return 1;
    }
    else
    {
        DLLNODE *trav = DLLhead;
        while (trav->next != NULL)
        {
            trav = trav->next;
        }
        trav->next = newNode;
        newNode->prev = trav;
    }
    return 1;
}

/* Function to add a node at the beginning of the double linked list
 *@brief Add a new node at the beginning of the double linked list
 *@return 1 on success, 0 on failure
 *@param void */

int DLLaddNodeFirst(void)
{
    DLLNODE *newNode = DLLcreateNode();
    if (newNode == NULL)
    {
        printf("MEMORY ALLOCATION FAILED\n");
        return 0;
    }
    newNode->next = DLLhead;
    newNode->prev = NULL;
    if (DLLhead != NULL)
        DLLhead->prev = newNode;
    DLLhead = newNode;
    return 1;
}

/* Function to delete a node from the beginning of the double linked list
 *@brief Delete the first node from the double linked list
 *@return 1 on success, 0 if the list is empty
 *@param void */

int DLLdeleteNodeFirst(void)
{
    if (DLLhead == NULL)
    {
        printf("LINK LIST IS EMPTY\n");
        return 0;
    }
    DLLNODE *temp = DLLhead;
    DLLhead = DLLhead->next;
    if (DLLhead != NULL)
        DLLhead->prev = NULL;
    printf("%d DELETED \n", temp->data);
    free(temp);
    return 1;
}

/* Function to delete a node from the end of the double linked list
 *@brief Delete the last node from the double linked list
 *@return 1 on success, 0 if the list is empty
 *@param void */

int DLLdeleteNodeLast(void)
{
    if (DLLhead == NULL)
    {
        printf("LINK LIST IS EMPTY\n");
        return 0;
    }
    DLLNODE *trav = DLLhead;
    // If only one node
    if (trav->next == NULL)
    {
        printf("%d DELETED\n", trav->data);
        free(trav);
        DLLhead = NULL;
        return 1;
    }
    while (trav->next != NULL)
    {
        trav = trav->next;
    }
    trav->prev->next = NULL;
    printf("%d DELETED\n", trav->data);
    free(trav);
    return 1;
}

/* Function to delete a node from a specific position in the double linked list
 *@brief Delete a node at the specified position in the double linked list
 *@return 1 on success, 0 on failure
 *@param void */

int DLLdeleteNodePos(void)
{
    int length = DLLLength();
    if (length == 0)
    {
        printf("LINK LIST IS EMPTY\n");
        return 0;
    }
    int pos = 0, count = 1;
    printf("ENTER THE POSITION TO DELETE NODE (1 to %d) : ", length);
    scanf("%d", &pos);
    if ((pos < 1) || (pos > length))
    {
        printf("INVALID POSITION\n");
        return 0;
    }
    if (pos == 1)
    {
        return DLLdeleteNodeFirst();
    }
    else if (pos == length)
    {
        return DLLdeleteNodeLast();
    }
    else
    {
        DLLNODE *trav = DLLhead;
        while (count < pos)
        {
            trav = trav->next;
            count++;
        }
        trav->prev->next = trav->next;
        trav->next->prev = trav->prev;
        printf("%d DELETED \n", trav->data);
        free(trav);
    }
    return 1;
}