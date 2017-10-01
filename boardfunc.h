//ComponentBoard 1.0
//Author: John Swan
//
//The program is used to create a custom electronic board. It is then possible to place and remove different
//electronic components into the board by typing each components pin coordinates, corresponding to the board.

#ifndef BOARDFUNC
#define BOARDFUNC

int intcheck();
int varCol;
int varRow;
char newComp;
char board[50][50];
int in;

void newboard();

void printboard();

void zeroboard();

void removeComp();


#endif // BOARDFUNC
