#include "CLL_op.h"
#include "CLL_Def.h"
#include "CLL_Menu.h"
#include "clearScreen.h"

int circularLinkListOp(void)
{
    do 
    {
        switch(CLLMenu())
        {
            case CLL_EXIT_OP            :       return 1 ;              break;
            case CLL_DISPLAY            :       CLLdisplay();  break;
            case CLL_LENGTH             :       printf("LIST LIST LENGTH IS : %d\n",CLLLength()); break;
            case CLL_ADD_NODE_FIRST     :       CLLaddNodeFirst();         break;
            case CLL_ADD_NODE_LAST      :       CLLaddNodeLast();          break;
            case CLL_ADD_NODE_POS       :       CLLaddNodePos();           break;
            case CLL_DELETE_NODE_FIRST  :       CLLdeleteNodeFirst() ;     break;
            case CLL_DELETE_NODE_LAST   :       CLLdeleteNodeLast();       break;  
            case CLL_DELETE_NODE_POS    :       CLLdeleteNodePos();        break;
            case CLL_SEARCH_ELEMENT     :       CLLsearchElement();        break;
            case CLL_REVERSE_LINK_LIST  :       CLLReverse();      break;
            
            default :                printf("Invalid Choice\n");
        }
        pauseScreen();
        clearScreen();
    }while(1);
}
