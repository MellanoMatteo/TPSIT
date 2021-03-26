#include <stdio.h>
 
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define NUMCARTENERE 26
#define NUMSEMI 4
#define NUMVALORI 13
#define NUMTOTCARTE 52

//la carta contiene un seme ed un valore che è un numero
typedef struct SCarta{
    int numero;
    char seme;
    struct SCarta* next;
    bool estratta;
        
}Carta;

void enqueue (Carta** head, Carta** tail, Carta* element) {
    
    if(*head == NULL) {
        *head = element;
    }
    else {
        (*tail)->next = element;
    }

    *tail = element;
    element->next = NULL;
}

Carta *dequeue(Carta** head, Carta** tail) {

    Carta *ret = *head;

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

void stampaCoda(Carta** head, Carta** tail)
{
    int cont = 1;
    while(*tail != NULL)
    {
        Carta* nodoOut = dequeue(head, tail);
        printf("n: %d seme: %c, numero: %d\n", cont++, nodoOut->seme, nodoOut->numero);
        free(nodoOut);
    }
        
}

int main()
{
    srand(time(NULL));

    bool carte[NUMSEMI][NUMTOTCARTE];

    //estremi della coda
    Carta* head = (Carta*) malloc (sizeof(Carta));
    Carta* tail = (Carta*) malloc (sizeof(Carta));

    head = NULL;
    tail = NULL;

    //seme rappresenta il valore del seme della carta, che viene assegnato attraverso lo switch nel primo for
    char seme;
    int randSeme;
    int randValore;

    for (int i = 0; i < NUMSEMI; i++)
    {
        for (int j = 0; j < NUMVALORI; j++)
        {
            carte[i][j] = false;
        }
    }

    int contCarteImmesse = 0;

    while(contCarteImmesse < NUMTOTCARTE)
    {
        randSeme = rand()%4;
        randValore = rand()%14;
        switch(randSeme)    //assegno il seme in base al valore casuale
        {
            case 0:
            seme = 'C';
            break;
            case 1:
            seme = 'P';
            break;
            case 2:
            seme = 'D';
            break;
            case 3:
            seme = 'F';
            break;
            default:
            break;

        }

        if(carte[randSeme][randValore] == false)
        {
            Carta* nuovaCarta = (Carta*) malloc (sizeof(Carta)); //creo una nuova carta
            //assegno dei valori alla nuova carta e la aggiungo al mazzo
            nuovaCarta->numero = randValore;
            nuovaCarta->seme = seme;
            carte[randSeme][randValore] = true; 
            contCarteImmesse++;
            enqueue(&head, &tail, nuovaCarta);
            //printf("%d\n", contCarteImmesse);
        }

    }

    //carteRimosse tiene il conto delle carte estratte
    // se è uguale al numero di carte nere vuol dire che sono rimaste solo più quelle rosse
    int carteRimosse = 0;

    //finche non ho rimosso tutte le carte nere
    while(carteRimosse < NUMCARTENERE )
    {
        //estraggo una carta dal mazzo

        Carta* cartaEstratta = dequeue(&head, &tail);
        //se la carta è rossa la rimetto nel mazzo, altrimenti la tolgo e aggiorno il contatore
        if(cartaEstratta->seme == 'C' || cartaEstratta->seme == 'D')
        {
            // se la carta è rossa la rimetto nel mazzo
            enqueue(&head, &tail, cartaEstratta);
            //printf("%c\n", cartaEstratta->seme);
        }
        else
        {
            carteRimosse++;
        }
        //printf("controsse: %d", carteRimosse);
    }

    stampaCoda(&head, &tail);
}