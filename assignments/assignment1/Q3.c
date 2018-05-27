/* CS261- Assignment 1 - Q.3*/
/*********************************************************************
** Program Filename:Q3.c
** Author: Farrukh Rahman
** Date: 1-18-17
** Description: allocates heap memory for size of n integer array and
 *              randomly fills it.  The array is then sorted in ascending order.
** Input:   No user input.
** Output:  Prints unsorted and sorted array.
*********************************************************************/
 
#include <stdio.h>
#include<stdlib.h>
#include<math.h>


void sort(int* number, int n){
     /*Sort the given array number , of length n*/
    int tmp;
    for (int i = n-1; i > 0; i--){

        for (int i = 0; i < n-1; i++){
            if (number[i] > number[i+1]){
                tmp = number[i];
                number[i] = number[i+1];
                number[i+1] = tmp;
            }
        }

    }

}

int main(){
    /*Declare an integer n and assign it a value of 20.*/
    int n = 20;
    
    /*Allocate memory for an array of n integers using malloc.*/
    int *arr = malloc(n * sizeof(n));

    /*Fill this array with random numbers, using rand().*/
    for (int i = 0; i < n; i ++){
        arr[i] = rand();
    }
    /*Print the contents of the array.*/
    printf("\nunsorted array:\n");
    for (int i = 0; i < n; i++){
        printf("%d\n",arr[i]);
    }
    /*Pass this array along with n to the sort() function of part a.*/
    sort(arr, n);
    /*Print the contents of the array.*/
    printf("\nsorted array:\n");
    for (int i = 0; i < n; i++){
        printf("%d\n", arr[i]);
    }
    free(arr);
    return 0;
}
