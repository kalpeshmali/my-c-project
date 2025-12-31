#include <stdlib.h>
#include "clearScreen.h"
#include <unistd.h>

void clearScreen(void)
{
    system("clear");
}

void pauseScreen(void)
{
    sleep(2);
}