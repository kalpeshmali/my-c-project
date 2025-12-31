#include "SLL_op.h"
#include "clearScreen.h"
#include "SLL_Def.h" 
#include "SLL_Menu.h"

int singleLinkListOp(void)
{
    do 
    {
        switch(LinkListMenu())
        {
            case EXIT_LINK_LIST_OP  :       return 1 ;              break;
            case DISPLAY_LINK_LIST  :       displayList();          break;
            case LENGTH_LINK_LIST   :       printf("LIST LIST LENGTH IS : %d\n",linkListLength()); break;
            case ADD_NODE_FIRST     :       addNodeFirst();         break;
            case ADD_NODE_LAST      :       addNodeLast();          break;
            case ADD_NODE_POS       :       addNodePos();           break;
            case DELETE_NODE_FIRST  :       deleteNodeFirst() ;     break;
            case DELETE_NODE_LAST   :       deleteNodeLast();       break;  
            case DELETE_NODE_POS    :       deleteNodePos();        break;
            case SEARCH_ELEMENT     :       searchElement();        break;
            case REVERSE_LINK_LIST  :       reverseLinkList();      break;
            
            default :                printf("Invalid Choice\n");
        }
        pauseScreen();
        clearScreen();
    }while(1);
}
