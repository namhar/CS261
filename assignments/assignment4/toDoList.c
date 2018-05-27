/* CS261- Assignment 4 - toDoList*/
/* Name: Farrukh Rahman
 * Date: 3-5-18
 * Solution description: todolist.c
 */
 


#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include "toDoList.h"


/*  Create a task from the description and the priority

    param:  priority    priority of the task
    param:  desc    	pointer to the description string
    pre:    none
    post:   none
	ret: 	a task with description and priority
*/
TYPE createTask (int priority, char *desc) 
{
	TYPE newTask;
	newTask.priority = priority;
	strcpy(newTask.description, desc);
	return newTask;
}

/*  Save the list to a file

    param:  heap    pointer to the list
    param:  filePtr	pointer to the file to which the list is saved
    pre:    The list is not empty
    post:   The list is saved to the file in tab-delimited format.
			Each line in the file stores a task, starting with the 
			task priority, followed by a tab character (\t), and 
			the task description.
			
			The tasks are not necessarily stored in the file in 
			priority order. 
	
*/
void saveList(DynArr *heap, FILE *filePtr)
{
  	/* FIX ME */
	Task taskTemp;
	assert(sizeDynArr(heap) > 0);
//	filePtr = fopen("todolist.txt", "w");
	if (filePtr == NULL){
		fprintf(stderr, "Cannot open %s\n", "todolist.txt");
	}
	for (int i = 0; i < sizeDynArr(heap); i++){
		//taskTemp = &heap[i];
		taskTemp = getDynArr(heap,i);
		fprintf(filePtr, "%d \t %s\n", taskTemp.priority, taskTemp.description);
	}
	//fclose(output_file);
}

/*  Load the list from a file

    param:  heap    pointer to the list
    param:  filePtr	pointer to the file
    pre:    none
    post:   The tasks are retrieved from the file and are added to the list.
			Refer to the saveList() function for the format of tasks in the file				
*/
void loadList(DynArr *heap, FILE *filePtr)
{
  	/* FIX ME */
	  
	//deleteDynArr(heap);
	//DynArr *newHeap = newDynArr(1);
	Task taskTemp;
	int priority;
  	char fileInput[200];  
  	char taskName[128];
  	
  while(fgets(fileInput, sizeof(fileInput), filePtr) != 0)
    {
      sscanf(fileInput, "%d\t %[^\n]s \n", &priority, taskName);
      taskTemp = createTask(priority, taskName);
      addHeap(heap, taskTemp);
    }
	//heap = newHeap;
}

/*  Print the list

    param:  heap    pointer to the list
    pre:    the list is not empty
    post:   The tasks from the list are printed out in priority order.
			The tasks are not removed from the list.
*/
void printList(DynArr *heap)
{
  	/* FIX ME  */
	  assert(sizeDynArr(heap) > 0);
	  Task tempTask;
	  DynArr *temp = newDynArr(1);
	  copyDynArr(heap,temp);
	  while (sizeDynArr(temp) > 0){
		  tempTask = getMinHeap(temp);
		  printf("%d \t %s\n", tempTask.priority, tempTask.description);
		  removeMinHeap(temp);
	  }
	deleteDynArr(temp);	  
}

/*  Compare two tasks by priority

    param:  left    first task
    param:  right 	second task
    pre:    none
    post:   none
	ret: 	-1 if priority of left < priority of right
			1 if priority of left > priority of right
			0 if priority of left = priority of right
*/
int compare(TYPE left, TYPE right)
{
	if (left.priority < right.priority)
		return -1;
	else if (left.priority > right.priority)
		return 1;
	else
		return 0;
}
