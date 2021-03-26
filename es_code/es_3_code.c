/*Implementare le pile e i metodi pop() e push() utilizzando una coda con i suoi metodi
enqueue() and dequeue().*/

#include <stdio.h>
#include <stdlib.h>
#include "libraryTail.h"

// la pop toglie l'ultima casella, ovvero nel caso della coda l'head
TailNode* pop(TailNode** head, TailNode** tail, int contAdd)
{
    TailNode* copyHead = *head;
    while(--contAdd != 0)
    {
        copyHead = copyHead->next;
        printf("%d\n", contAdd);
        //contAdd--;
    }
    TailNode* ret = dequeue(&copyHead, tail);
    
    *tail = (*tail)->next;
    return ret;
}

//la push aggiunge una casella alla fine della coda, quindi sposta l'head di uno
void push(TailNode** head, TailNode** tail, TailNode* element, int* contAdd)
{
    enqueue(head, tail, element);
    (*contAdd)++;
}

int main()
{
    int contAdd = 0;
    TailNode* head= (TailNode*) malloc (sizeof(TailNode));      
    TailNode* tail= (TailNode*) malloc (sizeof(TailNode));

    tail = NULL;
    head = NULL;

    TailNode* el1 = (TailNode*) malloc (sizeof(TailNode));
    TailNode* el2 = (TailNode*) malloc (sizeof(TailNode));
    TailNode* el3 = (TailNode*) malloc (sizeof(TailNode));

    el1->valore = 4;
    el2->valore = 5;
    el3->valore = 6;
    
    push(&head, &tail, el1, &contAdd);  
    push(&head, &tail, el2, &contAdd);
    push(&head, &tail, el3, &contAdd);

    int cont = 1;
    while(tail != NULL)
    {
        struct Snode* nodoOut = pop(&head, &tail, contAdd);
        printf("n: %d valore: %d\n", cont++, nodoOut->valore);
        free(nodoOut);
    }
}