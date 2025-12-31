#include "main.h"
#include "SLL_op.h"
#include "mainMenu.h"
#include "clearScreen.h"

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
            default :
                printf("Invalid Choice\n");
        }
        printf("\n DO YOU WANT TO CONTINUE ? YES : 1 NO : ANY KEY ");
        scanf("%d",&num);
    }while(num ==1);
    clearScreen();
    return 0;
}