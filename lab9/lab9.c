/**
 * Author:      J-D-J123
 * Date:        10/18/2024
 * File:        lab9.c
 * Desc:        this file uses pointers and a Pass-by-reference value
 *                  in order to help Captain Codebeard and his crew
 *                  of merry pirates find the ancient treasure.
 *                  This program lets the user input commands as 
 *                  char values either U/D/R/L and the user place in 
 *                  the program is displayed as a 'P' and the tresure
 *                  (when you find it) -> (please don't look at the comments :( 
 *                  find it by yourself) is represented by a 'T' character.
 */

#include <stdio.h> 
#include <ctype.h>

#define SIZE 5

// treasure cords are (4,2) but sense it starts at 0  = x
// treasure cords are (5, 2)
#define treasureX 4
#define treasureY 2

void initializeMap(int map[SIZE][SIZE]);
void displayMap(int map[SIZE][SIZE], int x, int y);
void move(int *x, int *y, char direction); 
int checkTreasure(int x, int y); 

int main(void) {

    // found = 0 = false sence we have not gone over booleans 
    // found = 1 = True = game over 
    int found  = 0; 

    // table array 5 * 5
    int table[SIZE][SIZE] = {0}; 

    // start location 
    int x      = 0; 
    int y      = 0; 

    // pointers to the location of the player
    int *ptrX  = &x; // assigns x location to ptrX
    int *ptrY  = &y; // assigns y location to ptrY


    // user contorls variable 
    char userControls = ' ';

    // initialize the map 
    initializeMap(table); 
    
    // print out the table so we can check - TESTING ONLY 
    // displayMap(table); 

    // start the game loop 
    while(found != 1) {
        printf("Here is your map:\n");
        displayMap(table, x, y); 

        // check if treasure is found 
        found = checkTreasure(x, y);
        
        // tell user current position 
        printf("Your current position is (%d, %d).\n", x, y); 

        // ask user to go to a direction U(up), D(down), L(left), R(right)
        printf("Enter direction (U/D/L/R) ");
        scanf(" %c", &userControls);

        if(toupper(userControls) == 'U') {
            // printf("User pressed U\n"); 
            move(ptrX, ptrY, 'U'); 
        } else if(toupper(userControls) == 'D') {
            // printf("User pressed D\n");
            move(ptrX, ptrY, 'D'); 
        } else if(toupper(userControls) == 'L') {
            // printf("User pressed L\n"); 
            move(ptrX, ptrY, 'L'); 
        } else if(toupper(userControls) == 'R') {
            // printf("User pressed R\n"); 
            move(ptrX, ptrY, 'R'); 
        }
        else {
            printf("user entered uknown command, please try again!\n");
        }
    }

    displayMap(table, x, y); 
    printf("Congratulatins! You found the treasure!\n"); 

    return 0; 
}

/**
 * the initializeMap() method takes an array for input and 
 *  sets every element to 0
 *  @param SIZE is the size of the rows and columns 
 *  @param map  is the name of the array - uses pass by refrence 
 */
void initializeMap(int map[SIZE][SIZE]) {

    for(int r = 0; r < SIZE; r++) {
        for(int c = 0; c < SIZE; c++) {

            // store a 0 into the array to set up the game
            map[r][c] = 0; 
        }
    }
}

/**
 * the displayMap() method prints out the array to the terminal 
 * to display a certian cord @param x and @param y will return the correct element
 *  @param SIZE is the size of the rows and columns 
 *  @param map  is the name of the array - uses pass by refrence 
 */
void displayMap(int map[SIZE][SIZE], int x, int y) {
    
    for(int r = 0; r < SIZE; r++) {
        for(int c = 0; c < SIZE; c++) {
            if(r == x && c == y) {

                // p = player's position 
                printf("[P] "); 
            } else {
                printf("[%d] ", map[r][c]); 
            }
        }
        printf("\n");
    }
}


/**
 * the move() method moves the user from the current location
 * @param direction is the direction that the user chose to move 
 *  with only a character either U/D/R/L
 * @param x is a pointer that points to the element x in the array (rows)
 * @param y is a pointer that points to the element y in the array (cols)
 */
void move(int *x, int *y, char direction) {
    if(direction == 'U') {
        if(*x > 0) {
            (*x)--; 
        } else {
            printf("Error! Cannot go there!\n");
        }
    } else if(direction == 'D') {
        if(*x < SIZE - 1) {
            (*x)++; 
        } else {
            printf("Error! Cannot go there!\n");
        }
    } else if(direction == 'L') {
        if(*y > 0) {
            (*y)--; 
        } else {
            printf("Error! Cannot go there!\n"); 
        }
    } else if(direction == 'R') {
        if(*y < SIZE - 1) {
            (*y)++; 
        } else {
            printf("Error! Cannot go there!\n"); 
        }
    }
}

/**
 * the checkTreasure() method takes two inputs which are the 
 *  rows and colums that are going to be checked if it is the treausre. 
 * @param x - is the row index 
 * @param y - is the column index 
 */
int checkTreasure(int x, int y) {
    if(treasureX == x && treasureY == y) {
        return 1; 
    }
    return 0; 
} // end of lab9.c file 
