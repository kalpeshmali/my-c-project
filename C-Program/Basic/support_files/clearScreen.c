#include <stdlib.h>
#include "clearScreen.h"

#ifdef _WIN32
    #include <windows.h>
#else
    #include <unistd.h>
#endif

void clearScreen(void)
{
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

void pauseScreen(void)
{
#ifdef _WIN32
    Sleep(2000);   // milliseconds
#else
    sleep(2);      // seconds
#endif
}
