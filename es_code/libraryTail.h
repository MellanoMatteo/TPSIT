

typedef struct Snode{
    struct Snode *next;
    int valore;
} TailNode;

void enqueue (struct Snode** head, struct Snode** tail, struct Snode* element) {
    
    if(*head == NULL) {
        *head = element;
    }
    else {
        (*tail)->next = element;
    }

    *tail = element;
    element->next = NULL;
}

struct Snode *dequeue(struct Snode** head, struct Snode** tail) {

    struct Snode *ret = *head;

    if (*head == NULL) {
        return NULL;
    }
    else {
        *head = ret->next;
    }

    if (*head == NULL) {
        *tail = NULL;
    }
    return ret;
}

void stampaCoda(struct Snode** head, struct Snode** tail)
{
    int cont = 1;
    while(*tail != NULL)
    {
        struct Snode* nodoOut = dequeue(head, tail);
        printf("n: %d valore: %d\n", cont++, nodoOut->valore);
        free(nodoOut);
    }
        
}
