#include <stdio.h>
#include <stdlib.h>
#include "libraryTail.h"

int main()
{
    struct Snode* head = (struct Snode*) malloc (sizeof(struct Snode));
    struct Snode* tail = (struct Snode*) malloc (sizeof(struct Snode));
    
    
    char sceltaIn = 'y';
    char sceltaOut = 'n';
    int input = 0;

    head = NULL;
    tail = NULL;
    
    while(sceltaIn == 'y')
    {
        struct Snode* element = (struct Snode*) malloc (sizeof(struct Snode));
        printf("inserire il valore: ");
        scanf("%d", &input);

        element->valore = input;
        enqueue(&head, &tail , element);

        printf("il valore e' stato inserito. \n si vuole procedere con altri inserimenti?(y = si, n = no)");
        fflush(stdin);
        sceltaIn = getchar();
    }

    printf("vuoi stampare la coda appena inserita?");
    fflush(stdin);
    sceltaOut = getchar();

    if(sceltaOut == 'y'){
        stampaCoda(&head, &tail);
    }   
}