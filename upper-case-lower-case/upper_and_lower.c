#include<stdio.h>

int main(){

    char str[20]; // Declare char array for store string.

    printf("Please type string: "); // print some text.
    gets(str); // get string from user { gets() is lib function }

    printf("\n\nUpper case use lib function: "); // print some text
    int i=0; // declare variable for access index.
    // start loop for make upper case char
    while(str[i]){
        printf("%c",toupper(str[i])); // make char upper case { toupper() is lib function for make upper}
        i++; // increment i
    }

    printf("\n\nLower case use lib function: "); // print some text.
    int j=0; // declare j for access index.
    // start loop for make lower case char
    while(str[j]){
        printf("%c",tolower(str[j])); // make char lower case using { tolower() is lib function for make lower }
        j++; // increment j
    }


    printf("\n\nUpper case use raw: "); // print some text
    int k=0; // declare k for access index.
    // start loop for make upper case char
    while(str[k]){
        // check current char lower are not? using ANSI code.
        if((int)str[k] < 123 && (int)str[k] > 96){
            printf("%c",(int)str[k]-32); // if lower then make upper using 32 bit code.
        }else{
            printf("%c",str[k]); // else print current char
        }
        k++; // increment k
    }



    printf("\n\nLower case use raw: "); // print some text
    int s=0; // declare s for access index.
    // start loop for make lower case char
    while(str[s]){
        // check current char upper are not? using ANSI code
        if((int)str[s] < 91 && (int)str[s] > 64){
            printf("%c",(int)str[s]+32); // if upper then make lower using 32 bit code
        }else{
            printf("%c",str[s]); // else print current char
        }
        s++; // increment s
    }


    printf("\n\n"); // print some new line.


    return 0;
}
