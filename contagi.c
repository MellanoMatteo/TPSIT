/*
Calcolare:
1) top 3 delle regioni per numero di ricoveri in terapia intensiva
2) totale dei ricoverati in terapia intensiva
3) top 3 delle regioni con meno casi totali positivi.
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX 1000

typedef struct SRegione
{
    char *data;
    char *stato;
    int cod_regione;
    char *denominazione_regione;
    float latitudine;
    float longitudine;
    int ric_sintomi;
    int ter_int;
    int ospedalizzati;
    int is_domicil;
    int positivi;
    int variazione_pos;
    int nuovi_pos;
    int dimessi;
    int morti;
    int casi_sospetti;
    int casi_da_screening;
    int casi_totali;
    int tamponi;
    int casi_testati;
}Regione;

int contaRighe(FILE* fp) // conta le righe del file da leggere
{
    int conta_righe = 0;
    char buffer[MAX];
    while (fgets(buffer, MAX, fp))

        conta_righe++;         // conto le righe del file
        
    return --conta_righe; //escludo la prima riga che fa da legenda al file
}

void leggiFile(FILE* fp, Regione* italia) // inserisce tutti i vari dati nella struct
{
    int i = 0;
    char buff[MAX];
    const char* delim = ",";

    fgets(buff, MAX, fp);
   
    while (fgets(buff, MAX, fp))
    {
        (italia+i)->data = strdup(strtok(buff, delim));

        (italia+i)->stato = strdup(strtok(NULL, delim));

        (italia+i)->cod_regione = atoi(strtok(NULL, delim));

        (italia+i)->denominazione_regione = strdup(strtok(NULL, delim));

        (italia+i)->latitudine = atof(strtok(NULL, delim));

        (italia+i)->longitudine = atof(strtok(NULL, delim));

        (italia+i)->ric_sintomi = atoi(strtok(NULL, delim));

        (italia+i)->ter_int = atoi(strtok(NULL, delim));

        (italia+i)->ospedalizzati = atoi(strtok(NULL, delim));

        (italia+i)->is_domicil = atoi(strtok(NULL, delim));
        
        (italia+i)->positivi = atoi(strtok(NULL, delim));

        (italia+i)->variazione_pos = atoi(strtok(NULL, delim));

        (italia+i)->nuovi_pos = atoi(strtok(NULL, delim));

        (italia+i)->dimessi = atoi(strtok(NULL, delim));

        (italia+i)->morti = atoi(strtok(NULL, delim));

        (italia+i)->casi_sospetti = atoi(strtok(NULL, delim));

        (italia+i)->casi_da_screening = atoi(strtok(NULL, delim));

        (italia+i)->casi_totali = atoi(strtok(NULL, delim));

        (italia+i)->tamponi = atoi(strtok(NULL, delim));

        (italia+i)->casi_testati = atoi(strtok(NULL, delim));

        i++;
    }
}

void top3MaxNumRecoveri (Regione* italia, int regioni) // cerco le prime 3 regioni per numero di terapie intensive
/*
    scorro per 3 volte l'array, e ogni volta cerco il numero maggiore che compare tra gli elementi del campo apposito
    ogni volta che ne trovo uno, salvo l'indice e dopo lo salto durante il controllo
*/
{
    int max_rec1 = 0, max_rec2 = 0, max_rec3 = 0;
    int ind1 = 0, ind2 = 0, ind3 = 0;

    for (int i = 0; i < regioni; i++)
        if(max_rec1 < (italia+i)->ter_int)
        {
            ind1 = i;
            max_rec1 = (italia+i)->ter_int;
        }
            
    for(int i = 0; i < regioni; i++)
        if(i != ind1)
            if(max_rec2 < (italia+i)->ter_int)
            {
                ind2 = i;
                max_rec2 = (italia+i)->ter_int;
            }

    for(int i = 0; i < regioni; i++)
        if(i != ind1 && i != ind2)
            if(max_rec3 < (italia+i)->ter_int)
            {
                ind3 = i;
                max_rec3 = (italia+i)->ter_int;
            }  

    printf("top 3 regioni maggior numero persone in terapia intensiva:\n 1.%s \n 2.%s\n 3.%s\n", (italia+ind1)->denominazione_regione, (italia+ind2)->denominazione_regione, (italia+ind3)->denominazione_regione);      
}

int totTerapiaIntensiva(Regione* italia, int regioni) // per tutte le regioni sommo il valore della terapia intensiva ad una variabile di appoggio che sucessivamente do in output
{
    int terInt = 0;
    for (int i = 0; i < regioni; i++)
        terInt += (italia+i)->ter_int;
    return terInt;
}

void top3MinNumPositivi(Regione* italia, int regioni) // cerco le tre regioni con il numero minore di positivi
/*
    scorro per 3 volte l'array, e ogni volta cerco il numero minore che compare tra gli elementi del campo apposito
    ogni volta che ne trovo uno, salvo l'indice e dopo lo salto durante il controllo
*/
{
    int min_pos1 = 10000, min_pos2 = 10000, min_pos3 = 10000;
    int ind1 = 0, ind2 = 0, ind3 = 0;

    for (int i = 0; i < regioni; i++)
        if(min_pos1 > (italia+i)->positivi)
        {
            ind1 = i;
            min_pos1 = (italia+i)->positivi;
        }
            
    for(int i = 0; i < regioni; i++)
        if(i != ind1)
            if(min_pos2 > (italia+i)->positivi)
            {
                ind2 = i;
                min_pos2 = (italia+i)->positivi;
            }

    for(int i = 0; i < regioni; i++)
        if(i != ind1 && i != ind2 )
            if(min_pos3 > (italia+i)->positivi)
            {
                ind3 = i;
                min_pos3 = (italia+i)->positivi;
            }
    printf("top 3 regioni minor numero contagi:\n 1.%s \n 2.%s\n 3.%s\n", (italia+ind1)->denominazione_regione, (italia+ind2)->denominazione_regione, (italia+ind3)->denominazione_regione);
}

int main()
{
    FILE* fp = fopen("contagi.csv", "r");
    FILE* fp2 = fopen("contagi.csv", "r");

    Regione* italia;
  
    if (!fp && !fp2) //controllo la validità di entrambi i puntatori a file
    {
        printf("errore durante l'apertura del file\n");
        return -1;
    }
    
    int nRegioni = contaRighe(fp);      //conto le righe del file 

    italia = (Regione*) malloc(nRegioni * sizeof(Regione)); //allocazione dinamica della memoria dell'array che salverà tutti i dati

    leggiFile(fp2, italia);     //salvo i dati nel database

    fclose(fp);         // chiudo i file precedentemente aperti per la lettura
    fclose(fp2);

    printf("\n");
    
    top3MaxNumRecoveri(italia, nRegioni);   //calcolo e stampo il numero maggiore di persone in terapia intensiva

    printf("totale persone ricoverate in terapia intensiva: %d\n", totTerapiaIntensiva(italia, nRegioni)); // stampo il valore ritornato dalla funzione che calcola il numero di persone totali in terapia intensiva

    top3MinNumPositivi(italia, nRegioni); //calcolo e stampo tutti i positivi in italia

    free(italia);       //libero l'area di memoria occupata dal database
    
    return 1;
}