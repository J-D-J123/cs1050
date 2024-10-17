/**
* Author:    J-D-J123
* Date:      10/17/2024
* Desc:      asks user for diamond size then asks what 
*              character to start the diamond at 
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

        // create the diamond array then call the other methods 
        char diamondArray[2 * size - 1][2 * size - 1];

        // set dimondArry to ' ' nothing SPACE char
        for(int r = 0; r < 2 * size - 1; r++) {
            for(int c = 0; c < 2 * size - 1; c++) {
                diamondArray[r][c] = ' ';
            }
        }

        // ask user for starting character :)
        printf("Enter the starting character: ");

        // if scanf == 1 go make dimond else do not make dimond 
        if(scanf(" %c", &startChar) == 1) {
            printf("\nmaking diamond\n");
            printDiamond(size, &startChar); 

            for(int r = 0; r < size; r++) {
                for(int c = 0; c < size; c++) {
                    printf("%c", diamondArray[r][c]); 
                }
                printf("\n");
            }
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

void printDiamond(int s, char *startChar) {
    // printf("size is = %d\n", s);
    // printf("*startChar = %p\n", startChar);

    int diamondSize = 2 * s - 1;
    int index =  0;  
    char currentChar = *startChar; 

    for(int r = 0; r < diamondSize; r++) {

        if (r==0) {
            currentChar = *startChar; 
        } else if(r < s) {
            modifyCharacter(&currentChar);
        } else {
            currentChar--; 
        }

        for(int c = 0; c < diamondSize; c++) {
            if(abs(s - 1 - r) + abs(s - 1 - c) < s) {
                startChar[index++] = currentChar;  
                printf("%c", currentChar);
            } else {
                startChar[index++] = ' ';
                printf(" ");
            }
        }
        printf("\n");
    }


    //modifyCharacter(startChar);
    // now we need to print to print the diamond
}
