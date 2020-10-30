//

#include<stdio.h>

#define MAX 100

int main()
{
    int a = 0, t = 0, c = 0, g = 0;
    FILE *fp;
    char buf[MAX];
    fp = fopen("rna.txt", "r"); // apro il file 

    if(fp)                  // se il file e' stato aperto correttamente
    {
        while(fgets(buf, MAX, fp))  //finchè ci sono righe da leggere
        {
            int i = 0;

            while(buf[i] != '\0')   //finchè non termino la riga 
            {
                switch (buf[i])     //per ogni lettera trovata incremento il contatore apposito
                {
                case 'a':
                    a++;
                    break;
                case 't':
                    t++;
                    break;
                case 'c':
                    c++;
                    break;
                case 'g':
                    g++;
                    break;
                default:
                    break;
                }
                i++;        //incremento per scorrere la riga 
            }
        }
    }
    else
    {
        printf("apertura errata del file\n");   //se il file non è stato aperto correttamente
    }
    

    
    printf("adenina: %d \n citosina: %d \n guanina: %d \n timina: %d\n", a, c, g, t ); //do in output il risultato

    fclose(fp);

}