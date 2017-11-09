#include <stdio.h>
#include <stdlib.h>

/** Funzione che legge	un carattere (da	a a	z e le corrispettive maiuscole)
*	@RETURN	il carattere corrispondente in maiuscolo
*/
int	leggi_carattere()
{
	char	car;
	car=getch();

	while((car<'A' || car>'z') || (car>'Z' && car<'a'))
	{
		car=getch();
	}
	printf("%c",car);

	return(car);
}

/** Funzione che legge una cifra naturale (da 0	a 9) o INVIO (non accetta altri	caratteri)
*	@RETURN	il valore intero corrispondente	alla cifra oppure un il	valore 13 che corrisponde al tasto INVIO
*/
int	leggi_cifra()
{
	int	cifra;
	char	car;
	car=getch();

	while((car<'0'	&&	car!=13)	||	car>'9')
	{
		car=getch();
	}

	cifra=car-'0';

	return(cifra);
}

/** Funzione che legge un numero naturale di max 8 cifre terminato con INVIO (non accetta altri caratteri)
*	@RETURN	il valore corrispondente al	numero inserito	in decimale
*/
int	leggi_numero()
{
	int	num, c, cifra;
	num=0;
	cifra=leggi_cifra();

	for(c=0;c<8	&& cifra>=0;c++)
	{
		num=num*10+cifra;
		printf("%d",cifra);
		cifra=leggi_cifra();
	}
	return(num);
}

/** Funzione che azzera tutti i valori di un array
 *  @PARAM (v) vettore che sara' modificato
 *  @PARAM (dim) dimensione del vettore
 *  @MODIFY azzera tutti i valori del vettore
 */
void azzera(char v[], int dim)
{
   int i=0;

   for(i=0; i<dim; i++)
   {
      v[i]=' ';
   }
}

/** Funzione che carica il vettore di caratteri con valori inseriti dall'utente
 *  @PARAM (v) vettore di caratteri che sara' modificato
 *  @PARAM (dim) dimensione del vettore
 *  @PARAM (num) valore intero che identifica la parola esaminata
 *  @MODIFY modifica tutti i valori del array
 */
void carica(char v[], int dim, int num)
{
   int i=0;

   printf("\nInserisci la parola n.%d: ",num);

   for(i=0; i<dim; i++)
   {
   	  v[i]=leggi_carattere();
   }
   printf("\n");
}

/** Funzione che stampa la parola inserita dall'utente
 *  @PARAM (v) vettore di caratteri che sara' esaminato
 *  @PARAM (dim) dimensione del vettore
 *  @PARAM (num) valore intero che identifica la parola esaminata
 */
void stampa(char v[], int dim, int num)
{
   int i=0;

    printf("\nLa parola n.%d: ",num);

   for(i=0; i<dim; i++)
   {
      printf("%c",v[i]);
   }
    printf("\n");
}

/** Funzione riceve in ingresso un carattere e da in output lo stesso carattere maiuscolo - Se il carattere e' gia maiuscolo non fa nulla e ritorna lo stesso carattere
 *  @PARAM (car) carattere intero che sarà analizzato
 *  @RETURN (car) carattere maiuscolo se in input è minuscolo
 */

char maiuscolizza(char car)
{
   int i=0;

   	if(car>'Z')
   	{
   	car=car-('a'-'A');
	}
	return(car);
}

/** Funzione controlla se le due parole inserite dall'utente sono uguali e stampa il risultato
 * @PARAM (parola1) vettore che sara' esaminato
 * @PARAM (parola2) vettore che sara' esaminato
 * @PARAM (dim) dimensione del vettore
 */

void controlla_differenze(char parola1[], char parola2[], int dim)
{
	int i=0;
	int count=0;

	for(i=0;i<dim;i++)
	{
		if(parola1[i]!=parola2[i])
		{
			printf("\nLe due parole inserite non sono uguali !!!");
			i=dim;
		}
		else
		{
			count++;
		}
		if(count==dim)
		{
			printf("\nLe due parole inserite sono uguali !!!");
		}
	}
	printf("\n");
}

/** Funzione controlla se le due parole inserite dall'utente sono uguali ignorando il case della lettera e stampa il risultato
 *  @PARAM (parola1) vettore di caratteri che sara' esaminato
 *  @PARAM (parola2) vettore di caratteri che sara' esaminato
 *  @PARAM (dim) dimensione del vettore
 */
void controlla(char parola1[], char parola2[], int dim)
{
	int i=0;
	int count=0;
	char a;
	char b;

	for(i=0;i<dim;i++)
	{
		a=parola1[i];
		b=parola2[i];

		a=maiuscolizza(a);
		b=maiuscolizza(b);

		if(a!=b)
		{

			printf("\nLe due parole inserite non sono uguali !!!");
			i=dim;
		}
		else
		{
			count++;
		}
		if(count==dim)
		{
			printf("\nLe due parole inserite sono uguali !!!");
		}
	}
	printf("\n");
}

/** Funzione che crea un menu' e accetta valori valori interi per spostarsi tra le varie opzioni
 * @PARAM (parola1) vettore di caratteri che sara' esaminato
 * @PARAM (parola2) vettore di caratteri che sara' esaminato
 * @PARAM (dim) dimensione del vettore
 */

void menu(char parola1[], char parola2[], int dim)
{
	int scelta=1;

	while(scelta!=0)
    {
  	  	printf("\n\n1) Carica dati\n");
    	printf("\n2) Stampa dati\n");
    	printf("\n3) Controlla se le due parole inserite sono uguali considerando la differenza tra le maiuscole e le minuscole\n");
    	printf("\n4) Controlla se le due parole inserite sono uguali senza considerare la differenza tra le maiuscole e le minuscole\n");

    	printf("\n0) USCITA\n");

		printf("\nIntroduci la scelta: ");
		scelta=leggi_numero();
		printf("\n");

		switch(scelta)
    	{
    			case 1:
    				printf("\nDi quanti caratteri sono le parole che vuoi inserire? ");
					dim=leggi_numero();
					printf("\n");
    	            carica(parola1, dim,1);
    	            carica(parola2, dim,2);
                	printf("\n");
                	system("PAUSE");
                	system("cls");
                	break;
	 			case 2:
                	stampa(parola1, dim,1);
                	stampa(parola2, dim,2);
                	printf("\n");
                	system("PAUSE");
                	system("cls");
                	break;
	  			case 3:
                	controlla_differenze(parola1, parola2, dim);
                	printf("\n");
                	system("PAUSE");
                	system("cls");
                	break;
	  			case 4:
                	controlla(parola1, parola2, dim);
                	printf("\n");
                	system("PAUSE");
                	system("cls");
                	break;
      			case 0:
                	break;
      			default:
                	printf("\n\nPer favore introdurre un opzione valida\n");
   		}
   }
}

/** Confronta due stringhe e verifica se sono uguali oppure no
 * @AUTHOR Danilo Cappellino
 * @VERSION 1.0
 * @DATE 27/02/2017
 */

int main(int argc, char *argv[])
{
	int DIM=0;

	printf("Di quanti caratteri sono le parole che vuoi inserire? ");
	DIM=leggi_numero();

	char parola1[DIM];
	char parola2[DIM];

	printf("\n");
	carica(parola1, DIM,1);
	carica(parola2, DIM,2);

	menu(parola1, parola2, DIM);

	system("PAUSE");
	return 0;
}
