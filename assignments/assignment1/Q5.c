/* CS261- Assignment 1 - Q.5*/
/*********************************************************************
** Program Filename:Q5.c
** Author: Farrukh Rahman
** Date: 1-18-17
** Description: Takes user input and applies sticky caps to it.
** Input:   user inputs word.
** Output:  prints word in sticky caps format.
*********************************************************************/
 
#include <stdio.h>
#include <stdlib.h>

/*converts ch to upper case, assuming it is in lower case currently*/
char toUpperCase(char ch){
     return ch-'a'+'A';
}

/*converts ch to lower case, assuming it is in upper case currently*/
char toLowerCase(char ch){
     return ch-'A'+'a';
}

void sticky(char* word){
     /*Convert to sticky caps*/
    int i = 0;
    // loops while end of word is not reached.
    while(word[i] != '\0'){
        // checks if even or zero and if its NOT already uppercase.
        if (i % 2 == 0 && !(word[i] >='A' && word[i] <='Z')){
            word[i] = toUpperCase(word[i]);
        }
        // checks if odd and already uppercase.
        else if (i % 2 == 1 && (word[i] >='A' && word[i] <='Z')){
            word[i] = toLowerCase(word[i]);
        }
        i++;
    }
}

int main(){
    /*Read word from the keyboard using scanf*/
    char wordIn[80];  // create stack memory allocation for word up to 80 characters.
    printf("enter a word: \n");
    scanf("%s", wordIn);
    /*Call sticky*/
    sticky(wordIn);
    /*Print the new word*/
    printf("new word: %s\n", wordIn);

    return 0;
}
