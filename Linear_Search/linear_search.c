#include <stdio.h> // call header file for default function
#include <stdbool.h> // call header for use boolean data type

// main function
int main(){

    // declare variable
    int inputs=0,search_number=0;

    printf("Type how many data in stored: "); // print massage
    scanf("%d",&inputs); // get value for set array index

    int total_number[inputs]; // declare array for get number list

    // loop for get numbers list
    for(int i=0; i<inputs; i++){
        scanf("%d",&total_number[i]); // get single number from user
    }

    printf("\nType witch number you want to search: "); // print massage
    scanf("%d",&search_number); // get search number from user

    int k=0; // declare variable for access array index
    bool error=false; // declare boolean variable for get error

    // loop for search number
    while(k <= (inputs-1)){
        // check search number in this array
        if(search_number == total_number[k]){
            // if maching number then print number and array index
            printf("\nYou search number is %d and find in index of total_number[%d]\n",total_number[k],k+1);
            error=false; // set error false
            break; // get out from the loop
        }else{
            error=true; // if search number is not present in this array then make error
        }
        k++; // k increment
    }
    // check error are present in this
    if(error){
        // then show massage
        printf("\nSorry your entered number is not present in the list\n");
    }


    return 0;
}
