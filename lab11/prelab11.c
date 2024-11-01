/*
 * CS1050
 * Fall 2024
 * Prelab 11 Starter File
 * by Jim Ries
 */

// includes
#include <stdio.h>
#include <ctype.h>

// Symbolic Constants
#define S1 "I'm not cool and I'm not smart and I can't even parallel park."
#define S2 "\n\n\tMommy's alright.  \t Daddy's alright.  They just seem a little weird.\n\n"
#define S3 "Every cheap hood strikes a bargain with the world.  Ends up making payments on a sofa or a girl."
#define S4 "Now some guys they just give up living.  And start dying little by little, piece by piece.      "
#define STRINGCOUNT 4

////////////////
// Prototypes //
////////////////

// KillWhiteSpace should take a string, remove the whitespace from that string in-place,
// and return a pointer to the beginning of the resultant string (which really should
// be the same thing that was passed in originally - i.e., s).
char * KillWhiteSpace(char *s);


// Main
int main(void)
{
    char s[STRINGCOUNT][256]=
    {
        S1,S2,S3,S4
    };

    printf("**** Original Strings ****\n");
    for (int i=0;i<STRINGCOUNT;i++)
    {
        printf("#%d: %s\n",i,s[i]);
    }

    printf("\n\n**** Strings without whitespace ****\n");
    for (int i=0;i<STRINGCOUNT;i++)
    {
        printf("#%d: %s\n",i,KillWhiteSpace(s[i]));
    }
}

/**
*  KillWhiteSpace Author:   J-D-J123
*/
char * KillWhiteSpace(char *s)
{
    // s is used to go through the whole string array to check for spaces

    // temp is used to build the new string without spaces
    char *temp = s; 

    // pointer to store the start of the original string 
    // used to print the start of the string later
    char *start = s; 

    // go till the end of the array 
    while(*s != '\0') {

        // if blank returns 1 that means it is not blank else is 0 = false
        // if isblank = true change the pointer++ 
        if (!isblank(*s)) {
            //printf("true");

            // copy char to pointer temp 
            *temp = *s; 
            temp++; 
        }

        // update s pointer 
        s++; 
    }

    // put the terminarity operator so the compiler does not go out of bounds
    *temp = '\0'; 

    return start;
}
