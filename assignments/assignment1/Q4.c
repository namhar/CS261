/* CS261- Assignment 1 - Q.4*/
/*********************************************************************
** Program Filename:Q4.c
** Author: Farrukh Rahman
** Date: 1-18-17
** Description: allocates heap memory for size of n array of students and
 *              randomly fills ID's and scores. Students are then sorted
 *              in ascending order by score.
** Input:   No user input.
** Output:  Prints unsorted and sorted array of students..
*********************************************************************/
 
#include <stdio.h>
#include<stdlib.h>
#include<math.h>

struct student{
	int id;
	int score;
};

void sort(struct student* students, int n){
     /*Sort the n students based on their score*/

    struct student tmp;
    for (int i = n-1; i > 0; i--){

        for (int i = 0; i < n-1; i++){
            if (students[i].score > students[i+1].score){
                tmp = students[i];
                students[i] = students[i+1];
                students[i+1] = tmp;
            }
        }
    }
}

int main(){
    /*Declare an integer n and assign it a value.*/
    int n = 20;
    /*Allocate memory for n students using malloc.*/
    struct student* students = malloc(n * sizeof(struct student));


    /*Generate random and unique IDs and random scores for the n students, using rand().*/

    int a[n-1];
    // this loop generates  the 10 ID's as well as
    // randomly assigns each student a score between 0 and 100
    for (int j = 0; j < n; j++){
        a[j] = j+1;
        students[j].score = rand() % 101;
    }

    // this loop takes the 10 ID's and shuffles them.
    for (int i = n-1; i > 0; i--){
        int j = rand() % (i+1);
        int temp = a[i];
        a[i] = a[j];
        a[j] = temp;
    }

    // loop to assign the shuffled ID's to each student.
    for (int i = 0; i < n; i++){
        students[i].id = a[i];
    }
    /*Print the contents of the array of n students.*/
    printf("\nUnsorted Students:  \n");
    for (int i = 0; i < n; i++){
        printf("ID%d Score%d\n", students[i].id, students[i].score);
    }
    /*Pass this array along with n to the sort() function*/
    sort(students,n);
    /*Print the contents of the array of n students.*/
    printf("\nSorted Students:  \n");
    for (int i = 0; i < n; i++){
        printf("ID%d Score%d\n", students[i].id, students[i].score);
    }
    free(students);
    return 0;
}
