#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include <stdbool.h>
#include <time.h>

#define MAX 100        // definisco la lunghezza dei buffer
#define NSONG 10       //definisco il nuemro delle canzoni

typedef struct s_canzone{
    int numero;
    char titolo[MAX];
    char artista[MAX];
    bool riprodotta;
    struct s_canzone * next;
    
}canzone;

void leggiFile(canzone** playlist, int* numCanzoni, canzone** head, FILE* fp);

void songRand(canzone** playlist, int numSong, canzone** head);

int main ()
{   
    canzone* playlist;                      // array di tutte che contiene tutte le struct alle canzoni
    int numCanzoni = 0;
    canzone* head;
    FILE* fp = fopen("playlist.csv","r");

    leggiFile(&playlist, &numCanzoni, &head, fp);       
    songRand(&playlist, numCanzoni, &head);

    free(playlist);
    return 0;
}

void leggiFile(canzone** playlist, int* numCanzoni, canzone** head, FILE* fp)
{
    if(fp)
    {
        char buf[MAX];                          // variabile in cui salvo l'intera riga per poi analizzarla
        char* token;                            //variabile che mi serve per salvare i valori restituiti da strtok
        const char* ch = ",";                   // mi serve per effettuare la separazione della stringa 

        *playlist = (canzone*) malloc(sizeof(canzone));             //utilizzo la malloc per creare un array dinamico
        *head = *playlist;

        while(fgets(buf, MAX, fp))                                  //finchè ci sono righe da leggere (ovvero finchè non sono arrivato alla fine del file)
        {
            (*playlist)->numero = atoi(strtok(buf, ch));                            // lo leggo prendendolo come decimale (atoi converte da stringa a decimale)
            
            strcpy((*playlist)->titolo, strtok(NULL, ch));                         //leggo la 2a stringa del file, che corrisponde al titolo, e lo salvo nella parte apposita all'interno della struct

            strcpy((*playlist)->artista, strtok(NULL, ch));                        //copio il valore restituito dalla lettura del file con strtok all'interno della struct
            (*playlist)->artista[strlen((*playlist)->artista)-1] = '\0';           // elimino l'ultimo carattere, ovvero quello di messa a capo, dall'interno della stringa dell'artista

            //FUNZIONAMENTO STRTOK: passandogli null la funzione strtok capisce che lei deve andare avanti sulla stessa riga precedentemente passata

            (*playlist)->next = (canzone*) malloc(sizeof(canzone));                 //alloco un'altra area di memoria per la prossima canzone
            *playlist = (*playlist)->next;                                          //scorro la lista per poter inizializzare la prossima canzone
            (*numCanzoni) ++;                                                       //conteggio delle canzoni
        }
        fclose(fp);  
    }
    else
        printf("errore durante l'apertura del file \n\n\n");
}

void songRand(canzone** playlist, int numSong, canzone** head)
{
    srand(time(NULL));                                  //fuznione che mi permette di utilizzare la funzione rand per il calcolo di numeri casuali
    int volteRiprodotte = 3;                            //numero di volte che la playlist viene riprodotta nella sua interezza 
    int random;
    int cont = 0;
    int numera_canzoni = 0;

    *playlist = *head;
    while ((*playlist)->next != NULL)                      //porto tutte le canzoni a false per contrassegnare le canzoni già riprodotte
    {
        (*playlist)->riprodotta = false;
        *playlist = (*playlist)->next;
    }     
            
    *playlist = *head;
    for (int j = 0; j < volteRiprodotte; j++)           // per un numero a piacere di volte che si vuole riprodurre la playlist
    {
        printf("\nriproduzione n %d:\n", j+1);

        for (int i = 0; i < numSong; i++)               //per tutte le canzoni della playlist
        {
            do{
                *playlist = *head;                      //epr scorrere le canzoni e trovare quella sorteggiata ocorre partire dalla prima canzone inserita, che coinicde con l'head
                random = rand() % numSong;              //estraggo un numero a sorte
                cont = 0;                               //per scorrere le canzoni ho bisogno di un contatore che parta da zero
                while(cont < random)                    //finchè nn ho trovato la canzone sorteggiata
                {
                    *playlist = (*playlist)->next;          //scorro nella lista di canzoni e aggiorno il contatore
                    cont++;
                }
            }while((*playlist)->riprodotta);                //finchè riprodotta ha un valore falso
            
            (*playlist)->riprodotta = true;                 //metto la canzone come riprodotta
            numera_canzoni++;
            printf("%d__titolo: %s, artista: %s\n",numera_canzoni, (*playlist)->titolo, (*playlist)->artista); // printo gli estremi della canzone 
        }
        *playlist = *head;                                  // per eseguire correttamente il while occorre riinizializzare la playliast alla prima canzone

        while ((*playlist)->next != NULL)                   //riporto tutte le canzoni a false per contrassegnare le canzoni già riprodotte, e per una numerazione corretta imposto numera_canzoni a 0
        {
            (*playlist)->riprodotta = false;
            *playlist = (*playlist)->next;
            numera_canzoni = 0;
        }
    }
}