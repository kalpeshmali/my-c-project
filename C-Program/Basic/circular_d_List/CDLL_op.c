/*@file CSLL_op.c 
    @brief  Circular Single Linked List operations
    @author kalpesh mali 
*/

/*header files */
#include <stdio.h>
#include "CDLL_op.h"
#include "CDLL_Def.h"
#include "CDLL_Menu.h"
#include "clearScreen.h"

/* Circular Double Linked List operations 
@fun This function performs all the operations on the circular double linked list 
@retuturn 1 on success, 0 on failure 
@param void */

int circularDoubleLinkListOp(void)
{
    do 
    {
        switch(CDLLMenu())
        {
            case CDLL_EXIT_OP            :       return 1 ;              break;
            case CDLL_DISPLAY            :       CDLLdisplay();  break;
            case CDLL_LENGTH             :       printf("LIST LIST LENGTH IS : %d\n",CDLLLength()); break;
            case CDLL_ADD_NODE_FIRST     :       CDLLaddNodeFirst();         break;
            case CDLL_ADD_NODE_LAST      :       CDLLaddNodeLast();          break;
            case CDLL_ADD_NODE_POS       :       CDLLaddNodePos();           break;
            case CDLL_DELETE_NODE_FIRST  :       CDLLdeleteNodeFirst() ;     break;
            case CDLL_DELETE_NODE_LAST   :       CDLLdeleteNodeLast();       break;  
            case CDLL_DELETE_NODE_POS    :       CDLLdeleteNodePos();        break;
            case CDLL_SEARCH_ELEMENT     :       CDLLsearchElement();        break;
            case CDLL_REVERSE_LINK_LIST  :       CDLLReverse();      break;
            
            default :                printf("Invalid Choice\n");
        }
        pauseScreen();
        clearScreen();
    }while(1);
}
