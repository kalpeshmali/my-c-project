/* @file mainMenu.c 
    @brief  Main menu display and user choice input
    @author kalpesh mali */
/* Header files */
#include "mainMenu.h"
#include <stdio.h>

/* Function to display the main menu 
   @function mainMenu 
   @return integer choice 
   @param void */

int mainMenu(void)
{
    int choice;
    printf("**************************************************************************************\n");
    printf("************************** WELCOME TO C PROGRAMMING **********************************\n");
    printf("**************************************************************************************\n");
    printf("    1.SINGLE LINK LIST \n");
    printf("    2.CIRCULAR LINK LIST \n");
    printf("    3.DOUBLE LINK LIST \n");
    printf("ENTER YOUR CHOICE\n");
    scanf("%d",&choice);
    return choice;
}