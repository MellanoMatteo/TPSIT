#include <stdio.h>
#include <stdlib.h>

struct El {
    int valore;
    struct El* next;
};

void push(struct El** lista, struct El** l, int n)
{
    if (n >= 0) {
        if (*lista == NULL) {  // se la lista vale NULL, ovvero dobbiamo istanziare il primo nodo
            
            *lista = (struct El*) malloc (sizeof (struct El));  // alloco un'area di memoria grande struct El e lo metto all'interno di l
            (*l) = (*lista);                                    // in questo modo la variabile lista tiene l'head
        }
        else { // se siamo oltre il primo nodo
            
            (*l)->next = (struct El*) malloc (sizeof (struct El));  // alloco un'area di memoria apposita per il nodo
            (*l) = (*l)->next;
        }
        (*l)->valore = n;   // sia che siam o nel primo nodo o no, dobbiamo salvare il valore del numero al nodo
        (*l)->next = NULL;  // e il valore del puntatore a next lo si porta a NULL
    }
}

void stampaLista(struct El** l)
{
    printf("numeri inseriti: \n");

    while (*l != NULL) {
        printf("%d - %p \n",(*l)->valore, (*l)->next);
        *l = (*l)->next; //scorro nella lista di nodi
    }
}

int main() {
    int n;
    struct El* lista;
    struct El* l;
    lista = NULL; //inizializzo la lista a NULL  

    do {
        printf("Inserisci un naturale o -1 per terminare\n");
        scanf("%d",&n);  
        push(&lista, &l, n);

    } while (n >= 0);

    l = lista; // lista coincide con il primo nodo, quindi per poterlo scorrere di nuovo devo riinizializzare l all'head

    stampaLista(&l);
    
    printf("\n");
    return 0;
}