#ifndef SLL_DEF_H
#define SLL_DEF_H

typedef struct SLLnode {
    int data;
    struct SLLnode *next;
} SLLNODE;

SLLNODE * SLLcreateNode(void);

int SLLaddNodeFirst(void);
int SLLaddNodeLast(void);
int SLLaddNodePos(void);

int SLLdeleteNodeFirst(void);
int SLLdeleteNodeLast(void);
int SLLdeleteNodePos(void);

void SLLdisplayList(void);
int SLLlinkListLength(void);
int SLLsearchElement(void);
int SLLreverseLinkList(void);

#endif