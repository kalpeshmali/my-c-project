#ifndef CSLL_DEF_H
#define CSLL_DEF_H

/* header files*/
#include "CSLL_Def.h"
#include <stdlib.h>
#include <stdio.h>

/* Circular Linked List Node Definition 
@data: integer data value
@next: pointer to the next node in the list */

typedef struct CSLLnode {
    int data;
    struct CSLLnode *next;
} CSLLNODE;

/* Function declarations */

CSLLNODE * CSLLcreateNode(void);
int CSLLReverse(void);
int CSLLsearchElement(void);
int CSLLLength(void);
void CSLLdisplay(void);
int CSLLaddNodePos(void);
int CSLLaddNodeLast(void);
int CSLLaddNodeFirst(void);
int CSLLdeleteNodeFirst(void);
int CSLLdeleteNodeLast(void);
int CSLLdeleteNodePos(void);

#endif //"SLL_Def.h"