#ifndef CLL_DEF_H
#define CLL_DEF_H

#include "CLL_Def.h"
#include <stdlib.h>
#include <stdio.h>

typedef struct CLLnode {
    int data;
    struct CLLnode *next;
} CLLNODE;

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