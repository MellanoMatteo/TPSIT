#include <stdio.h>
#include <stdlib.h>
#include "libraryStack.h"

#define MAX 1000


int main()
{
    StackNode* head;
    char stringa[MAX];
    int i = 0;

    printf("inserire il numero da invertire: ");
    scanf("%s", stringa);

    while(stringa[i] != '\0')
    {
        StackNode *elemento = (StackNode*) malloc(sizeof(StackNode));
        elemento->valore = stringa[i];
        push(&head, elemento);
        i++;
    }
    while(head != NULL)
    {
        printf("%c", pop(&head)->valore);
    }
}


