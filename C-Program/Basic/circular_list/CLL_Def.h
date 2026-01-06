#ifndef CLL_DEF_H
#define CLL_DEF_H

/* header files*/
#include "CLL_Def.h"
#include <stdlib.h>
#include <stdio.h>

/* Circular Linked List Node Definition 
@data: integer data value
@next: pointer to the next node in the list */

typedef struct CLLnode {
    int data;
    struct CLLnode *next;
} CLLNODE;

/* Function declarations */

CLLNODE * CLLcreateNode(void);
int CLLReverse(void);
int CLLsearchElement(void);
int CLLLength(void);
void CLLdisplay(void);
int CLLaddNodePos(void);
int CLLaddNodeLast(void);
int CLLaddNodeFirst(void);
int CLLdeleteNodeFirst(void);
int CLLdeleteNodeLast(void);
int CLLdeleteNodePos(void);

#endif //"SLL_Def.h"