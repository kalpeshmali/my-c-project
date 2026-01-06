#include "CLL_Menu.h"
#include <stdio.h>

int CLLMenu(void)
{
    int choice;
    printf("**************** WELCOME TO CIRCULAR LINK LIST OPERATION ****************\n");
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