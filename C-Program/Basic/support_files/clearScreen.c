#include <stdlib.h>
#include "clearScreen.h"
#include <unistd.h>

void clearScreen(void)
{
    system("cls");
}

void pauseScreen(void)
{
    sleep(2);
}