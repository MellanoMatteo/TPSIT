//mellano matteo 
//calcola i giorni in cui vengono contagiati un certo numero di persone

#include <stdio.h>
#include <stdlib.h>

int main()
{
	float r = 0;
	int alunni = 0;
	int *contagiati;
	int giorni = 0;
	int i = 0;

	//contagiati è un array che contiene tutti i contagiati in funzione dei giorni
	//la prima volta alloco 1 cella, e ogni volta lo andrò ad aumentare
	contagiati = (int *)malloc(sizeof(int)); 
	contagiati[i] = 1;

	// inserisco i valori che mi servono
	printf("inserire il valore di contagio\n");
	scanf("%f", &r);
	printf("inserire il numero di alunni\n");
	scanf("%d", &alunni);
	
	//finchè tutti gli alunni non sono stati contagiati
	for (i = 0; alunni > contagiati[i]; i++)
	{
		//aumento la dimensione dell'array per poter inserire un nuovo numero di contagiati
		contagiati = realloc(contagiati, ((i+2)*sizeof(int)));
		
		//calcolo i contagiati nel nuovo giorno 
		contagiati[i + 1] = contagiati[i] + (contagiati[i] * r);

		//aumnto l contatore che contrassegna i nomi
		giorni = i + 1;
		
		//do in output il giorno con il relativo numero di contagiati
		printf("al giorno %d ci sono %d contagiati\n", giorni, contagiati[i]);
	}
	//alla fine dico a che giorno vengono contagiati tutti
	printf("al giorno %d sono stati contagiati tutti gli elementi\n\n", ++giorni);
	return 0;
}