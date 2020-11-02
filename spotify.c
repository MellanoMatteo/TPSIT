//obiettivo:riprodurre la funzione di spotify che fa partire le canzoni in modo casuale

/*
1. lettura csv (leggere tutto il valueStringaenuto del file e riconoscere la virgola: 0,titolo,autore)
    1.1 caricamento(caricare i file letti in memoria) ovvero in array di struttura
2. random ordering (sorteggio delle canzoni in modo tale che non si ripetino )
*/
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
}canzone;

int  letturaFile(canzone *playlist);

void songRand(canzone *playlist, int numSong);

int main ()
{   
    canzone playlist[NSONG];                // array di tutte che contiene tutte le struct alle canzoni
    int numCanzoni;
    
    numCanzoni = letturaFile(playlist);

    songRand(playlist, numCanzoni);

    /* DEBUG
    printf("\n\n"); 
    for (int  i = 0; i < NSONG; i++)        
        printf("%d-%s-%s\n", playlist[i].numero, playlist[i].artista, playlist[i].titolo); */

    return 0;
}

int letturaFile(canzone *playlist)
{
    char buf[MAX];                          // variabile in cui salvo l'intera riga per poi analizzarla
    char* token;                            //variabile che mi serve per salvare i valori restituiti da strtok
    const char *ch = ",";                   // mi serve per effettuare la separazione della stringa 
    int nCanzone = 0;                       // in fase di inizializzazione, mi serve per controllare di scorrere tutte le canzoni 

    FILE *fp=fopen("playlist.csv","r");

    if(fp != NULL)
    {
        while(fgets(buf, MAX, fp))                    //finchè ci sono righe da leggere (ovvero finchè non sono arrivato alla fine del file)
        {
                        //prendo una riga del file 

            token = strtok(buf, ch);        //strtok ritorna la prima occorrenza del secondo parametro all'interno del primo

            playlist[atoi(token)].numero = atoi(token);                                 // lo leggo prendendolo come decimale (atoi converte da stringa a decimale)
            printf("numero: %d \t\t",playlist[atoi(token)].numero);                     //debug
            nCanzone = atoi(token);                                                     //assegno alla variabile nCanzone il valore del numero corrente della canzone
            
            strcpy(playlist[nCanzone].titolo, strtok(NULL, ch));                        //leggo la 2a stringa del file, che corrisponde al titolo, e lo salvo nella parte apposita all'interno della struct
            printf("titolo: %s \t\t",playlist[nCanzone].titolo);
            
            strcpy(playlist[nCanzone].artista, strtok(NULL, ch));                       //copio il valore restituito dalla lettura del file con strtok all'interno della struct
            playlist[nCanzone].artista[strlen(playlist[nCanzone].artista)-1] = '\0';    // elimino l'ultimo carattere, ovvero quello di messa a capo, dall'interno della stringa dell'artista
            printf("artista: %s \t\t\n",playlist[nCanzone].artista);

            //FUNZIONAMENTO STRTOK: passandogli null la funzione strtok capisce che lei deve andare avanti sulla stessa riga precedentemente passata
        }
        fclose(fp); 
        return nCanzone; // ritorno il numero di canzoni totale 
    }
    else
        printf("errore durante l'apertura del file \n\n\n");
}

void songRand(canzone *playlist, int numSong)
{
    srand(time(NULL));                                  //fuznione che mi permette di utilizzare la funzione rand per il calcolo di numeri casuali
    int volteRiprodotte = 3;                            //numero di volte che la playlist viene riprodotta nella sua interezza 
    int random = 0;
    /*
    for(per n volte)
    {
        for(per tutte le canzoni )
        {
            do
            {
                tira a sorte una canzone 
            }while(se la canzone è già stata riprodotta)
            riproducila 
        }
    }
    */
    printf("\n\nfunzione stampa:\n\n\n");

    for (int i = 0; i < numSong; i++)                   //porto tutte le canzoni a false per contrassegnare le canzoni già riprodotte
            playlist[i].riprodotta = false;

    for (int j = 0; j < volteRiprodotte; j++)           // per un numero a piacere di volte che si vuole riprodurre la playlist
    {
        printf("\n\nriproduzione n %d:\n\n\n", j);
        for (int i = 0; i < numSong; i++)               //per tutte le canzoni della playlist
        {
            do{
                random = rand() % numSong;              //tiro a caso un numero tra 0 e rand

            }while(playlist[random].riprodotta);              //controllo se la canzone sorteggiata è già stata riprodotta

            playlist[random].riprodotta = true;              //porto riprodotta a true per contrassegnare la sua avvenuta riproduzione 
            
            printf("titolo: %s, artista: %s\n", playlist[random].titolo, playlist[random].artista); // printo gli estremi della canzone 
        }
        for (int i = 0; i < numSong; i++)               //riporto tutte le canzoni ad un valore false per poter riutilizzare la variabile booleana
            playlist[i].riprodotta = false;
    }
}