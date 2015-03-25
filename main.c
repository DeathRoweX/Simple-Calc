#include <stdio.h>  /* printf, sscan, fgets, putchar */
#include <stdlib.h> /* strol */
#include <limits.h> /* UNINT_MAX */

/*input function, returns unsigned in, requires character argument*/
unsigned int input(const char *str)
{
    char inputArray[200], *endptr; //array for input storage and end pointer
    int count; //stores array and end pointer count
    long int returnInput; //stores converted input to be returned

    /*Request input*/
    printf("Enter the %s number: ", str);

    /*store input in array then validate entry is not equal to 0*/
    if(fgets(inputArray, sizeof(inputArray),stdin)==0)return 0;

    /*read and count the array, verifying the array has a value*/
    if(sscanf(inputArray, " %n", &count)==0 && count>=0 && inputArray[count]=='\0')return 0;

    /*convert the character array into a base 2 long int*/
    returnInput = strtol(inputArray, &endptr, 2);

    /*read and count end pointer, verifying it has no value*/
    if(sscanf(endptr, " %n", &count)!=0 || count<0 || endptr[count]!='\0')return 0;

    /*verify the return input is within min and max limits*/
    if(returnInput<=0 || returnInput > UINT_MAX)return 0;

    /*return input*/
    return(unsigned int)returnInput;
}

/*Convert long int to binary and print to screen*/
void printBnr(unsigned long int value)
{
    /*start converting the supplied value to binary, by the value modulo 2*/
    int binary = value%2;
    /*shift bits in value to the right by 1*/
    value>>=1;
    /*determine if the value has been processed completely, if not perform a recursive call*/
    if(value!=0)printBnr(value);
    /*when fully processed, print the remainder adding an extra 0*/
    putchar(binary+'0');
}

/*main function, accepts no arguments*/
int main(void)
{
    for(;;) /*indefinite for loop, break to exit*/
    {
        unsigned int x,y; /*input variables*/
        long int sum, diff; /*stores the sum and difference of x and y*/
        unsigned long int prod; /*stores the product of x and y*/

        /*call for user inputs, breaking the loop if the returned input is equal to 0*/
        x = input("first");
        if(x==0)break;
        y = input("second");
        if(y==0)break;

        /*perform calculations for provided inputs*/
        sum=x+y, diff=x-y, prod=x*y;

        /*Print inputs via printBnr function*/
        printf("1st = ");printBnr(x);
        printf("\n2nd = ");printBnr(y);

        /*Print calculation results by calling the printBnr function*/
        printf("\nSum = ");printBnr(sum);
        printf("\nDifference = ");
        /*If the difference is negative, inverse the difference*/
        if(diff<0){putchar('-');printBnr(-diff);}else printBnr(diff);
        printf("\nProduct = ");printBnr(prod);
        putchar('\n');
    }
    return 0;
}
