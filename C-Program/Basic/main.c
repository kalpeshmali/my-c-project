/* @file main.c 
    @brief  Main function to run the linked list operations
    @author kalpesh mali */

/* Header files */

#include "main.h"
#include "mainMenu.h"
#include "clearScreen.h"
#include "SLL_op.h"
#include "CSLL_op.h"
#include "DLL_op.h"
#include "CDLL_op.h"

/* Main function
/* @function main 
   @return integer 
   @param void */

int main (void)
{
    int num;
    do 
    {
        clearScreen();
        switch(mainMenu())
        {
            case SINGLE_LIST_OP :
                singleLinkListOp();
                break;
            case CIRCULAR_S_LIST_OP:
                circularSingleLinkListOp();
                break;
            case DOUBLE_LIST_OP:
                doubleLinkListOp();
                break;
            case CIRCULAR_D_LIST_OP:
                doubleLinkListOp();
                break;
            default :
                printf("Invalid Choice\n");
        }
        printf("\n DO YOU WANT TO CONTINUE ? YES : 1 NO : ANY KEY ");
        scanf("%d",&num);
    }while(num ==1);
    clearScreen();
    return 0;
}