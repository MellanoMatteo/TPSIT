#include <stdio.h>

typedef struct Snode
{
    int valore;
    struct Snode* next;
}Node;

int lunghezzaListaRicorsiva(Node* head)
{
    if(head == NULL)
    {
        return 0;
    }
    else
    {
        return 1 + lunghezzaListaRicorsiva(head->next);
    }
}

int lunghezzaListaIterattiva(Node* head)
{
    int cont = 0;
    while(head != NULL)
    {
        cont++;
        head= head->next;
    }
    return cont;
}

void deallocaRicorsivamente(Node* head)
{
    if(head != NULL)
    {
        dealloca(head->next);
        free(head); // vengono eseguite tutte le free in cascata quando arriva all'ultima cella
    }
}

void dellocaIterattivamente(Node* head)
{
    Node* appoggio = NULL;
    while(head != NULL)
    {
        appoggio = head->next;
        free(head);
        head = appoggio;
    }
}