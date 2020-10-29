//obiettivo:riprodurre la funzione di spotify che fa partire le canzoni in modo casuale

/*
1. lettura csv (leggere tutto il valueStringaenuto del file e riconoscere la virgola: 0,titolo,autore)
    1.1 caricamento(caricare i file letti in memoria) ovvero in array di struttura
2. random ordering (sorteggio delle canzoni in modo tale che non si ripetino )
*/
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define MAX 100        // definisco la lunghezza dei buffer
#define NSONG 10       //definisco il nuemro delle canzoni

typedef struct s_canzone{
    int numero;
    char titolo[MAX];
    char artista[MAX];
}canzone;

void letturaFile(canzone *playlist);

int main ()
{   
    canzone playlist[NSONG];                // array di tutte che contiene tutte le struct alle canzoni
    
    letturaFile(playlist);

    printf("\n\n"); 
    for (int  i = 0; i < NSONG; i++)        //stampa il contenuto delle struct per vedere cosa mi mette
        printf("%d-%s-%s\n", playlist[i].numero, playlist[i].artista, playlist[i].titolo);

    return 0;
}

void letturaFile(canzone *playlist)
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

            //FUNZIONAMENTO STRTOK: passanfogli null la funzione strtok capisce che lei deve andare avanti sulla stessa riga precedentemente passata
        }

        fclose(fp); 
    }
    else
        printf("errore durante l'apertura del file \n\n\n");
}