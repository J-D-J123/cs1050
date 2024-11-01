/** 
* Name: Joseph Johnson 
* Date: 8/30/2024 
* Class: CS 1050   
* Desc: Print the values of both variables that were entered by the user.
* • Print the value of the first variable times the second variable.
* • Print the value of the first variable divided by the second variable.
* • Print the value of the second variable minus 2, quantity times the first variable (e.g.: Imagine
*  you named the first variable X and the second variable Y. If X is 3 and Y is 4 then Y minus 2
*  quantity times X is 6 because Y minus 2 is 2 and 2 times 3 is 6).
* • Print the values of both original variables again to show that they did not change.
*/

#include <stdio.h> 

int x; 
int y; 

void getInput(void);
void printOut(void); 

int main(void) {
    getInput(); 
}

void getInput(void) {
    printf("| Enter two ints, seperated by spaces\n");
    printf("| ");

    if(scanf("%d %d", &x, &y) != 2) {
        printf("Error Occured, not all input were ints, Try Again.\n");

        // clear past input 
        while (getchar() != '\n');

        getInput(); 
        
    } else {
        printOut(); 
    }
}

/**
 * the printOut method prints out all the equasions from the Desc
 * Desc: Print the values of both variables that were entered by the user.
 *  • Print the value of the first variable times the second variable.
 *  • Print the value of the first variable divided by the second variable.
 *  • Print the value of the second variable minus 2, quantity times the first variable (e.g.: Imagine
 *      you named the first variable X and the second variable Y. If X is 3 and Y is 4 then Y minus 2
 *      quantity times X is 6 because Y minus 2 is 2 and 2 times 3 is 6).
 *  • Print the values of both original variables again to show that they did not change.
 */
void printOut(void) {

    // print out what is stored in the x and y variables 
    printf("| You have selected: X = %d, Y = %d\n", x, y);

    // print out x * y 
    printf("| Times: %d * %d = %d\n", x, y, x*y);

    // x / y 
    printf("| Divided %d / %d = %d\n", x, y, x/y);

    // (y - 2) * x 
    printf("| (y-2) * x = (%d - 2) * %d = %d\n", y, x, (y-2) * x); 

    // orginial variables 
    printf("| Orginal Variables: X = %d, Y = %d\n", x, y);

    // honors extensions 1-2 
    // #1 print the remainder of dividing the second variable by the first variable 
    printf("| Remainder of %d %% %d = %d\n", y, x, y % x); 

    // #2 print the remainder of dividing the first variable plus 3 by the second 
    printf("| Remanider of %d %% %d = %d", (x + 3), y, (x+3) % y);

} // end of lab2.c 
