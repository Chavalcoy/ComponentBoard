//ComponentBoard 1.0
//Author: John Swan
//
//The program is used to create a custom electronic board. It is then possible to place and remove different
//electronic components into the board by typing each components pin coordinates, corresponding to the board.

#include "boardfunc.h"
#include <ctype.h>
#include <stdlib.h>
#include <stdio.h>

char board[50][50]; //Creates a predefined 2D array before users
int varCol;
int varRow;
char newComp;
int posXPin1, posYPin1, posXPin2, posYPin2;
int output;
int in;


void mainMenu(){
    char userinput;
    do {
    printf("\t    MAIN MENU\n\t   ===========\n\t(0)Make new board\n\t(1)Zeroize board\n\t(2)Place component\n\t(3)Remove component\n\t(4)Exit\n\n\tENTER CHOICE: ");
    scanf("%s", &userinput);
    switch (userinput){
        case 48: //Creates new board
            newboard(); //Sets default size
            zeroboard();
            printboard();
            mainMenu();
        break;
        case 49: // Clear current board
            zeroboard();
            printboard();
            mainMenu();
        break;
        case 50: // Place component
            printboard();
            newComponent();
            printboard();
            mainMenu();
        break;
        case 51: // Remove Component
            printboard();
            removeComp();
            printboard();
            mainMenu();
        break;
        case 52: return 0;
        break;
        default: printf("\nInvalid option!!! Select 0-4 \n\n ");
        break;
        }
    }
while (userinput < 48 || userinput > 52);
}


//Checks if entered value is a valid digit
int intcheck(){
//(int *)malloc(sizeof(int)); Not needed atm.
while(scanf("%d", &in)==0){
        printf("\tINVALID\n\tEnter a numbers only \n");
        int clear;
        while((clear=getchar()) !='\n' && clear!=EOF);
    }
    return in;
}



//Create a new board with users A B values
void newboard(){
    int input;
    printf("\n\n\tWelcome, create a new board\n\tEnter number of rows ( Max 10 ): ");
    intcheck();//Check that input is valid
    varRow=in;
         if(varRow > 10){
           printf("\tValue automatically set to 10 (Maximum Value)\n");
           varRow=10;
            }

    printf("\tEnter number of columns ( Max 40: ): ");
    intcheck();
    varCol=in;
    printf("\n");
        if(varCol > 49){
            printf("\tValue automatically set to 30 (Default Value)\n");
            varCol=30;
        }
    int board[varRow][varCol];
    //free(in);//Free mem for now
    scanf("%*c"); //Flush scanf buffer

}


//Prints current board
//Prints COLUMN numbers, example 0-30
void printboard(){
   printf("\n\n");
   int i, j, e;
   printf("    ");
   for(e = 1; e <= varCol; e++){
   printf("[%2d]", e);
 //Prints values(Empty spaces/Components) on 2D array.
   }

   printf("\n");
   int x = varCol;
   x = x +1;
   for(i = 0; i < varRow; i++){
        for(j = 0; j < x; j++){
            printf(" [%c]", board[i][j]);
        }
        printf("\n");
    }

    //Print component index
     printf("INDEX - (D)DIOD - (C)CAPACITOR - (S)SWITCH - (R)RESISTOR\n\n");

}

//Zero Sets all values to ' '.
void zeroboard(){

    int i,d;
    for(i = 0; i <= varRow; i++){
        for(d = 0; d <= varCol; d++){
            board[i][d]= ' ';
        }
    }
    //Sets Coordinates 0-10 (ROWS)
    int g='0';
    for(i = 0; i < varRow; i++){

        for(d = 0; d < 1; d++){
            board[i][0]=g;
            g++;
        }
    }
    /* // Protoype for filling value 0-X for X coordinates. Not in function. Use Static 0-X instead.
    int f=0;
    char ca[10];
    itoa(f,ca,10);
    for(i = 0; i < 1; i++){

        for(d = 0; d < 50; d++){
            board[i][d]=ca;
            ca+1;
        }
    }
*/
}

