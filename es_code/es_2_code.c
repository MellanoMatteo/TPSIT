/*Scrivere una funzione che inverta una coda, ovvero produca una coda invertendo l’ordine
degli elementi della coda di partenza. Suggerimento: utilizzare una pila.*/

#include <stdio.h>
#include <stdlib.h>
#include "libraryTail.h"
#include "libraryStack.h"

void reverseTail(TailNode** tail, TailNode** headT)
{
    StackNode* headS = (StackNode*) malloc (sizeof(StackNode));
    headS = NULL;

    while(*tail != NULL)
    {
        StackNode* element = (StackNode*) malloc (sizeof(StackNode));
        element->valore = dequeue(headT, tail)->valore;
        push(&headS, element);
    }

    while(headS != NULL)
    {
        TailNode* element = (TailNode*) malloc (sizeof(TailNode));
        element->valore = pop(&headS)-> valore;
        enqueue(headT, tail, element);

    }
}

int main ()
{
    TailNode* tail = (TailNode*) malloc (sizeof(TailNode));
    TailNode* headT = (TailNode*) malloc (sizeof(TailNode));

    tail = NULL;
    headT = NULL;
    
    int input = 0;
    char inputTail = 'y';

    while(inputTail == 'y')
    {
        TailNode* element = (TailNode*) malloc (sizeof(TailNode));
        printf("inserire il valore: ");
        scanf("%d", &input);

        element->valore = input;
        enqueue(&headT, &tail , element);

        printf("il valore e' stato inserito. \n si vuole procedere con altri inserimenti?(y = si, n = no)");
        fflush(stdin);
        inputTail = getchar();
    }

    reverseTail(&tail, &headT);

    stampaCoda(&headT, &tail);

    return 0;

}
