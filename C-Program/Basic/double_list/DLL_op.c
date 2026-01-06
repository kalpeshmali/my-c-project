/* @file DLL_op.c 
   @author kalpesh mali
*/

/*header files*/
#include <stdio.h>
#include "DLL_op.h"
#include "DLL_Def.h"
#include "DLL_Menu.h"
#include "clearScreen.h"

/* Define operation codes for double linked list menu */
/* @function doubleLinkListOp
 * @brief Handles the operations for double linked list based on user menu choice
 * @param void
 * @return 1 on exit
 */

int doubleLinkListOp(void)
{
    do 
    {
        switch(DLLMenu())
        {
            case DLL_EXIT_OP            :       return 1 ;                  break;
            case DLL_DISPLAY            :       DLLdisplay();               break;
            case DLL_LENGTH             :       printf("LIST LIST LENGTH IS : %d\n",DLLLength()); break;

            case DLL_ADD_NODE_FIRST     :       DLLaddNodeFirst();          break;
            case DLL_ADD_NODE_LAST      :       DLLaddNodeLast();           break;
            case DLL_ADD_NODE_POS       :       DLLaddNodePos();            break;

            case DLL_DELETE_NODE_FIRST  :       DLLdeleteNodeFirst() ;      break;
            case DLL_DELETE_NODE_LAST   :       DLLdeleteNodeLast();        break;  
            case DLL_DELETE_NODE_POS    :       DLLdeleteNodePos();         break;

            case DLL_SEARCH_ELEMENT     :       DLLsearchElement();         break;
            case DLL_REVERSE_LINK_LIST  :       DLLReverse();               break;
            
            default                     :       printf("Invalid Choice\n");
        }
        pauseScreen();
        clearScreen();
    }while(1);
}