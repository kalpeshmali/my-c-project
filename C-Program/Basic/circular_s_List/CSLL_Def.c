/* 
    @file   CSLL_Def.c 
    @brief  Definition of Circular Linked List functions
    @author kalpesh mali
*/

#include "CSLL_Def.h"
#include <stdlib.h>
#include <stdio.h>

/*  Define the global tail pointer exactly once */
CSLLNODE *CSLLtail = NULL;

/* Function to create a new node 
@brief Create a new node and initialize it with user input
@returns Pointer to the newly created node or NULL on failure
@param void */

CSLLNODE * CSLLcreateNode(void)
{
    CSLLNODE * newnode = (CSLLNODE*) malloc (sizeof(CSLLNODE));
    if(newnode == NULL)
    {
        printf("malloc failure to create a new node\n");
        return NULL;
    }
    else
    {
        printf("ENTER THE NUMBER : ");
        scanf("%d",&newnode->data);
        printf("\n");
        newnode->next = newnode;
        return newnode;
    }
}

/* Function to reverse the circular linked list
 *@brief Reverse the order of nodes in the circular linked list
 *@return 1 on success, 0 if the list is empty
 *@param void */

int CSLLReverse(void)
{
    if ( CSLLtail == NULL)
    {
        printf("CIRCULAR LINK LIST IS EMPTY\n");
        return 0;
    }
    else
    {
        CSLLNODE *head = CSLLtail->next;
        CSLLNODE *current = head;
        CSLLNODE *prev = CSLLtail;
        CSLLNODE *nextt = NULL;
        do
        {
            nextt = current->next;
            current->next = prev;
            prev = current;
            current = nextt;
        }while(current != head);

        CSLLtail = head;
        return 1;
    }
}
/* Function to search an element in the circular linked list
 *@brief Search for a specific element in the circular linked list
 *@return 1 on success, 0 if the list is empty or element not found
 *@param void */

int CSLLsearchElement(void)
{
    if (CSLLtail == NULL)
    {
        return 0;
    }
    int element,count = 0;
    printf("ENTER THE ELEMENT TO BE SEARCHED : ");
    scanf("%d",&element);
    CSLLNODE *trav = CSLLtail->next;
    do
    {
        count ++;
        if(trav->data == element)
        {
            printf("ELEMENT FOUND AT %d POSITION\n", count);
            
            return 1;
        }
        trav = trav->next;
        
    }while(trav != CSLLtail->next);
    printf("ELEMENT NOT FOUND\n");
    return 0;
}

/* Function to calculate the length of the circular linked list
 *@brief Calculate the number of nodes in the circular linked list
 *@return Length of the circular linked list
 *@param void */

int CSLLLength(void)
{
    int count = 0;
   if (CSLLtail == NULL)
   {
       return count;
   }
   else
   {
       CSLLNODE *trav = CSLLtail->next;
       do
       {
           count++;
           trav = trav->next;
       }while(trav != CSLLtail->next);  
   }
   return count;
}

/* Function to add a node at a specific position in the circular linked list
 *@brief Add a new node at the specified position in the circular linked list
 *@return 1 on success, 0 on failure
 *@param void */

int CSLLaddNodePos(void)
{
    if(CSLLtail == NULL)
    {
        printf("CIRCULAR LINK LIST IS EMPTY\n");
        return 0;
    }
    else
    {
        int pos, len, i;
        len = CSLLLength();
        printf("ENTER THE POSITION TO ADD NODE (1 to %d) : ", len+1);
        scanf("%d",&pos);
        if (pos < 1 || pos > len + 1)
        {
            printf("INVALID POSITION\n");
            return 0;
        }
        else if (pos == 1)
        {
            CSLLaddNodeFirst();
        }
        else if (pos == len + 1)
        {
            CSLLaddNodeLast();
        }
        else
        {
            CSLLNODE *newNode = CSLLcreateNode();
            if (newNode == NULL)
            {
                printf("Node not able to create\n");
                return 0;
            }
            else
            {
                CSLLNODE *trav = CSLLtail->next;
                for (i = 1; i < pos - 1; i++) 
                {
                    trav = trav->next;
                }
                newNode->next = trav->next;
                trav->next = newNode;
            }
        }
    }
    return 1;
}

