/*****************************************************************************
 * lab10.c
 * Starter Code By Jim Ries
 * Fall 2024
 * Student:     J-D-J123 
 * Date:        10/25/2024
 * TLA:         Ethan Johnson (Not Related) 
 * Desc:        print all the 2D arrays and then sort them 
 *                  only adjust the PrintStrings() method and the 
 *                  BubbleSortStrings() method. 
 *****************************************************************************/
#include <stdio.h>
#include <string.h>

void PrintStrings(char * * strings, int count)
{

    for(int x = 0; x < count; x++) {

        printf("      - %s\n", *(strings + x));
    }
}

void BubbleSortStrings (char * * strings, int count, int fIsAscending)
{
    // printf("count = %d\n", count); // starts with 12
    // printf("fIsAscending = %d\n", fIsAscending); // starts with 0

    for(int r = 0; r < count; r++) {

        // count goes untill c is equal to count - r - 1
        for(int c = 0; c < count - r - 1; c++) {
            
            // if strings + c is greater than strings + c + 1 then it is greater as ASCII
            // and should swap indexes 
            if(strcmp(*(strings + c),*(strings + c + 1)) > 0){

                // swap elements 
                char *tempPtr = *(strings + c);
                *(strings + c) = *(strings + c + 1); 
                *(strings + c + 1)  = tempPtr; 
            }
        }
    }       
}


int main(void)
{
    // Test 1
    char * dogsOfJimR[] = 
    {
        "Murphy",
        "Cisco",
        "Bandit",
        "Poncho",
        "Cuddles",
        "Frisky",
        "Vicki",
    };

    // size is 12 
    int countDogs = sizeof(dogsOfJimR)/sizeof(dogsOfJimR[0]);

    printf("Original dogs:\n");

    // call is 12 of countDogs = count 
    PrintStrings(dogsOfJimR, countDogs);
    printf("\n");

    BubbleSortStrings(dogsOfJimR,countDogs,1);

    printf("Sorted dogs\n");
    PrintStrings(dogsOfJimR, countDogs);
    printf("\n");


    // Test 2
    char * heroesOfJimR[] = 
    {
        "Spiderman",
        "Captain America",
        "Wolverine",
        "Cyclops",
        "Iron Man",
        "Black Widow",
        "Hulk",
        "Collosus",
        "Nightcrawler",
        "Storm",
        "Thunderbird",
        "Sunfire",
    };
    int countHeroes = sizeof(heroesOfJimR)/sizeof(heroesOfJimR[0]);

    printf("Original heroes:\n");
    PrintStrings(heroesOfJimR, countHeroes);
    printf("\n");

    BubbleSortStrings(heroesOfJimR,countHeroes,1);

    printf("Sorted heroes\n");
    PrintStrings(heroesOfJimR, countHeroes);
    printf("\n");

    // Test 3
    char * dummy[] =
    {
        "two",
        "one",
    };
    int countDummy = sizeof(dummy)/sizeof(dummy[0]);

    printf("Original dummy:\n");
    PrintStrings(dummy,countDummy);
    printf("\n");

    BubbleSortStrings(dummy,0,1);

    printf("Should not have changed\n");
    PrintStrings(dummy,countDummy);
    printf("\n");

    BubbleSortStrings(dummy,1,1);
    printf("Still should not have changed\n");
    PrintStrings(dummy,countDummy);
    printf("\n");

    BubbleSortStrings(dummy,countDummy,1);
    printf("Finally changed\n");
    PrintStrings(dummy,countDummy);
    printf("\n");


    // Honors only testing.  You can ignore
    // if you are not in the honors section
    printf("**** Honors only ****\n");
    BubbleSortStrings(dogsOfJimR,countDogs,0);
    printf("Sorted descending dogs\n");
    PrintStrings(dogsOfJimR, countDogs);
    printf("\n");
    BubbleSortStrings(heroesOfJimR,countHeroes,0);
    printf("Sorted descending heroes\n");
    PrintStrings(heroesOfJimR, countHeroes);
    printf("\n");
    printf("*********************\n");

} // end of lab10.c
