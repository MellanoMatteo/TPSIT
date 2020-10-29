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

//valori che mi servono per il caricamento nello switch
#define CONTSONG 0
#define TITLE 1
#define AUTHOR 2

typedef struct s_canzone{
    int numero;
    char titolo[MAX];
    char artista[MAX];
}canzone;

void lettura&Caricamento(canzone *playlist);

int main ()
{   
    canzone playlist[NSONG];                // array di tutte che contiene tutte le struct alle canzoni
    
    letturaeCaricamento(playlist);

    printf("\n\n"); 
    for (int  i = 0; i < NSONG; i++)        //stampa il contenuto delle struct per vedere cosa mi mette
        printf("%d-%s-%s\n", playlist[i].numero, playlist[i].artista, playlist[i].titolo);

    return 0;
}

void letturaeCaricamento(canzone *playlist)
{
    char buf[MAX];                          // variabile in cui salvo l'intera riga per poi analizzarla
    char* token;                            //variabile che mi serve per salvare i valori restituiti da strtok
    const char *ch = ",";                   // mi serve per effettuare la separazione della stringa 
    int valueStringa = 0;                   // mi serve per sapere se si tratta del numero della canzone, del titolo o dell'autore
    int nCanzone = 0;                       // in fase di inizializzazione, mi serve per controllare di scorrere tutte le canzoni 

    FILE *fp=fopen("playlist.csv","r");

    if(fp != NULL)
    {
        while(!feof(fp))                    //per tutta la lunghezza del file(finche il puntatore non è arrivato alla fine del file)
        {
            nCanzone = 0;
            valueStringa = 0;

            //printf("cambio riga\n");

            fgets(buf, MAX, fp);            //prendo una riga del file 

            //printf("buf: %s\n", buf);

            token = strtok(buf, ch);        //strtok ritorna la priam occorrenza del secondo parametro all'interno del primo
            
            while (token != NULL)           // per tutta la lunghezza del file 
            {
                switch (valueStringa)       // controllo cosa sto leggendo della canzone (se numero, titolo o artista)
                {
                case CONTSONG:              // nel caso in cui io stia leggendo il numero 
                    printf("numero: ");
                    printf("%s\n", token );
                    playlist[atoi(token)].numero = atoi(token);             // lo leggo prendendolo come decimale (atoi converte da stringa a decimale)
                    nCanzone = atoi(token);                                 // mi salvo il numero della canzone per usarlo anche nei salvataggi successivi
                    break;
                case TITLE:                 // nel caso in cui io stia leggendo il titolo della canzone 
                    printf("titolo: ");
                    printf("%s\n", token );
                    strcpy(playlist[nCanzone].titolo, token);               // lo salvo all'interno dell'apposita sezione della struct
                    break;
                case AUTHOR:                // nel caso in cui io stia leggendo l'autore della canzone 
                    printf("autore: ");
                    printf("%s\n", token );
                    strcpy(playlist[nCanzone].artista, token);              // mi salvo il nome dell'autore 
                    playlist[nCanzone].artista[strlen(token)-1] = '\0';     // elimino l'ultimo carattere (quello di a capo ) 
                    break;
                default:
                printf("errore\n");
                    break;
                }
                valueStringa++;             // tutte le volte che mi salvo un valore, passo a quello successivo nella stringa, quindi incremento la variabile dello switch
                //printf("%s\n", token );
                token = strtok(NULL, ch);   //passo alla sezione successiva del file 
                //passanfogli null la funzione strtok capisce che lei deve andare avanti sulla stessa riga precedentemente passata
            }
        } 
        fclose(fp); 
    }
    else
    {
        printf("errore durante l'apertura del file \n\n\n");
    }
}