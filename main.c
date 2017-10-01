//ComponentBoard 1.0
//Author: John Swan
//
//The program is used to create a custom electronic board. It is then possible to place and remove different
//electronic components into the board by typing each components pin coordinates, corresponding to the board.

#include <stdio.h>
#include <stdlib.h>
#include "boardfunc.h"
//#include "boardmain.c"



//Main Menu
int main()
{
    newboard();
    zeroboard();
    printboard();
    mainMenu();

    return 0;
}
