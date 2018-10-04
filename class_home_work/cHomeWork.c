#include <stdio.h> // call header file
#include <math.h> // call header file for user math function

int main(){

    // ------------  all math operation using two number ---------------------

    // declare variable for do all math operation
    int numberA=0,numberB=0;

    printf("Math operation between two number,\nFirst number:"); // print massage
    scanf("%d",&numberA); // get first number
    printf("Second number:"); // print massage
    scanf("%d",&numberB); // get second number

    printf("\n\nTotal sum is = %d",numberA+numberB); // print two number sum
    printf("\nTotal subtract is = %d",numberA-numberB); // print two number subtract
    printf("\nTotal multi is = %d",numberA*numberB); // print two number multi
    printf("\nTotal quotient is = %d",numberA/numberB); // print two number quotient
    printf("\nTotal remainder is = %d",numberA%numberB); // print two number remainder


    // ------------- Find area of circle and circumference -----------------------

    int radiusOfCircle=0; // declare variable for get radius of circle

    printf("\n\n-----------------------\nType radius of circle: "); // print massage
    scanf("%d",&radiusOfCircle); // get radius

    /** print area of circle
        formula is:
        area = 3.1416 X radiusOfCircle^2 */

    printf("\nArea of circle = %.3lf",(3.1416*pow(radiusOfCircle,2)));

    /** print Circumference of circle
        formula is:
        area = 2 X 3.1416 X radiusOfCircle */

    printf("\nCircumference of circle = %.3lf CM",(2*3.1416*radiusOfCircle));

    // --------------  Convert CM to M and KM --------------------------------------

    int getCM=0; // declare variable for get Cm value

    printf("\n\n-----------------------\nType CM: "); // print massage
    scanf("%d",&getCM); // get CM value

    /** Convert CM to M and KM
        formula is:
        M = CM X 0.01
        KM = CM X ( 1 X 10^-5) */

    printf("\nConvert CM to M is = %.3lf M",(getCM*0.01)); // print M
    printf("\nConvert CM  to KM is = %.3lf KM",(getCM*(1*pow(10,-5)))); // print KM

    // ------------ Find rectangle Area ---------------------------------------------

    // declare variable for get width and hight of rectangle
    int widthOfRectangle=0,lengthOfRectangle=0;

    printf("\n\n-----------------------\nArea of Rectangle,\nType Width of Rectangle: "); // print massage
    scanf("%d",&widthOfRectangle); // get width
    printf("Type Length of Rectangle: "); // print massage
    scanf("%d",&lengthOfRectangle); // get length

    /** Area of rectangle
        formula is:
        area = w X l */

    printf("\n\nArea of Rectangle = %d",widthOfRectangle*lengthOfRectangle); // print area

    // ---------------  Find square area -------------------------------------------

    int sideOfSquare=0; // declare variable for get side of square

    printf("\n\n-----------------------\nArea of Square,\nType Side of Square: "); // print massage
    scanf("%d",&sideOfSquare); // get side

    /** Area of Square
        formula is:
        area = side^2 */

    printf("\n\nArea of Square is = %.3lf",pow(sideOfSquare,2)); // print area

    // -------------- Convert C to F and F to C -------------------

    int getCelsius=0,getFahrenheit=0; // declare variable C and F

    printf("\n\n-----------------------\nConvert C to F & F to C,\nType Celsius: "); // print massage
    scanf("%d",&getCelsius); // get Celsius

    /** Convert C to F
        formula is:
        f = (c x 1.8)+32 */

    printf("\nFahrenheit is = %.3lf",((getCelsius*1.8)+32)); // print Fahrenheit
    printf("\n\nType Fahrenheit: "); // print massage
    scanf("%d",&getFahrenheit); // get F

    /** Convert F to C
        formula is:
        c = (f - 32)/1.8 */

    printf("\nCelsius is = %.3lf\n\n\n",((getFahrenheit-32)/1.8)); // print C


    // -------------- Calculate total and average -------------------

    int subjectsMark[5],totalMark=0; // declare variable for count mark

    printf("\n\n-----------------------\nCalculate total and average, Type 5 subject mark: \n\n"); // print massage

    for(int i=0; i<5; i++){
        scanf("%d",&subjectsMark[i]); // get subject mark
    }

    for(int i=0; i<5; i++){
        totalMark += subjectsMark[i]; // sum all subject marks
    }

    printf("\n\nTotal subject mark is = %d",totalMark); // print total subject mark
    printf("\nAverage subject mark is = %d\n\n\n",totalMark/5); // print average subject mark


    return 0;
}
