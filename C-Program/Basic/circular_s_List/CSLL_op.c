/*@file CSLL_op.c 
    @brief  Circular Single Linked List operations
    @author kalpesh mali 
*/

/*header files */
#include <stdio.h>
#include "CSLL_op.h"
#include "CSLL_Def.h"
#include "CSLL_Menu.h"
#include "clearScreen.h"

/* Circular Single Linked List operations 
@fun This function performs all the operations on the circular single linked list 
@retuturn 1 on success, 0 on failure 
@param void */

int circularSingleLinkListOp(void)
{
    do 
    {
        switch(CSLLMenu())
        {
            case CSLL_EXIT_OP            :       return 1 ;              break;
            case CSLL_DISPLAY            :       CSLLdisplay();  break;
            case CSLL_LENGTH             :       printf("LIST LIST LENGTH IS : %d\n",CSLLLength()); break;
            case CSLL_ADD_NODE_FIRST     :       CSLLaddNodeFirst();         break;
            case CSLL_ADD_NODE_LAST      :       CSLLaddNodeLast();          break;
            case CSLL_ADD_NODE_POS       :       CSLLaddNodePos();           break;
            case CSLL_DELETE_NODE_FIRST  :       CSLLdeleteNodeFirst() ;     break;
            case CSLL_DELETE_NODE_LAST   :       CSLLdeleteNodeLast();       break;  
            case CSLL_DELETE_NODE_POS    :       CSLLdeleteNodePos();        break;
            case CSLL_SEARCH_ELEMENT     :       CSLLsearchElement();        break;
            case CSLL_REVERSE_LINK_LIST  :       CSLLReverse();      break;
            
            default :                printf("Invalid Choice\n");
        }
        pauseScreen();
        clearScreen();
    }while(1);
}
