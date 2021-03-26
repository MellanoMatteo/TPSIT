/*
Nel file instagram.csv trovate alcuni dati esportati dal vostro account Instagram. 
Ogni riga del file corrisponde ad un post pubblicato nel 2020 e su ogni riga trovate
 in ordine: 
mese, giorno del mese, identificativo del post, numero di like.

Scrivere un programma in C, che faccia uso della allocazione dinamica e 
della aritmetica dei puntatori (requisiti obbligatori): 
il programma deve richiedere all'utente il nome di un mese e poi deve 
fornire in output il numero di post di quel mese ed il numero totale di like ricevuto
durante quel mese.

NOTA: non è possibile accedere agli elementi degli array utilizzando le parentesi [ ].

CONSEGNARE SOLTANTO IL FILE SORGENTE .C ADEGUATAMENTE COMMENTATO. IL FILE .C 
DEVE AVERE NOME: COGNOME_NOME.c

*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX 100

typedef struct SAccount
{
    char* mese; 
    int giorno;
    char* IDPost;
    int like;
}Account;


int contarighe(FILE* fp)
{
    char *buffer;
    buffer = (char*) malloc(sizeof(char) * MAX);
    int cont = 0;
    while(fgets(buffer, MAX, fp))
        cont++;
    free(buffer);
    return cont;
}

int main()
{
    FILE *fp = fopen("instagram.csv", "r");

    int righe = 0;
    int k = 0;
    const char* ch = ",";

    char* inMese;
    int postMese = 0;
    int totLike =0;
    char *buf;

    Account *mioAccount;

    if (!fp)
    {
        printf("errore durante l'apertura del file");
        return -1;
    }
    
    righe = contarighe(fp);

    fclose(fp);

    mioAccount = (Account*) malloc(sizeof(Account) * righe);

    buf = (char*) malloc(sizeof(char) * MAX);

    FILE *fp2 = fopen("instagram.csv", "r");
    
    fgets(buf, MAX, fp2);

    while(fgets(buf, MAX, fp2))
    {
        (mioAccount+k)->mese = strdup(strtok(buf, ch));

        (mioAccount+k)->giorno = atoi(strtok(NULL, ch));

        (mioAccount+k)->IDPost = strdup(strtok(NULL, ch));

        (mioAccount+k)->like = atoi(strtok(NULL, ch));
        k++;
    }
    free(buf);

    inMese = (char*) malloc(sizeof(char) * MAX);

    fflush(stdin);
    
    printf("inserire il mese: ");
    fgets(inMese, MAX, stdin);

    inMese[strlen(inMese)-1] = '\0';

    for (int i = 0; i < righe; i++)
    {
        if(strcmp((mioAccount+i)->mese , inMese) == 0)
        {
            postMese++;
            totLike += (mioAccount+i)->like;
        }
    }
    printf("numero di post: %d\n numero totale di like: %d\n", postMese, totLike);

    fclose(fp2);

    free(mioAccount);
    
    return 1;
}