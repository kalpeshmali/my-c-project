#include "SLL_op.h"
#include "clearScreen.h"
#include "SLL_Def.h" 
#include "SLL_Menu.h"

int singleLinkListOp(void)
{
    do 
    {
        switch(SLLMenu())
        {
            case EXIT_LINK_LIST_OP  :       return 1 ;              break;
            case DISPLAY_LINK_LIST  :       SLLdisplayList();          break;
            case LENGTH_LINK_LIST   :       printf("LIST LIST LENGTH IS : %d\n",SLLlinkListLength()); break;
            case ADD_NODE_FIRST     :       SLLaddNodeFirst();         break;
            case ADD_NODE_LAST      :       SLLaddNodeLast();          break;
            case ADD_NODE_POS       :       SLLaddNodePos();           break;
            case DELETE_NODE_FIRST  :       SLLdeleteNodeFirst() ;     break;
            case DELETE_NODE_LAST   :       SLLdeleteNodeLast();       break;  
            case DELETE_NODE_POS    :       SLLdeleteNodePos();        break;
            case SEARCH_ELEMENT     :       SLLsearchElement();        break;
            case REVERSE_LINK_LIST  :       SLLreverseLinkList();      break;
            
            default :                printf("Invalid Choice\n");
        }
        pauseScreen();
        clearScreen();
    }while(1);
}
