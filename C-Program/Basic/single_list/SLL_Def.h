#ifndef SLL_DEF_H
#define SLL_DEF_H

/*  struct defination SLLnode
    @data integer data
    @next pointer to the next node in the list */

typedef struct SLLnode {
    int data;
    struct SLLnode *next;
} SLLNODE;

/* Function declaration  for single linked list operations */

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