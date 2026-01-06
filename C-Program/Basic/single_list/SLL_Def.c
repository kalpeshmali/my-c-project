#include "SLL_Def.h"
#include <stdlib.h>
#include <stdio.h>

/* Define the global head exactly once */
SLLNODE *head = NULL;

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

int SLLreverseLinkList(void)
{
    if(head == NULL)
    {
        printf("LINK LIST IS EMPTY \n");
        return 0;
    }
    else 
    {
        SLLNODE *prev = NULL;
        SLLNODE *curr = NULL;
        SLLNODE *nextt = NULL;

        curr = head;

        while(curr != NULL)
        {
            nextt = curr ->next;
            curr->next = prev;
            prev = curr;
            curr = nextt;
        }
        head = prev;
        return 1;
    }
}


int SLLsearchElement(void)
{
    int num=0,count=1;
    if(head == NULL)
    {
        printf("LINK LIST IS EMPTY\n");
        return 0;
    }
    else 
    {
        printf("ENTER THE NUMBER FOR SEARCH :");
        scanf("%d",&num);
        SLLNODE *trav = head;
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
int SLLlinkListLength(void)
{
    int length = 1;
    SLLNODE *trav = head;
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

        SLLNODE *trav = head;
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
        SLLNODE *trav = head;
        if(trav == NULL)
        {
            head = newNode;
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
        newNode->next = head;
        head = newNode;
        return 1;
    }
}

void SLLdisplayList(void)
{
    SLLNODE *trav = head;
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

int SLLdeleteNodeFirst(void)
{
    if(head == NULL)
    {
        printf("LINK LIST IS EMPTY\n");
        return 0;
    }
    SLLNODE *temp = head;
    head = head->next;
    
    printf("%d DELETED \n",temp->data);
    
    free(temp);
    return 1;
}

int SLLdeleteNodeLast(void)
{
    if(head == NULL)
    {
        printf("LINK LIST IS EMPTY\n");
        return 0;
    }

    SLLNODE *trav = head;

    // If only one node
    if(trav->next == NULL)
    {
        printf("%d DELETED\n", trav->data);
        free(trav);
        head = NULL;
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

int SLLdeleteNodePos(void)
{
    if(head == NULL)
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
        SLLNODE *trav = head;
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