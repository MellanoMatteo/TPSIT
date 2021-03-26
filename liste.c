#include <stdio.h>


//strutura auto-referenziale
typedef struct SLista
{
    int val;
    struct SLista* next;
}Lista;


void push(Lista* head, int valore)
{
    //aggiungi un elemento in fondo alla lista contenete il valore
    
    Lista* punt_app = head;
    
    while (punt_app->next != NULL)
    {
        punt_app = punt_app-> next;
    }
    
    punt_app ->next = (Lista*) malloc (sizeof(Lista));
    punt_app->next->val = valore; // punt_app->next è un puntatore a lista che punta ad un altra casella 
    punt_app->next->next = NULL;
    
}

int main()
{
 
    Lista* primo_elemento;
    primo_elemento = (Lista*) malloc (sizeof(Lista));
    primo_elemento->next = NULL;
    primo_elemento->val = 1;

    
    push(primo_elemento, 2);        //inserisco la seconda cella 
    push(primo_elemento, 3);        //isnerisco la terza cella 


    Lista puntatore_appoggio;
    puntatore_appoggio = primo_elemento;

    while(puntatore_appoggio != NULL)
    {
        printf("il valore e' : %d", puntatore_appoggio->val);
        puntatore_appoggio = puntatore_appoggio->next;
    }


    return 0;
}