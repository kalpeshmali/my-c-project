#include "mainMenu.h"
#include <stdio.h>

int mainMenu(void)
{
    int choice;
    printf("**************************************************************************************\n");
    printf("************************** WELCOME TO C PROGRAMMING **********************************\n");
    printf("**************************************************************************************\n");
    printf("    1.SINGLE LINK LIST \n");
    printf("    2.CIRCULAR LINK LIST \n");
    printf("ENTER YOUR CHOICE\n");
    scanf("%d",&choice);
    return choice;
}