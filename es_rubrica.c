#include <stdio.h>
#include <string.h>

#define MAX_NUM_CONTATTI 1024

typedef struct SContatto
{
    int id;
    char nome[64];
    char numero[16];
} Contatto;

typedef struct SRubrica
{
    int num_inseriti;
    Contatto db [MAX_NUM_CONTATTI];
}Rubrica;


int inserisci (Rubrica *r, char *nome, char* numero)
{
    Contatto *p;
    if(r->num_inseriti == MAX_NUM_CONTATTI)
    {
        printf("memoria piena \n");
        return -1;
    }
    p = &r->db[r->num_inseriti];
    strcpy(p->nome, nome);
    strcpy(p->numero, numero);
    p->id = r->num_inseriti;
    r->num_inseriti++;
    return 0;
}

char *trova_numero_da_nome(Rubrica *r, char* nome)
{
    int i;
    Contatto *p;
    for (int i = 0; i < MAX_NUM_CONTATTI; i++)
    {   
        if (i == r->num_inseriti)
            break;
        p = &r->db[i];

        if (strcmp(p->nome, nome) == 0) 
            return p->numero;
    }
    return NULL;
}

void stampa_rubrica(Rubrica *r)
{
    int i;
    Contatto *p;
    printf("\nstampa rubrica: %d contatti \n", r->num_inseriti);

    for (int i = 0; i < MAX_NUM_CONTATTI; i++)
    {        
        if (i == r->num_inseriti)
            break;
    p = &r->db[i];
    printf("%s, %s\n", p->nome, p->numero);
    }
}

int main()
{
    Rubrica rubrica;
    char scelta = 0;
    int num;
    char nomeDaTrovare[64];
    do
    {
        fflush(stdin);
        printf("\ninserire la scelta:\n 1 per inserire dei nuovi contatti\n 2.stampare la scelta\n 3.cercare un numero in base al nome\n ");
        scelta = getchar();

        switch (scelta)
        {
        case '1':                                               //inserire nuovi contatti
            printf("quante persone si vogliono inserire?");
            scanf("%d", &num);
            for (int i = 0; i < num; i++)
            {
                char nome[64];
                char numero[16];
                fflush(stdin);

                printf("\ninserire il nome: ");
                fgets(nome, 64, stdin);
                nome[strlen(nome)-1] = '\0';

                printf("\ninserire il numero: ");
                fgets(numero, 16, stdin);
                numero[strlen(numero)-1] = '\0';

                inserisci(&rubrica, nome, numero);
            }
            printf("vuoi effettuare una altra azione sulla rubrica? (s = si, n = no)\n");
            scelta = getchar();
            if(scelta = 's')
                scelta = 0;
            break;

        case '2':                                       //stampa dei contatti
            stampa_rubrica(&rubrica);
            printf("vuoi effettuare una altra azione sulla rubrica? (s = si, n = no)\n");
            scelta = getchar();
            if(scelta = 's')
                scelta = 0;
            break;
            
        case '3':                                       //cercare un numero in base al nome
            fflush(stdin);
            printf("inserire il nome di cui si vuole sapere il numero: ");
            fgets(nomeDaTrovare, 64, stdin);

            nomeDaTrovare[strlen(nomeDaTrovare)-1] = '\0';            
            
            if(trova_numero_da_nome(&rubrica, nomeDaTrovare) == NULL)
                printf("non e' stato trovato alcun numero associato a quel nome\n");
            else
                printf("il numero della persona indicata e': %s\n", trova_numero_da_nome(&rubrica, nomeDaTrovare));

            printf("vuoi effettuare una altra azione sulla rubrica? (s = si, n = no)\n");
            scelta = getchar();
            if(scelta = 's')
                scelta = 0;
            break;
        
        default:
            printf("\ninserimento non valido, riinserire la scelta\n");
            scelta = 0;
            break;
        } 
    } while (scelta == 0);


    return 0;
}