/**
Insertion Sort:
Algorithm:

1. get box number for get input from user.
2. get input number from user.
3. while a != box number.
4. start loop for sorting
    b != (box number - 1).
5. check current number big from next number.
6. if current number then swap variable one in other.
7. check all number are sorting.
8. print sorting number.
*/

#include<stdio.h>

int main(){

    // declare variable
    int getBoxNumber=0; // get input for box number.

    printf("Please type how many data get input: ");
    scanf("%d",&getBoxNumber);

    int numbers[getBoxNumber]; // declare a array for get number from user.
    int count=0; // declare variable for count.
    int check=1; // declare variable for working loop.

    // working loop for get input number from user.
    for(int i=0; i<getBoxNumber; i++){
        scanf("%d",&numbers[i]);// get input from user.
    }
    // working while loop for sorting number.
    while(check != getBoxNumber){
        // working loop for check number are sort or not.
        for(int i=0; i<(getBoxNumber-1); i++){
            // check current number big from next number.
            if(numbers[i]>numbers[i+1]){
                int temp=numbers[i]; // if big then current number swapping a temp variable.
                numbers[i]=numbers[i+1];// then next number swapping in current index.
                numbers[i+1]=temp;// temp number swapping in next index.
            }
        }

        // working loop for check all number are sorting.
        for(int i=0;i<(getBoxNumber-1);i++){
            // check all number sorting.
            if(numbers[i]<numbers[i+1]){
                count++;// if sorting then count variable increment.
            }
        }

        // check count variable are same user box size.
        if(count == (getBoxNumber-1)){
            break;// if same then break while loop.
        }
        check++;// increment check variable.
    }

    // working loop for show array value.
    for(int i=0;i<getBoxNumber;i++){
        printf("\n %d",numbers[i]); // print number
    }

    return 0;
}
