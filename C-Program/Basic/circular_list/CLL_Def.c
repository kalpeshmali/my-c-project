/* 
    @file   CLL_Def.c 
    @brief  Definition of Circular Linked List functions
    @author kalpesh mali
*/

#include "CLL_Def.h"
#include <stdlib.h>
#include <stdio.h>

/*  Define the global tail pointer exactly once */
CLLNODE *CLLtail = NULL;

/* Function to create a new node 
@brief Create a new node and initialize it with user input
@returns Pointer to the newly created node or NULL on failure
@param void */

CLLNODE * CLLcreateNode(void)
{
    CLLNODE * newnode = (CLLNODE*) malloc (sizeof(CLLNODE));
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

int CLLReverse(void)
{
    if ( CLLtail == NULL)
    {
        printf("CIRCULAR LINK LIST IS EMPTY\n");
        return 0;
    }
    else
    {
        CLLNODE *head = CLLtail->next;
        CLLNODE *current = head;
        CLLNODE *prev = CLLtail;
        CLLNODE *nextt = NULL;
        do
        {
            nextt = current->next;
            current->next = prev;
            prev = current;
            current = nextt;
        }while(current != head);

        CLLtail = head;
        return 1;
    }
}
/* Function to search an element in the circular linked list
 *@brief Search for a specific element in the circular linked list
 *@return 1 on success, 0 if the list is empty or element not found
 *@param void */

int CLLsearchElement(void)
{
    if (CLLtail == NULL)
    {
        return 0;
    }
    int element,count = 0;
    printf("ENTER THE ELEMENT TO BE SEARCHED : ");
    scanf("%d",&element);
    CLLNODE *trav = CLLtail->next;
    do
    {
        count ++;
        if(trav->data == element)
        {
            printf("ELEMENT FOUND AT %d POSITION\n", count);
            
            return 1;
        }
        trav = trav->next;
        
    }while(trav != CLLtail->next);
    printf("ELEMENT NOT FOUND\n");
    return 0;
}

/* Function to calculate the length of the circular linked list
 *@brief Calculate the number of nodes in the circular linked list
 *@return Length of the circular linked list
 *@param void */

int CLLLength(void)
{
    int count = 0;
   if (CLLtail == NULL)
   {
       return count;
   }
   else
   {
       CLLNODE *trav = CLLtail->next;
       do
       {
           count++;
           trav = trav->next;
       }while(trav != CLLtail->next);  
   }
   return count;
}

/* Function to add a node at a specific position in the circular linked list
 *@brief Add a new node at the specified position in the circular linked list
 *@return 1 on success, 0 on failure
 *@param void */

int CLLaddNodePos(void)
{
    if(CLLtail == NULL)
    {
        printf("CIRCULAR LINK LIST IS EMPTY\n");
        return 0;
    }
    else
    {
        int pos, len, i;
        len = CLLLength();
        printf("ENTER THE POSITION TO ADD NODE (1 to %d) : ", len+1);
        scanf("%d",&pos);
        if (pos < 1 || pos > len + 1)
        {
            printf("INVALID POSITION\n");
            return 0;
        }
        else if (pos == 1)
        {
            CLLaddNodeFirst();
        }
        else if (pos == len + 1)
        {
            CLLaddNodeLast();
        }
        else
        {
            CLLNODE *newNode = CLLcreateNode();
            if (newNode == NULL)
            {
                printf("Node not able to create\n");
                return 0;
            }
            else
            {
                CLLNODE *trav = CLLtail->next;
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

int CLLaddNodeLast(void)
{
    CLLNODE *newNode = CLLcreateNode();
    if (newNode == NULL)
    {
        printf("Node not able to create\n");
        return 0;
    }
    else 
    {   if (CLLtail == NULL)
        {
            CLLtail = newNode;
            newNode->next = newNode;
        }
        else
        {
            newNode->next = CLLtail->next;
            CLLtail->next = newNode;
            CLLtail = newNode;
        }
    }
    return 1;
}

/* Function to add a node at the beginning of the circular linked list
 *@brief Add a new node at the beginning of the circular linked list
 *@return 1 on success, 0 on failure
 *@param void */

int CLLaddNodeFirst(void)
{
    CLLNODE *newNode = CLLcreateNode();
    if(newNode == NULL)
    {
         printf("Node not able to create\n");
         return 0;
    }
    else 
    {
        if(CLLtail == NULL)
        {
            CLLtail = newNode;
            newNode->next = newNode;
        }
        else
        {
            newNode->next = CLLtail->next;
            CLLtail->next = newNode;
        }
    }
    return 1;
}

/* Function to display the circular linked list
 *@brief Print all elements in the circular linked list
 *@param void */

void CLLdisplay(void)
{
    if(CLLtail == NULL)
    {
        printf("CIRCULAR LINK LIST IS EMPTY\n");
        return;
    }
    else
    {
        CLLNODE *trav = CLLtail->next;
        do
        {
            printf("-> %d ",trav->data);
            trav = trav->next;
        }while(trav != CLLtail->next);

        printf("\n");
    }
}

/* Function to delete a node from the beginning of the circular linked list
 *@brief Delete the first node from the circular linked list
 *@return 1 on success, 0 if the list is empty
 *@param void */

int CLLdeleteNodeFirst(void)
{
   if(CLLtail == NULL)
   {
       printf("CIRCULAR LINK LIST IS EMPTY\n");
       return 0;
   }
   else
   {
       CLLNODE *temp = CLLtail->next;
       if (CLLtail->next == CLLtail) // Only one node
       {
           CLLtail = NULL;
       }
       else
       {
           CLLtail->next = temp->next;
       }
       free(temp);
   }
   return 1;
}

/* Function to delete a node from the end of the circular linked list
 *@brief Delete the last node from the circular linked list
 *@return 1 on success, 0 if the list is empty
 *@param void */

int CLLdeleteNodeLast(void)
{
    if(CLLtail == NULL)
    {
        printf("CIRCULAR LINK LIST IS EMPTY\n");
        return 0;
    }
    else
    {
        CLLNODE *current = CLLtail->next;
        CLLNODE *prev = NULL;
        if (CLLtail->next == CLLtail) // Only one node
        {
            free(CLLtail);
            CLLtail = NULL;
        }
        else
        {
            while(current->next != CLLtail->next)
            {
                prev = current;
                current = current->next;
            }
            prev->next = CLLtail->next;
            free(CLLtail);
            CLLtail = prev;
        }
    }
    return 1;
}

/* Function to delete a node from a specific position in the circular linked list
 *@brief Delete the node at the specified position in the circular linked list
 *@return 1 on success, 0 on failure
 *@param void */

int CLLdeleteNodePos(void)
{
    if(CLLtail == NULL)
    {
        printf("CIRCULAR LINK LIST IS EMPTY\n");
        return 0;
    }
    else
    {
        int pos, len, i;
        len = CLLLength();
        printf("ENTER THE POSITION TO DELETE NODE (1 to %d) : ", len);
        scanf("%d",&pos);
        if (pos < 1 || pos > len)
        {
            printf("INVALID POSITION\n");
            return 0;
        }
        else if (pos == 1)
        {
            CLLdeleteNodeFirst();
        }
        else if (pos == len)
        {
            CLLdeleteNodeLast();
        }
        else
        {
            CLLNODE *trav = CLLtail->next;
            for (i = 1; i < pos - 1; i++)
            {
                trav = trav->next;
            }
            CLLNODE *temp = trav->next;
            trav->next = temp->next;
            free(temp);
        }
    }
    return 1;
}