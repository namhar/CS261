/* CS261- Assignment 1 - Q. 0*/
/*********************************************************************
** Program Filename: Q0.c
** Author:  Farrukh Rahman
** Date: 1-17-18
** Description: Practice pointers functions by passing and printing pointers.
** Input: no user input
** Output: print address and values of pointers.
*********************************************************************/
 
#include <stdio.h>
#include <stdlib.h>

void fooA(int* iptr){
     /*Print the value pointed to by iptr*/
     printf("%d\n",*iptr);
     /*Print the address pointed to by iptr*/
     printf("%p\n", iptr);
     /*Print the address of iptr itself*/
     printf("%p\n", &iptr);
}

int main(){
    
    /*declare an integer x*/
    int x = 42;
    /*print the address of x*/
    printf("%p\n",&x);
    /*Call fooA() with the address of x*/
    fooA(&x);
    /*print the value of x*/
    printf("%d\n", x);
    return 0;
}
