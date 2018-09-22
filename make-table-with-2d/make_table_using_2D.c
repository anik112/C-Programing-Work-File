#include<stdio.h> // include header lib function

/**

>> 2D array meaning single array in another array.
>> i declare a 2D array is count[2][2]
    now this array make won index like as

    -----------
    | 00 | 01 |
    -----------
    | 10 | 11 |
    -----------

    first index is = 00
            second = 01
             third = 10
             forth = 11

    value:
        00 = 1,
        01 = 2,
        10 = 3,
        11 = 4

        like this table:

    index->   0 | 1
            |-------|
          0 | 1 | 2 |
            |-------|
          1 | 3 | 4 |
            |-------|

*/


// main function
int main(){

    int tableSize=0; // declare variable for get array size from user.

    printf("Table size: "); // print text
    scanf("%d",&tableSize); // get array size form user.
    printf("\n"); //print new line

    int table[tableSize][tableSize]; // declare 2D array array size = tableSize.
    // start loop for access 2D array first index
    for(int i=0; i<tableSize; i++){
        // inner loop for access second index in 2D array
        for(int j=0; j<tableSize; j++){
            printf("Number[0 to 9]: "); // print text
            scanf("%d",&table[i][j]); // get one by one input from user.
        }
    }


    printf("\nTable [ %d X %d ]:\n\n",tableSize,tableSize); // print some text.
    // start loop for print line in console
    for(int i=1; i<=tableSize*5; i++){
        printf("-"); // print -
    }

    printf("\n"); //  print new line.
    // loop for print array data in a table
    for(int i=0; i<tableSize; i++){
        // inner loop for access index
        for(int j=0; j<tableSize; j++){
            printf("| "); // print bar
            printf("%d |",table[i][j]); // print data
        }
        printf("\n"); // print new line
        // loop for make line in console
        for(int i=1; i<=tableSize*5; i++){
            printf("-");
        }
        printf("\n"); // print new line.
    }

    return 0;
}
