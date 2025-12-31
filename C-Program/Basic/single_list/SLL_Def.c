#include "SLL_Def.h"
#include <stdlib.h>
#include <stdio.h>

/* Define the global head exactly once */
NODE *head = NULL;

NODE * createNode(void)
{
    NODE * newnode = (NODE*) malloc (sizeof(NODE));
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

int reverseLinkList(void)
{
    if(head == NULL)
    {
        printf("LINK LIST IS EMPTY \n");
        return 0;
    }
    else 
    {
        NODE *prev = NULL;
        NODE *curr = NULL;
        NODE *nextt = NULL;

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


int searchElement(void)
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
        NODE *trav = head;
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
int linkListLength(void)
{
    int length = 1;
    NODE *trav = head;
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
int addNodePos(void)
{
    int pos=0,count = 0;
    printf("ENTER THE POSITION : ");
    scanf("%d",&pos);
    printf("\n");
    if(( pos >= linkListLength()) || (pos <= 0))
    {
        printf("POSITION INVALID\n");
        return 0;
    }
    if(pos == 1)
    {
        return addNodeFirst();
    }
    else if(pos == linkListLength())
    {
        return addNodeLast();
    }       
    else 
    {
        NODE *newNode = createNode();

        NODE *trav = head;
        NODE *prev = trav;
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
int addNodeLast(void)
{
    NODE *newNode = createNode();
    if(newNode == 0)
    {
        printf("Node not able to create\n");
        return 0;
    }
    else 
    {
        NODE *trav = head;
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

int addNodeFirst(void)
{
    NODE *newNode = createNode();
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

void displayList(void)
{
    NODE *trav = head;
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

int deleteNodeFirst(void)
{
    if(head == NULL)
    {
        printf("LINK LIST IS EMPTY\n");
        return 0;
    }
    NODE *temp = head;
    head = head->next;
    
    printf("%d DELETED \n",temp->data);
    
    free(temp);
    return 1;
}

int deleteNodeLast(void)
{
    if(head == NULL)
    {
        printf("LINK LIST IS EMPTY\n");
        return 0;
    }

    NODE *trav = head;

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

int deleteNodePos(void)
{
    if(head == NULL)
    {
        printf("LINK LIST IS EMPTY\n");
        return 0;
    }

    int pos=0;
    int count=1;
    int lLength = linkListLength(); 
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
        return deleteNodeFirst();
    }
    else if(pos ==  lLength)
    {
        return deleteNodeLast();
    }
    else
    {
        NODE *trav = head;
        NODE *prev = NULL;
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