/* Function to add a node at the end of the circular linked list
 *@brief Add a new node at the end of the circular linked list
 *@return 1 on success, 0 on failure
 *@param void */

int CSLLaddNodeLast(void)
{
    CSLLNODE *newNode = CSLLcreateNode();
    if (newNode == NULL)
    {
        printf("Node not able to create\n");
        return 0;
    }
    else 
    {   if (CSLLtail == NULL)
        {
            CSLLtail = newNode;
            newNode->next = newNode;
        }
        else
        {
            newNode->next = CSLLtail->next;
            CSLLtail->next = newNode;
            CSLLtail = newNode;
        }
    }
    return 1;
}

/* Function to add a node at the beginning of the circular linked list
 *@brief Add a new node at the beginning of the circular linked list
 *@return 1 on success, 0 on failure
 *@param void */

int CSLLaddNodeFirst(void)
{
    CSLLNODE *newNode = CSLLcreateNode();
    if(newNode == NULL)
    {
         printf("Node not able to create\n");
         return 0;
    }
    else 
    {
        if(CSLLtail == NULL)
        {
            CSLLtail = newNode;
            newNode->next = newNode;
        }
        else
        {
            newNode->next = CSLLtail->next;
            CSLLtail->next = newNode;
        }
    }
    return 1;
}

/* Function to display the circular linked list
 *@brief Print all elements in the circular linked list
 *@param void */

void CSLLdisplay(void)
{
    if(CSLLtail == NULL)
    {
        printf("CIRCULAR LINK LIST IS EMPTY\n");
        return;
    }
    else
    {
        CSLLNODE *trav = CSLLtail->next;
        do
        {
            printf("-> %d ",trav->data);
            trav = trav->next;
        }while(trav != CSLLtail->next);

        printf("\n");
    }
}

/* Function to delete a node from the beginning of the circular linked list
 *@brief Delete the first node from the circular linked list
 *@return 1 on success, 0 if the list is empty
 *@param void */

int CSLLdeleteNodeFirst(void)
{
   if(CSLLtail == NULL)
   {
       printf("CIRCULAR LINK LIST IS EMPTY\n");
       return 0;
   }
   else
   {
       CSLLNODE *temp = CSLLtail->next;
       if (CSLLtail->next == CSLLtail) // Only one node
       {
           CSLLtail = NULL;
       }
       else
       {
           CSLLtail->next = temp->next;
       }
       free(temp);
   }
   return 1;
}

/* Function to delete a node from the end of the circular linked list
 *@brief Delete the last node from the circular linked list
 *@return 1 on success, 0 if the list is empty
 *@param void */

int CSLLdeleteNodeLast(void)
{
    if(CSLLtail == NULL)
    {
        printf("CIRCULAR LINK LIST IS EMPTY\n");
        return 0;
    }
    else
    {
        CSLLNODE *current = CSLLtail->next;
        CSLLNODE *prev = NULL;
        if (CSLLtail->next == CSLLtail) // Only one node
        {
            free(CSLLtail);
            CSLLtail = NULL;
        }
        else
        {
            while(current->next != CSLLtail->next)
            {
                prev = current;
                current = current->next;
            }
            prev->next = CSLLtail->next;
            free(CSLLtail);
            CSLLtail = prev;
        }
    }
    return 1;
}

/* Function to delete a node from a specific position in the circular linked list
 *@brief Delete the node at the specified position in the circular linked list
 *@return 1 on success, 0 on failure
 *@param void */

int CSLLdeleteNodePos(void)
{
    if(CSLLtail == NULL)
    {
        printf("CIRCULAR LINK LIST IS EMPTY\n");
        return 0;
    }
    else
    {
        int pos, len, i;
        len = CSLLLength();
        printf("ENTER THE POSITION TO DELETE NODE (1 to %d) : ", len);
        scanf("%d",&pos);
        if (pos < 1 || pos > len)
        {
            printf("INVALID POSITION\n");
            return 0;
        }
        else if (pos == 1)
        {
            CSLLdeleteNodeFirst();
        }
        else if (pos == len)
        {
            CSLLdeleteNodeLast();
        }
        else
        {
            CSLLNODE *trav = CSLLtail->next;
            for (i = 1; i < pos - 1; i++)
            {
                trav = trav->next;
            }
            CSLLNODE *temp = trav->next;
            trav->next = temp->next;
            free(temp);
        }
    }
    return 1;
}