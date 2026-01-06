#include <stdlib.h>
#include "clearScreen.h"

#ifdef _WIN32
    #include <windows.h>
#else
    #include <unistd.h>
#endif

/* Function to clear the console screen 
@brief Clears the console screen based on the operating system
@param void 
@returns void */

void clearScreen(void)
{
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

/* Function to pause the console screen for a brief moment
@brief Pauses the console screen for 2 seconds based on the operating system
@param void 
@returns void */

void pauseScreen(void)
{
#ifdef _WIN32
    Sleep(2000);   // milliseconds
#else
    sleep(2);      // seconds
#endif
}
