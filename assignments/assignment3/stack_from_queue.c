/* CS261- Assignment 3 - Q.3*/
/*********************************************************************
** Program Filename:Q3
** Author: Farrukh Rahman
** Date: 2-3-17
** Description: part 3 - stack from queues.
** Input:   No user input.
** Output:  Prints based on function calls.
*********************************************************************/

/*
 * This is the file in which you'll write the functions required to implement
 * a stack using two queues.  Make sure to add your name and @oregonstate.edu
 * email address below:
 *
 * Name: Farrukh Rahman
 * Email: rahmanfa@oregonstate.edu
 */

#include <assert.h>
#include <stdlib.h>
#include <stdio.h>

#ifndef TYPE
#define TYPE int
#endif

/* All by yourself */

struct link
{
    TYPE value;
    struct link *next;
};

struct listQueue
{
    struct link *firstLink;
    struct link *lastLink;
};

struct listQueue* listQueueCreate(){
    struct listQueue *newListQ = malloc(sizeof(struct listQueue));
    listQueueInit(newListQ);
    return newListQ;
}


void listQueueInit(struct listQueue *q)
{
    struct link *lnk = (struct link *)malloc(sizeof(struct link));
    assert(lnk != 0);
    lnk->next = 0;
    q->firstLink = q->lastLink = lnk;
}

void listQueueAddBack(struct listQueue *q, TYPE e)
{
    struct link *newLink = (struct link *)malloc(sizeof(struct
                                                        link));
    assert(newLink != 0);
    newLink->value = e;
    newLink->next = NULL;
    q->lastLink->next = newLink;
    q->lastLink = newLink;
}
TYPE listQueueFront(struct listQueue *q)
{
    assert(!listQueueIsEmpty(q));
    return q->firstLink->next->value;
}
void listQueueRemoveFront(struct listQueue *q)
{
    assert(!listQueueIsEmpty(q));
    struct link *temp = q->firstLink->next;
    assert(temp != 0);
    if (temp->next)
    {
        q->firstLink->next = temp->next;
    }
    else
    {
        q->firstLink = q->lastLink;
    }
    //free(temp);
}

int listQueueIsEmpty(struct listQueue *q)
{
    // Will only be true when empty
    return q->lastLink == q->firstLink;
}

struct QueueStack {
    struct listQueue *q1;
    struct listQueue *q2;
};


struct QueueStack* QueueStackCreate (){
    struct QueueStack *newStack = malloc(sizeof(struct QueueStack));
    queueStackInit(newStack);
    return newStack;
}

void queueStackInit (struct QueueStack *s){
    s->q1 = listQueueCreate();
    s->q2 = listQueueCreate();
}

void queueStackFree ( struct QueueStack *s){
    assert(s);
    while (!listQueueIsEmpty(s->q1)){
        listQueueRemoveFront(s->q1);
    }
    free(s->q1->firstLink);
    free(s->q2->firstLink);
    free(s->q1);
    free(s->q2);
    free(s);

}

//swaps the two queues in queuestack to maintain queue 1 (q1) as main queue with values.
void swap(struct QueueStack *s){
    struct listQueue *temp;
    temp = s->q1;
    s->q1 = s->q2;
    s->q2 = temp;
}


void queueStackPush( struct QueueStack *s, TYPE d){
    assert(s);
    listQueueAddBack(s->q1, d);
}

TYPE queueStackTop (struct QueueStack *s){
    assert(s);
    assert(!listQueueIsEmpty(s->q1));
    TYPE value;
    int lastVal = 0;
    while (!listQueueIsEmpty(s->q1)){

        if (s->q1->firstLink->next == s->q1->lastLink){
            value = listQueueFront(s->q1);
//            printf("last link is %d\n", value);
        }
        listQueueAddBack(s->q2, listQueueFront(s->q1));
        listQueueRemoveFront(s->q1);
    }
    swap(s);
    return value;
}


void queueStackPop (struct QueueStack *s){
    assert(s);
    assert(!listQueueIsEmpty(s->q1));
    TYPE value;
    int lastVal = 0;
    while (!listQueueIsEmpty(s->q1))
    {

        if (s->q1->firstLink->next == s->q1->lastLink)
        {
            value = listQueueFront(s->q1);
            printf("removing: %d\n", value);
            listQueueRemoveFront(s->q1);
        }
        else{
            listQueueAddBack(s->q2, listQueueFront(s->q1));
            listQueueRemoveFront(s->q1);
        }
    }
    swap(s);
}


void printStack(struct QueueStack *s){
    assert(!listQueueIsEmpty(s->q1));
    while (!listQueueIsEmpty(s->q1)){
        printf("value: %d\n", listQueueFront(s->q1));     
        listQueueAddBack(s->q2, listQueueFront(s->q1));
        listQueueRemoveFront(s->q1);
    }
    swap(s);
}





int main(){
    struct QueueStack *s = QueueStackCreate();
    queueStackPush(s,(TYPE)3);
    queueStackPush(s, (TYPE)6);
    queueStackPush(s, (TYPE)9);
    queueStackPush(s, (TYPE)12);
    printStack(s);
    queueStackPop(s);
    printf("%d\n", queueStackTop(s));
    printStack(s);
    queueStackPush(s, (TYPE)3);
    queueStackPop(s);
    queueStackPop(s);
    printStack(s);
    queueStackFree(s);
    printf("end\n");

    return 0;
}
