#include <stdio.h> // call header file


// main function
int main(){


    // declare variable
    int inputs=0,search_number=0;

    printf("Type how many data in stored: "); // print massage
    scanf("%d",&inputs); // get value for set array index

    printf("Type data in sorted like [ 1,2,3 ] or [ 3,2,1 ]: \n"); // print massage

    int total_number[inputs]; // declare array for get number list

    // loop for get numbers list
    for(int i=0; i<inputs; i++){
        scanf("%d",&total_number[i]); // get single number from user
    }

    int beg=1; // declare begin index
    int end=(int)(sizeof(total_number)/sizeof(total_number[0])); // declare ending index
    int mid=(int)(beg+end)/2; // declare mid index
    int checkUp=0,checkDown=0; // declare checkUp and checkDown variable for check array are sorted

    // loop for check witch rules flowing this list
    for(int i=0; i<(inputs-1); i++){
        // if number down to up like [ 1,2,3,4,5 ]
        if(total_number[i] < total_number[i+1]){
            checkDown++; // then down variable increment
        }
        // else if check up to down like [ 5,4,3,2,1 ]
        else if(total_number[i] > total_number[i+1]){
            checkUp++; // then up variable increment
        }
    }

    // if number list are sorted using down to up
    if(checkDown == (inputs-1)){
        // then loop for find item in this array
        while(beg <= end){

            printf("\nType witch number you want to search: "); // print massage
            scanf("%d",&search_number); // get search number from user

            // if searching number is lower then mid number in this list
            if(search_number < total_number[mid]){
                end=mid; // then make end is mid
            }
            // else if searching number is upper then mid number
            else if(search_number > total_number[mid]){
                beg=mid; // then make begin is mid
            }
            // else if searching number is equal to mid number of array
            else if(search_number == total_number[mid]){
                printf("Number found position is: %d\n",mid); // then print index
                break; // and break the loop
            }
            mid=(int)(beg+end)/2; // modified mid variable
        }

    }
    // else if number list are sorted using up to down
    else if(checkUp == (inputs-1)){

        printf("\nType witch number you want to search: "); // print massage
        scanf("%d",&search_number); // get search number from user

        // then loop for find item in this array
        while(beg <= end){
            // if searching number is upper then mid number in this list
            if(search_number > total_number[mid]){
                end=mid; // then make end is mid
            }
            // else if searching number is lower then mid number
            else if(search_number < total_number[mid]){
                beg=mid; // then make begin is mid
            }
            // else if searching number is equal to mid number of array
            else if(search_number == total_number[mid]){
                printf("Number found position is: %d\n",mid); // then print massage
                break; // and break the loop
            }
            mid=(int)(beg+end)/2; // modified mid variable
        }

    }
    // else print number is not sorted
    else{
        printf("\nThis number list is not sorted.\n");
    }

    return 0;
}
