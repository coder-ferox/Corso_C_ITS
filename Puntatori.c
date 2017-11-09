#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

#define INVIO 13
#define SPAZIO 32
#define DIMV 256
#define DIMALFABETO 26

/** Programma che data una stringa dice qual'è il suo range di lettere, quale lettera è stata scritta più volte e quante
*   @AUTHOR Danilo Cappellino
*   @DATE 11/03/2017
*   @VERSION 1.0
*/

//prototipi
char Maiuscolizza(char car);
char Leggi_lettera();
int pokeV (char v[], int dim);
void range(char v[],int dim,char *range1,char *range2);
void countL (char v[], int dimv, int a[], int dima);
void popola_alfabeto(char v[],int dim);
int trova_max_intid_inV(int v[],int dim);
void ripetizioni(char a[],int pa[],int dim,int maxid,char *lettera,int *qta);

int main()
{
    char word[DIMV];
    int wordL=0;
    char range1;
    char range2;
    int punt_alfabeto[DIMALFABETO]={0};
    char alfabeto[DIMALFABETO];
    int maxid;
    char lettera;
    int qta;

    printf("\nInserisci la frase e termina con INVIO: ");
    wordL=pokeV(word,DIMV);

    range(word,wordL,&range1,&range2);
    printf("\n\nIl range di caratteri della stringa parte da \"%c\" e arriva a \"%c\"\n",range1,range2);

    countL(word,wordL,punt_alfabeto,DIMALFABETO);

    popola_alfabeto(alfabeto,DIMALFABETO);

    maxid=trova_max_intid_inV(punt_alfabeto,DIMALFABETO);

    ripetizioni(alfabeto,punt_alfabeto,DIMALFABETO,maxid,&lettera,&qta);
    printf("\nLa lettera maggiormente ripetuta e' %c con %d ripetizioni (%d lettere)\n",lettera,qta-1,qta);

    return 0;
}

/** Funzione che maiuscolizza tutte le lettere minuscole passate come parametro
*   @PARAM (car) carattere dell'alfabeto compreso tra a e z
*   @RETURN (car) carattere corrispondente maiuscolo
*/

char Maiuscolizza(char car)
{
	if(car>='a'&& car<='z')
		car= car - ('a'- 'A');

	return car;
}

/** Funzione che legge una lettera da tastiera (maiuscola o minuscola) più spazi ed invio
*   @RETURN (car) carattere digitato maiuscolo
*/

char Leggi_lettera()
{
	char car;
	car=getch();
    while((car<'A' && car!=INVIO && car !=SPAZIO) || (car>'Z' && car<'a') || car>'z')
		car=getch();
    car=Maiuscolizza(car);
	printf("%c", car);

	return (car);
}

/** Funzione che carica il vettore ripulito dal carattere INVIO (13)
*   @PARAM (v) vettore di caratteri
*   @PARAM (dim) dimensione intera del vettore
*   @MODIFY carica (v) con caratteri
*   @RETURN (i) valore intero rappresentante la lunghezza della stringa introdotta senza caratteri speciali
*/

int pokeV (char v[], int dim)
{
    int i;
    char car;

    car=Leggi_lettera();
    for(i=0;i<dim && car != INVIO;i++)
    {
        v[i]=car;
        car=Leggi_lettera();
    }
    return i;
}

/** Funzione che riporta il range delle lettere digitate nella stringa
*   @PARAM  (v) vettore di caratteri
*   @PARAM  (dim) dimensione del vettore
*   @MODIFY (*range1) estremo sinistro del range delle lettere
*   @MODIFY (*range2) estremo destro del range delle lettere
*/

void range(char v[],int dim,char *range1, char *range2)
{
    int i;
    *range1=v[0];
    *range2=*range1;
    for(i=0;i<dim;i++)
    {
        if(v[i]<*range1)
            *range1=v[i];
        if(v[i]>*range2)
            *range2=v[i];
    }
}

/** Funzione che calcola quante sono le singole lettere presenti nella stringa
*   @PARAM (v) vettore di caratteri che può accettare solo lettere maiuscole
*   @PARAM (dimv) dimensione intera del vettore v da verificare
*   @PARAM (dima) dimensione intera del vettore a (26)
*   @MODIFY (a) vettore di interi che verrà riempito con le quantità delle singole lettere della stringa
*/


void countL (char v[], int dimv, int a[], int dima)
{
    int i,j;
    char car;

    for(i=0;i<dimv;i++)                         //scorri il vettore della parola
        for(j=0;j<dima;j++)                     //scorri l'alfabeto per confronto
            {
            car = 'A'+j;
            if(v[i]==car)
                a[j]++;
            }

    /*for(j=0;j<dima;j++)
        if(!a[j]==0)                           //così riporto solo le lettere presenti
            printf("\n%c = %d",'A'+j,a[j]);*/
}

/** Funzione che popola un vettore di 26 caratteri con le lettere dell'alfabeto maiuscolo
*   @PARAM (v) vettore di caratteri
*   @PARAM (dim) dimensione del vettore, in genere è uguale a 26
*   @MODIFY riempie con le lettere dell'alfabeto il vettore indicato
*/


void popola_alfabeto(char v[],int dim)
{
    char init_lett='A';
    int i;
    for(i=0;i<dim;i++)
        v[i]=init_lett+i;
}

/** Funzione che trova l'indice del valore massimo di un vettore di interi
*   @PARAM (v) vettore di interi
*   @PARAM (dim) dimensione del vettore
*   @RETURN (maxid) intero, id del valore massimo del vettore
*/

int trova_max_intid_inV (int v[],int dim)
{
    int i;
    int max=0;
    int maxid=0;
    for(i=0;i<dim;i++)
        if(v[i]>max)
        {
            max=v[i];
            maxid=i;
        }
    return maxid;
}

/** Funzione che collega a due variabili (carattere e intero) i rispettivi valori rappresentanti lettera dell'alfabeto e quantità della stessa, basandosi sull'input di valore intero id passato esternamente
*   @PARAM (alfa) vettore di caratteri contenente le lettere dell'alfabeto
*   @PARAM (puntalfa) vettore di interi, numero di caratteri per ogni lettera
*   @PARAM (dim) dimensione intera dei due vettori alfa e puntalfa
*   @PARAM (maxid) intero, valore indice per sincronizzare alfa e puntalfa
*   @MODIFY(*lettera) carattere puntato che verrà poi restituito con la lettera prescelta a detta di maxid
*   @MODIFY (*qta) intero puntato che verrà poi restituito con la quantità relativa la lettera prescelta a detta di maxid
*/

void ripetizioni (char alfa[],int puntalfa[],int dim,int maxid,char *lettera,int *qta)
{
    *lettera=alfa[maxid];
    *qta=puntalfa[maxid];
}



