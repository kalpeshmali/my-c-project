#ifndef SLL_DEF_H
#define SLL_DEF_H

typedef struct node {
    int data;
    struct node *next;
} NODE;

NODE * createNode(void);

int addNodeFirst(void);
int addNodeLast(void);
int addNodePos(void);

int deleteNodeFirst(void);
int deleteNodeLast(void);
int deleteNodePos(void);

void displayList(void);
int linkListLength(void);
int searchElement(void);
int reverseLinkList(void);
#endif