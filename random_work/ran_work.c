#include<stdio.h>


int main(){

    int numberA=10;
    int numberB=10;
    int numberC=5;


    printf("Two number ( %d + %d ) is: %d\n",numberA,numberB,numberA+numberB);
    printf("Two number ( %d - %d ) is: %d\n",numberA,numberC,numberA-numberC);
    printf("Two number ( %d * %d ) is: %d\n",numberA,numberB,numberA*numberB);
    printf("Two number ( %d / %d ) is: %d\n",numberA,numberC,numberA/numberC);
    printf("Two number ( %d % %d ) is: %d\n\n",numberA,numberC,numberA%numberC);


    int sum=0;
    int multi=1;

    for(int i=1;i<=5;i++){
        printf("%d, ",i);
        sum += i;
        multi *= i;
    }

    printf("Total number + is:  %d\n\n",sum);
    printf("Total number X is:  %d\n\n",multi);



    int factorial=3;
    int getValue=1;

    for(int i=factorial; i>0; i--){
        getValue *= i;
    }

    printf("The number %d factorial is:  %d\n\n",factorial,getValue);

    return 0;
}
