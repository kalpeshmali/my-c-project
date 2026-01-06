#ifndef DLL_DEF_H
#define DLL_DEF_H    

/* Double Linked List Node Definition 
@data: integer data value
@next: pointer to the next node in the list
@prev: pointer to the previous node in the list */

typedef struct DLLnode {
    int data;
    struct DLLnode *next;
    struct DLLnode *prev;
} DLLNODE;

/* Function declarations for double linked list operations */
DLLNODE * DLLcreateNode(void);
int DLLReverse(void);
int DLLsearchElement(void);
int DLLLength(void);
void DLLdisplay(void);
int DLLaddNodePos(void);
int DLLaddNodeLast(void);
int DLLaddNodeFirst(void);
int DLLdeleteNodeFirst(void);
int DLLdeleteNodeLast(void);
int DLLdeleteNodePos(void);

#endif
/* Function declaration for double linked list operations */