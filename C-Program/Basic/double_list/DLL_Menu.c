/* @file DLL_Menu.c 
   @author kalpesh mali
*/
/*header files */

#include <stdio.h>
#include "DLL_Menu.h"

/* @function DLLMenu
 * @brief Displays the menu for double linked list operations and gets user choice
 * @param void
 * @return User's menu choice as an integer */

int DLLMenu(void)
{
    int choice;
    printf("**************** WELCOME TO DOUBLE LINK LIST OPERATION ****************\n");
    printf("    0.  EXIT LINK LIST OPERATION \n");
    printf("    1.  DISPLAY LINK LIST\n");
    printf("    2.  LINK LIST LENTH\n");
    printf("    3.  ADD NODE FIRST \n");
    printf("    4.  ADD NODE LAST  \n");
    printf("    5.  ADD NODE GIVEN POSITION  \n");
    printf("    6.  DELETE NODE FIRST  \n");
    printf("    7.  DELETE NODE LAST  \n");
    printf("    8.  DELETE NODE POSITION  \n");
    printf("    9.  SEARCH ELEMENT\n");
    printf("   10.  REVERSE LINK LIST\n");
    printf("ENTER YOUR CHOICE\n");
    scanf("%d",&choice);
    return choice;
}