/* @file SLL_Menu.c 
    @brief  Menu for Single Linked List operations
    @author kalpesh mali 
*/
/* Header files */
#include "SLL_Menu.h"
#include <stdio.h>

/* Function to display the menu 
   @function SLLMenu 
   @return integer choice 
   @param void */
   
int SLLMenu(void)
{
    int choice;
    printf("**************** WELCOME TO SINGLE LINK LIST OPERATION ****************\n\n");
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
    printf("ENTER YOUR CHOICE\n");
    scanf("%d",&choice);
    return choice;
}