/**
* Author:    J-D-J123
* Date:      10/17/2024
* File:      prelab9.c
* Desc:      asks user for diamond size then asks what 
*              character to start the diamond at, 
*              finally prints out the dimond 
*/ 

#include <stdio.h> 
#include <stdlib.h> 

void printDiamond(int s, char *startChar); 
void modifyCharacter(char *ch); 

// NO GOLBAL VARIABLES!!!!!!!!!!!!!!!!!!

int main(void) {
    int size = 0; 
    char startChar = ' '; 

    printf("Enter the size of the diamond: ");
    if(scanf("%d", &size) == 1 ) {

        // ask user for starting character :)
        printf("Enter the starting character: ");

        // if scanf == 1 go make dimond else do not make dimond 
        if(scanf(" %c", &startChar) == 1) {
            printf("\nmaking diamond\n");
            printDiamond(size, &startChar); 

        } else {
            printf("failed to make diamond");
        }
    } else {
        printf("failed to make diamond");
    }
}

/**
 * the modifyCharacter() method takes a pramater input of a char pointer 
 *  named *ch this input will modify the pointer to the new the 
 *  next ASCII character. 
 */
void modifyCharacter(char *ch) {
    //printf("*ch = %c\n", *ch); 
    //printf("modifying character...\n");
    
    *ch = *ch + 1; 

    //printf("%c\n", *ch); 
}

// void modifyCharacter(char *ch) {

// }

void printDiamond(int s, char *startChar) {

    int size = 2 * s - 1;

    char diamond[size][size]; 

    for(int r = 0; r < size; r++) {
        for(int c = 0; c < size; c++) {
            diamond[r][c] = ' '; 
            printf("%c", diamond[r][c]);
        }
        printf("\n");
    }

    int mid = size / 2; 


    // top layer 
    for(int r = 0; r < size / 2 + 1; r++) {
        for(int c = 0; c <= r; c++) {
            diamond[r][mid]     = *startChar; 
            diamond[r][mid-c]   = *startChar; 
            diamond[r][mid+c]   = *startChar; 
        }

        // modifyCharacter(startChar); 
    }

    // bottom layer 
    int num = 0; 
    for(int r = size - 1; r > size / 2; r--) {
        for(int c = 0; c <= num; c++) {
            diamond[r][mid]     = *startChar; 
            diamond[r][mid-c]   = *startChar; 
            diamond[r][mid+c]   = *startChar; 
        }
        num++; 
    }

    // change and modify the characters of the diamond array 
    int top = 1; 
    int bottom = size - 2; 
    while(top <= bottom) {

        modifyCharacter(startChar);
        for(int r = 0; r < size; r++) {
            if(diamond[top][r] != ' ') {

                diamond[top][r]     = *startChar; 
                diamond[bottom][r]  = *startChar; 
            }
        }
        top++; 
        bottom--; 
    }

    // print the diamond array 
    for(int r = 0; r < size; r++) {
        for(int c = 0; c < size; c++) {
            // diamond[r][c] = ' '; 
            printf("%c", diamond[r][c]);
        }
        printf("\n");
    }


    //modifyCharacter(startChar);
    // now we need to print to print the diamond
}
