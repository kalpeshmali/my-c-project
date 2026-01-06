/*@file SLL_Def.c 
    @brief  Single Linked List definitions and operations
    @author kalpesh mali 
*/
/*header files*/
#include "SLL_Def.h"
#include <stdlib.h>
#include <stdio.h>

/* Define the global head exactly once */
SLLNODE *SLLhead = NULL;

/* Create a new node 
@fun This function creates a new node and returns a pointer to it 
@retuturn pointer to new node on success, NULL on failure 
@params void */

SLLNODE * SLLcreateNode(void)
{
    SLLNODE * newnode = (SLLNODE*) malloc (sizeof(SLLNODE));
    if(newnode == NULL)
    {
        printf("malloc failure to create a new node\n");
        return 0;
    }
    else
    {
        printf("ENTER THE NUMBER : ");
        scanf("%d",&newnode->data);
        printf("\n");
        newnode->next = NULL;
        return newnode;
    }
}

/* Reverse the linked list
@fun This function reverses the linked list
@params void
@return 1 on success, 0 on failure */

int SLLreverseLinkList(void)
{
    if(SLLhead == NULL)
    {
        printf("LINK LIST IS EMPTY \n");
        return 0;
    }
    else 
    {
        SLLNODE *prev = NULL;
        SLLNODE *curr = NULL;
        SLLNODE *nextt = NULL;

        curr = SLLhead;

        while(curr != NULL)
        {
            nextt = curr ->next;
            curr->next = prev;
            prev = curr;
            curr = nextt;
        }
        SLLhead = prev;
        return 1;
    }
}
/* Search an element in the linked list 
@fun This function searches for an element in the linked list
@params void
@return 1 if element found, 0 otherwise */

int SLLsearchElement(void)
{
    int num=0,count=1;
    if(SLLhead == NULL)
    {
        printf("LINK LIST IS EMPTY\n");
        return 0;
    }
    else 
    {
        printf("ENTER THE NUMBER FOR SEARCH :");
        scanf("%d",&num);
        SLLNODE *trav = SLLhead;
        while(trav != NULL)
        {   
            if(trav->data == num)
            {
                printf("%d FOUND AT %d POSITION\n",num,count);
                return 1;
            }
            trav = trav->next;
        }
    }
    printf("%d ELEMENT IS NOT FOUND\n",num);
    return 0;
}

/* Calculate the length of the linked list
@fun This function calculates the length of the linked list
@params void
@return length of the linked list */

int SLLlinkListLength(void)
{
    int length = 1;
    SLLNODE *trav = SLLhead;
    if(trav == NULL)
    {
        printf("LINK LIST IS EMPTY");   
    }
    else
    {
        while (trav != NULL)
        {
            trav = trav->next;
            ++length;
        }
    }
    return length;
}

/* Add a node at a specific position in the linked list
@fun This function adds a new node at the specified position in the linked list 
@params void
@return 1 on success, 0 on failure */

int SLLaddNodePos(void)
{
    int pos=0,count = 0;
    printf("ENTER THE POSITION : ");
    scanf("%d",&pos);
    printf("\n");
    if(( pos >= SLLlinkListLength()) || (pos <= 0))
    {
        printf("POSITION INVALID\n");
        return 0;
    }
    if(pos == 1)
    {
        return SLLaddNodeFirst();
    }
    else if(pos == SLLlinkListLength())
    {
        return SLLaddNodeLast();
    }       
    else 
    {
        SLLNODE *newNode = SLLcreateNode();

        SLLNODE *trav = SLLhead;
        SLLNODE *prev = trav;
        while(pos != count)
        {
            prev = trav;
            trav = trav->next;
            ++count;
        }
        newNode->next = trav;
        prev->next = newNode;
    }
    return 1;
}

/* Add a node at the end of the linked list
@fun This function adds a new node at the end of the linked list
@params void
@return 1 on success, 0 on failure */

int SLLaddNodeLast(void)
{
    SLLNODE *newNode = SLLcreateNode();
    if(newNode == 0)
    {
        printf("Node not able to create\n");
        return 0;
    }
    else 
    {
        SLLNODE *trav = SLLhead;
        if(trav == NULL)
        {
            SLLhead = newNode;
        }
        else
        {
            while(trav->next != NULL)
            {
                trav = trav->next;
            }
            trav->next = newNode;
        }
        return 1;
    }
}

/* Add a node at the beginning of the linked list
@fun This function adds a new node at the beginning of the linked list
@params void
@return 1 on success, 0 on failure */

int SLLaddNodeFirst(void)
{
    SLLNODE *newNode = SLLcreateNode();
    if(newNode == 0)
    {
        printf("Node not able to create\n");
        return 0;
    }
    else
    {
        newNode->next = SLLhead;
        SLLhead = newNode;
        return 1;
    }
}
/* Display the linked list
@fun This function displays the elements of the linked list
@params void
@return void */

void SLLdisplayList(void)
{
    SLLNODE *trav = SLLhead;
    if(trav == NULL)
    {
        printf("LINK LIST IS EMPTY\n");
    }
    else
    {
        while(trav != NULL)
        {
            printf("-> %d ",trav->data);
            trav = trav->next;
        }
        printf("\n");
    }
}

/* Delete the first node from the linked list
@fun This function deletes the first node from the linked list
@params void
@return 1 on success, 0 on failure */

int SLLdeleteNodeFirst(void)
{
    if(SLLhead == NULL)
    {
        printf("LINK LIST IS EMPTY\n");
        return 0;
    }
    SLLNODE *temp = SLLhead;
    SLLhead = SLLhead->next;

    printf("%d DELETED \n",temp->data);
    
    free(temp);
    return 1;
}

/* Delete the last node from the linked list
@fun This function deletes the last node from the linked list
@params void
@return 1 on success, 0 on failure */

int SLLdeleteNodeLast(void)
{
    if(SLLhead == NULL)
    {
        printf("LINK LIST IS EMPTY\n");
        return 0;
    }

    SLLNODE *trav = SLLhead;

    // If only one node
    if(trav->next == NULL)
    {
        printf("%d DELETED\n", trav->data);
        free(trav);
        SLLhead = NULL;
        return 1;
    }
    while(trav->next->next != NULL)
    {
        trav = trav->next;
    }

    printf("%d DELETED \n",trav-> next-> data);
    free(trav->next);
    trav->next = NULL;
    return 1;
}

/* Delete a node at a specific position in the linked list
@fun This function deletes a node at a specific position in the linked list
@params void
@return 1 on success, 0 on failure */

int SLLdeleteNodePos(void)
{
    if(SLLhead == NULL)
    {
        printf("LINK LIST IS EMPTY\n");
        return 0;
    }

    int pos=0;
    int count=1;
    int lLength = SLLlinkListLength(); 
    printf("ENTER THE POSITION : ");
    if (scanf("%d", &pos) != 1)
    {   
        printf("INVALID INPUT\n");
        return 0;
    }

    if((pos > lLength)||(pos <= 0))
    {
        printf("INVALID POSITION \n");
        return 0;
    }
    else if(pos == 1)
    {
        return SLLdeleteNodeFirst();
    }
    else if(pos ==  lLength)
    {
        return SLLdeleteNodeLast();
    }
    else
    {
        SLLNODE *trav = SLLhead;
        SLLNODE *prev = NULL;
        for (count = 1; count < pos; count++)
        {
            prev = trav;
            trav = trav->next;
        }
        prev->next = trav->next;
        printf("%d DELETED\n",trav->data);
        free(trav);
    }
    return 1;
}