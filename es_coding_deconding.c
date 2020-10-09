#include<stdio.h>

#define MAX 50

void code(int lenght, int cont, char *stringa);
void decode(int lenght, int cont, char *stringa);
void inserireStringa(int lenght,  char *stringa);

int main()
{
    char stringa[MAX];
    int cont = 1;
    int lenght = 0;
    int scelta;

    printf("vuoi codificare(1) o decodificare(2)?\n");//chiedo cosa si vuole fare
    scanf("%d", &scelta);

    switch (scelta)
    {
    case 1:
        inserireStringa(lenght, stringa);
        code(lenght, cont, stringa);
        break;
    case 2:
        inserireStringa(lenght, stringa);
        decode(lenght, cont, stringa);
        break;
    default:
    printf("hai sbagliato a fare la scelta\n");
        break;
    }
    return 0;
}

void inserireStringa(int lenght, char* stringa)//inserisco la stringa 
{
    printf("inserire la stringa:\n");
    scanf("%s", stringa);
    for(int i = 0; stringa[i] != '\0'; i++) //conto la lunghezza della stringa 
        lenght = i;
}

void code(int lenght, int cont, char* stringa)
{
    for(int i = 0; i < lenght; i++)         //per tutta la lunghezza della stringa 
    {
        printf("ciao");
        while(stringa[i] == stringa[i+1] && i+1 <= lenght) //se il carattere è uguale a quello dopo e la strnga non è finita
        {
            printf("cia9");
            cont++;
            i++;
        }
        cont != 1 ? printf("%d%c", cont,  stringa[i]) : printf("%c", stringa[i]);
        //se c'è solo un carattere lo stampo altrimenti stampo il numero e il carattere

        cont = 1;
    }
}

void decode(int lenght, int cont, char* stringa) //decodifica
{
    for(int i = 0; i < lenght; i++)
    {

        if(stringa[i] =='0' ||
           stringa[i] =='1' ||
           stringa[i] =='2' ||
           stringa[i] =='3' ||
           stringa[i] =='4' ||
           stringa[i] =='5' ||
           stringa[i] =='6' ||
           stringa[i] =='7' ||
           stringa[i] =='8' ||
           stringa[i] =='9')
           {
               

           }
    }
}