typedef struct SStackNode
{
    char valore;
    struct SStackNode* next;
}StackNode;

int is_empty(StackNode* head)
{
    if(head == NULL)
        return 1;
    else 
        return 0;
}

void push(StackNode** head, StackNode* elemento)
{
    if(is_empty(*head))
    {
        *head = elemento;
        elemento->next = NULL;
    }
    else
    {
        elemento->next = *head;
        *head = elemento;
    }
}

StackNode* pop (StackNode** head)
{
    StackNode* ret = *head;
    if(is_empty(*head))
        return NULL;
    else
        *head = ret->next;
    return ret;
}
