/* CS261- Assignment 1 - Q.1*/
/*********************************************************************
** Program Filename:Q1.c
** Author: Farrukh Rahman
** Date: 1-18-17
** Description: allocates heap memory for ten students, generates
 *              random ID's and scores and summarizes their info.
** Input:   No user input.
** Output:  Prints students ID's and scores, as well as min/max & avg.
*********************************************************************/
 
#include <stdio.h>
#include<stdlib.h>
#include<math.h>

struct student{
	int id;
	int score;
};

struct student* allocate(){
     /*Allocate memory for ten students*/
     struct student* newStudents = malloc(10 * sizeof(struct student));
     /*return the pointer*/
     return newStudents;
}


void generate(struct student* students){
     /*Generate random and unique ID and scores for ten students, ID being between 1 and 10, scores between 0 and 100*/
     int a[9];
    // this loop generates  the 10 ID's as well as
    // randomly assigns each student a score between 0 and 100
    for (int j = 0; j < 10; j++){
        a[j] = j+1;
        students[j].score = rand() % 101;
    }

    // this loop takes the 10 ID's and shuffles them by iterating down.
     for (int i = 9; i > 0; i--){
         int j = rand() % (i+1);
         int temp = a[i];
         a[i] = a[j];
         a[j] = temp;
     }

    // loop to assign the shuffled ID's to each student.
    for (int i = 0; i < 10; i++){
        students[i].id = a[i];
    }

}

void output(struct student* students){
     /*Output information about the ten students in the format:
              ID1 Score1
              ID2 score2
              ID3 score3
              ...
              ID10 score10*/
    for (int i = 0; i < 10; i++){
        printf("ID%d Score%d\n", students[i].id, students[i].score);
    }
}

void summary(struct student* students){
     /*Compute and print the minimum, maximum and average scores of the ten students*/
    int min, max;
    double sum, average;

    min = students[0].score;
    max = students[0].score;
    for (int i = 0; i < 9;i++){

        sum += students[i].score;
        if (students[i].score < min){
            min = students[i].score;
        }
        else if (students[i].score > max){
            max = students[i].score;
        }

    }
    average = sum / 10;
    printf("Min:%d Max:%d Average:%f\n", min, max, average);

}

void deallocate(struct student* stud){
     /*Deallocate memory from stud*/
    if (stud != NULL) {
        free(stud);
        stud = NULL;
    }
}

int main(){
    struct student* stud = NULL;
    
    /*call allocate*/
    stud = allocate();
    /*call generate*/
    generate(stud);
    /*call output*/
    output(stud);
    /*call summary*/
    summary(stud);
    /*call deallocate*/
    deallocate(stud);
    return 0;
}
