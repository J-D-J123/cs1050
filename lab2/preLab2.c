/**
* Name: J-D-J123
* Date: 8/27/2024 
* File: (preLab) lab2.c 
* Desc: print the values of A, B, C, D
*   print the value of the sum of B and C
*   print the value of the product of A and D. 
*   print the value of the integer quotient of A divided by C. 
*   Print the value of the integer remainder of C divided by D.
*   Print the value of the quantity A times C divided (integer division) 
*   the quantity B plus D. 
*/

#include <stdio.h> 

int a; 
int b; 
int c; 
int d; 

void storeVariables(void); 
void printOut(void); 

int main(void) {
    storeVariables(); 
    return 0; 
}

void storeVariables(void) {

    printf("Enter 4 Integeres, seperated by spaces.\n");

    if (scanf("%d %d %d %d", &a, &b, &c, &d) != 4) {
        printf("Error Reading ints try again!");

        // reset input (clears the input for the next input)
        // fixes it so it does not go on forever 
        while (getchar() != '\n');
        
        storeVariables(); 
    } else {
        // call to printOut() which will print out the variables with math
        printOut(); 
    }
}

/**
* the printOut(void) method does not return but is 
*   used to test the var array of characters that 
*   will be used to store into the variables after
*   the user inputs them into the terminal. 
*/
void printOut(void) {

    // uncomment to test! 
    // printf("%d, ", a); 
    // printf("%d, ", b);
    // printf("%d, ", c);
    // printf("%d, ", d);  

    /**
    * print the values of A, B, C, D
    * print the value of the sum of B and C
    * print the value of the product of A and D. 
    * print the value of the integer quotient of A divided by C. 
    * Print the value of the integer remainder of C divided by D.
    * Print the value of the quantity A times C divided (integer division) 
    * the quantity B plus D. 
    */ 

    printf("\n");
    
    // equasion 1 --> sorry i can't spell  
    printf("Numbers: A = %d, B = %d, C = %d, D = %d\n", a, b, c, d);

    // equasion 2
    printf("Sum of B and C: %d + %d = %d\n", b, c, b + c);

    // equasion 3
    printf("Product of A and D: %d * %d = %d\n", a, d, a * d);

    // equasion 4
    printf("Sum of B and C: %d / %d = %d\n", a, c, a / c);

    // equasion 5
    printf("Value of C mod by D: %d %% %d = %d\n", c, d, c % d);

    // equasion 6
    printf("Value of A times C divided by B plus D: %d * %d / %d + %d = %d\n", a, c, b, d, (a * c)/(b + d));

}
