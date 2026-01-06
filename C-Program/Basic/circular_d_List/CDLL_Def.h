#ifndef CDLL_DEF_H
#define CDLL_DEF_H

/* header files*/
#include "CDLL_Def.h"
#include <stdlib.h>
#include <stdio.h>

/* Circular Double Linked List Node Definition 
@data: integer data value
@next: pointer to the next node in the list
@prev: pointer to the previous node in the list */

typedef struct CDLLnode {
    int data;
    struct CDLLnode *next;
    struct CDLLnode *prev;
} CDLLNODE;

/* Function declarations */

CDLLNODE * CDLLcreateNode(void);
int CDLLReverse(void);
int CDLLsearchElement(void);
int CDLLLength(void);
void CDLLdisplay(void);
int CDLLaddNodePos(void);
int CDLLaddNodeLast(void);
int CDLLaddNodeFirst(void);
int CDLLdeleteNodeFirst(void);
int CDLLdeleteNodeLast(void);
int CDLLdeleteNodePos(void);

#endif //"CDLL_Def.h"