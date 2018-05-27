/* CS261- Assignment 1 - Q.2*/
/*********************************************************************
** Program Filename:Q2.c
** Author: Farrukh Rahman
** Date: 1-18-17
** Description: passes 3 integers into a function, 2 as pointers and 1
 * by value.
** Input:   No user input.
** Output:  prints values x, y,z initially and post processing from
 *          function foo.
*********************************************************************/
 
#include <stdio.h>
#include <stdlib.h>

int foo(int* a, int* b, int c){
    /*Set a to double its original value*/
    *a *= 2;
    /*Set b to half its original value*/
    *b *= 0.5;
    /*Assign a+b to c*/
    c = *a + *b;
    /*Return c*/
    return c;
}

int main(){
    /*Declare three integers x,y and z and initialize them to 5, 6, 7 respectively*/
    int x = 5, y = 6, z = 7;
    /*Print the values of x, y and z*/
    printf("x%d y%d z%d \n", x,y,z);
    /*Call foo() appropriately, passing x,y,z as parameters*/
    int f = foo(&x,&y,z);
    /*Print the value returned by foo*/
    printf("foo: %d\n", f);
    /*Print the values of x, y and z again*/
    printf("x%d y%d z%d \n", x,y,z);
    /*Is the return value different than the value of z?  Why?*/
    // the return value is different than the value of z because z was passed in by value.
    // Thus when the function foo was called, the pointer to the integers a and b were passed however
    // a copy of the variable z was passed in.  Therefore any changes made to c within foo would not persist since
    // the scope of c is limited to the function foo.
    return 0;
}
    
    
