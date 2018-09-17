#include<stdio.h>

int main(){

    // declare variable
    int getBoxNumber=0; // get input for box number.

    printf("Please type how many data get input: ");
    scanf("%d",&getBoxNumber);

    int numbers[getBoxNumber]; // declare a array for get number from user.
    int count=0; // declare variable for count.
    int check=0; // declare variable for working loop.

    // working loop for get input number from user.
    for(int i=0; i<getBoxNumber; i++){
        printf("number %d:",i+1);
        scanf("%d",&numbers[i]);// get input from user.
    }

    // start loop for find min number.
    for(int i=0; i<getBoxNumber; i++){
        check=0; // set check variable for avoid error
        // loop for compare current number and all number in array
        for(int j=0;j<getBoxNumber; j++){
            // check current number small from array all number.
            if(numbers[i]<numbers[j]){
                check++;// if small then count increment.
            }
        }
        // if count are equal to box number then
        if(check==(getBoxNumber-1)){
            printf("\n The MIN number is: %d",numbers[i]); // print  number
            break;// and break loop
        }
    }

    return 0;
}
