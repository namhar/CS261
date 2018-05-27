/* CS261- Assignment 2 - Q.3*/
/*********************************************************************
** Program Filename:Q2 part 3
** Author: Farrukh Rahman
** Date: 1-29-17
** Description: Part 3: Application of the stack - checking balanced
						Parentheses, braces, and brackets.
** Input:   User inputs string containing parentheses, braces, or brackets
** Output:  whether user input is balanced or unbalanced.
*********************************************************************/

/*	stack.c: Stack application. */
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "dynArray.h"


/* ***************************************************************
Using stack to check for unbalanced parentheses.
***************************************************************** */

/* Returns the next character of the string, once reaches end return '0' (zero)
	param: 	s pointer to a string 	
	pre: s is not null		
*/
char nextChar(char* s)
{
	static int i = -1;	
	char c;
	++i;	
	c = *(s+i);			
	if ( c == '\0' )
		return '\0';	
	else 
		return c;
}

/* Checks whether the (), {}, and [] are balanced or not
	param: 	s pointer to a string 	
	pre: s is not null	
	post:	
*/
int isBalanced(char* s)
{
	/* FIXME: You will write this function */		
	char ch;
	struct DynArr *stack = newDynArr(20);
	assert (stack !=0);
	do{
		ch = nextChar(s); 
		// if appropriate charcter, push onto stack.
		if(ch == '{' || ch == '(' || ch == '[')
			pushDynArr(stack, ch);
		if(ch == '}' || ch == ')' || ch == ']'){
			// check for empty stack, if empty then unbalanced. otherwise pop off stack
			if(isEmptyDynArr(stack)){
					deleteDynArr(stack);
					return 0; 
			}
			else{
				popDynArr(stack);
			}
		}
	}while(ch != '\0');
	// if the stack is empty at the end, then the string was balanced.
	if(isEmptyDynArr(stack)){
		deleteDynArr(stack);
		return 1; 
	}
	// otherwise return false.
	else{
		deleteDynArr(stack);
		return 0; 
	}
}

int main(int argc, char* argv[]){
	
	char* s=argv[1];	
	int res;
	
	printf("Assignment 2\n");

	res = isBalanced(s);

	if (res)
		printf("The string %s is balanced\n",s);
	else 
		printf("The string %s is not balanced\n",s);
	
	return 0;	
}