void newComponent (){
    int a,b,c,d;
    //User chooses new where the component is places on 2 pins ROW/COL and ROW/COL for each pin.
    //a/b and c/d correspond to Pin1 ROW/COL and Pin2 ROW/COL
    printf("\n\tPLACE COMPONENT\n\n\tChoose position by typing ROW/COL for Pin(1) followed by ROW/COL Y for Pin(2)\n\tPress ENTER after each coordinate point\n");
        printf("\tPin 1, Enter Row: ");
        intcheck();
        a=in;
        printf("\tEnter Column: ");
        intcheck();
        b=in;
        printf("\tPin2, Enter Row: ");
        intcheck();
        c=in;
        printf("\tEnter Column: ");
        intcheck();
        d=in;

        if (a > varRow || b > varCol || c > varRow || d > varCol){
            printf("\n\n\n\tOUT OF BOUNDS, PLEASE ENTER A VALID ROW/COLUMN NUMBER\n\n");
            newComponent();
        }
        else if (board[a][b] != ' ' || board[c][d] != ' ') {
            printf("\n\n\n\tSPACE OCCUPIED, CHOOSE ANOTHER POSITION!!!!!\n\n");

            newComponent();

       } else if (a != c) {
         printf("\n\n\n\tYOU CAN ONLY PLACE A COMPONENT ON THE SAME ROW!!!!!\n\n");

            newComponent();
        }


    printf("\tPlace a new component: \n\n\t(D)Diod \n\t(R)Resistor \n\t(S)Switch \n\t(C)Capacitor\n\tEnter value:");
    scanf(" %c", &newComp);
    board[a][b]=newComp; //Place new component on 1:st pin
    board[c][d]=newComp; //Place new component on 2:d pin

        //Fill space between component pins with '-'
        //Two loops depending on how the user entered the pin order for example: abcd: 3,3,3,6 or 3,6,3,3 which is the same thing.
        if (b > d){ //If user started from left to right
            int f;
                for (f = --b; f > d; f--){
                    board[a][f]='-';
                }
            } else if (b < d){  //If user started from right to left
                int f;
                for (f = ++b; f < d; ++f){
                    board[a][f]='-';
                }
            }


}
void removeComp(){
    int a,b,c,d=0;    //a/b and c/d correspond to Pin1 ROW/COL and Pin2 ROW/COL
    printf("\tRemove component:\n\n\tSelect first pin postion\n\tEnter Row: ");
        intcheck();
        a=in;
        printf("\tEnter Column: ");
        intcheck();
        b=in;
    printf("\n\tSecond pin postion\n\tEnter Row: ");
        intcheck();
        c=in;
    printf("\tEnter Column: ");
        intcheck();
        d=in;

    if (a > varRow || b > varCol || c > varRow || d > varCol){
            printf("\n\n\n\tOUT OF BOUNDS, PLEASE ENTER A VALID ROW/COLUMN NUMBER\n\n");
            removeComp();
        }
    else if (a != c) {
         printf("\n\n\n\tYOU CAN ONLY REMOVE A COMPONENT ON THE SAME ROW!!!!!\n\n");

            removeComp();
    }
    else if (board[a][b] != board[c][d] || board[a][b] == '-' || board [c][d] == '-' || board[a][b] == ' ' || board[c][d] == ' '){ //CHECK THAT THE ENTERED POS ARE INDEED VALID PINS AND THAT ONLY ONE COMPONENT IS CHOOSEN
        printf("\n\n\n\tPLEASE SELECT THE RIGHT PIN POSITION, START FROM THE LEFT OR RIGHT\n\n");
        removeComp();
    }
    //Replace component placement with ' '
    else {
            if (b > d){
            int f;
                for (f = b; f >= d; --f){
                    board[a][f]=' ';
                }
            } else if (b < d){
                int g;
                for (g = b; g <= d; g++){
                    board[a][g]=' ';
                }
            }

    }
}
