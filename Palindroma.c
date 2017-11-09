#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <conio.h>

#define DIMV 100


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

//Funzione che mi consente solo di inserire lettere e non numeri

/** Funzione che legge solo lettere, spazi e INVIO
*   @RETURN (car) carattere
*/

char Leggi_lettera()
{
	char car;
	car=getch();
    while((car<'A' && car!=13 && car !=32) || (car>'Z' && car<'a') || car>'z')
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
    for(i=0;i<dim && car != 13;i++)
    {
        v[i]=car;
        car=Leggi_lettera();
    }
    return i;
}

/** Funzione che stampa il vettore alla lunghezza riportata dalla funzione di caricamento
*   @PARAM (v) vettore di caratteri
*   @PARAM (dim) dimensione intera del vettore da stampare
*/

void prntV (char v[], int dim)
{
    int i;
    for(i=0;i<dim;i++)
        printf("%c",v[i]);
}

/** Funzione che calcola quante sono le singole lettere presenti nella stringa e ne stampa il risultato a schermo
*   @PARAM (v) vettore di caratteri
*   @PARAM (dimv) dimensione intera del vettore v da verificare
*   @PARAM (a) vettore di interi rappresentante il punteggio in relazione alle lettere dell'alfabeto
*   @PARAM (dima) dimensione intera del vettore a (26)
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

    for(j=0;j<dima;j++)
        if(!a[j]==0)                           //così riporto solo le lettere presenti
            printf("\n%c = %d",'A'+j,a[j]);
}

/** Funzione che stabilisce se la lunghezza della stringa è pari o dispari
*   @PARAM (dimv) valore intero ritornato dalla funzione di caricamento del vettore "pokeV"
*   @RETURN (resp) valore intero che può essere 1 se pari o 0 se dispari
*/

int lPari (int dimv)
{
    int resp;
    resp = ((dimv%2)==0) ? 1 : 0;
    return(resp);
}

/** Funzione che analizza la stringa di lunghezza pari e stabilisce se è palindroma oppure no (ANNA - ANNAANNA)
*   @PARAM (v) vettore contenente la stringa di caratteri
*   @PARAM (dimv) dimensione intera della stringa di caratteri
*   @RETURN (resp) valore intero uguale a 1 se la stringa è palindroma, 0 se non lo è
*/

int sepalindromapari(char v[], int dimv)
{

    int i,salto=0,punteggior=dimv/2,punteggio=0,resp;

    for(i=0;i<dimv/2;i++)
    {
        if(v[i]==v[dimv-1-salto])
            {
            punteggio++;
            salto++;
            }
        else
            {
            salto++;
            }
    }

    resp = (punteggio == punteggior) ? 1 : 0;
    return (resp);

}

/** Funzione che analizza la stringa di lunghezza dipari e stabilisce se è palindroma oppure no (CASAC - SATOR ROTAS) la differenza con la precedente funzione consiste nel gestire la singola lettera centrale
*   @PARAM (v) vettore contenente la stringa di caratteri
*   @PARAM (dimv) dimensione intera della stringa di caratteri
*   @RETURN (resp) valore intero uguale a 1 se la stringa è palindroma, 0 se non lo è
*/

int sepalindromadisp(char v[], int dimv){

    int i,salto=0,punteggio=0,punteggior=dimv/2,resp;

    for(i=0;i<dimv/2+1;i++)
    {
        if(v[i]==v[dimv-1-salto])
            {
            if(i != dimv/2)                 //Per la lettera centrale si deve ragionare per indici non per contenuto
                {
                punteggio++;
                salto++;
                }
            }
        else
            {
            salto++;
            }
    }

        resp = (punteggio == punteggior) ? 1 : 0;
        return (resp);

}

/** Funzione che carica uno splashscreen grafico con generazione di parola palindroma */

void splashscreen()
{
    char palindroma[19]={'P','A','L','I','N','D','R','O','M','A'};
    int i,j=8;

    for(i=10;i<19;i++)
        {
        palindroma[i]=palindroma[j];
        j--;
        }

    int c=0;

    while(c<6){
    printf("\n\n\n\n\n\n\n\n\n\n");
    printf("                                     *****     \n");
    printf("                                 *** *   * *** \n");
    printf("                                 * * *   * * * \n");
    printf("                                 *** *   * *** \n");
    printf("                                     *****     \n");
    Sleep(200);
    system("cls");

    printf("\n\n\n\n\n\n\n\n\n\n");
    printf("                                *****     *****\n");
    printf("                                *   * *** *   *\n");
    printf("                                *   * * * *   *\n");
    printf("                                *   * *** *   *\n");
    printf("                                *****     *****\n");
    Sleep(200);
    system("cls");

    printf("\n\n\n\n\n\n\n\n\n\n");
    printf("                                               \n");
    printf("                                 ***       *** \n");
    printf("                                 * *   *   * * \n");
    printf("                                 ***       *** \n");
    printf("                                               \n");
    Sleep(200);
    system("cls");

    printf("\n\n\n\n\n\n\n\n\n\n");
    printf("                                               \n");
    printf("                                      ***      \n");
    printf("                                  *   * *   *  \n");
    printf("                                      ***      \n");
    printf("                                               \n");
    Sleep(200);
    system("cls");

    c++;
    }

    printf("\n\n\n\n\n\n\n\n\n\n\n       ");
    for (i=0;i<65;i++)
        printf("*");

    printf("\n       *** ");
    for(i=0;i<19;i++)
        {
        printf(" %c ",palindroma[i]);
        Sleep(200);
        }
    printf(" ***\n");
    printf("       ");
    for (i=0;i<65;i++)
        printf("*");
    printf("\n\n\n\n\n\n\n\n\n\n\n");
    system("pause");
}

/** Programma che data una parola in input (stoppata con INVIO) ne conta i caratteri e stabilisce se è palindroma oppure no
*   @AUTHOR Danilo Cappellino
*   @DATE 04/03/2017 @ 14:30
*   @VERSION 1.0
*   @NOTES Test di riferimento - Stringhe lunghezza pari: ANNA (palindroma) ANNO (no palindroma) AMNO (no palindroma) ANNA  ANNA (palindroma) - Stringhe lunghezza dispari: CASAC (palindroma) CASOC (no palindroma) CASAB (no palindroma) SATOR ROTAS (palindroma)
*/


int main()
{
    char word[DIMV];
    int wordL;
    int alfa[26]={0};
    char scelta=' ';
    int j;


    splashscreen();

    while(scelta!=27){
    system("cls");
    printf("\nInserisci la parola: ");
    wordL=pokeV(word,DIMV);
    printf("\n");
    printf("\nStampo la parola: ");
    prntV(word,wordL);
    printf("\n");
    for(j=0;j<26;j++)                   //azzero il vettore dei punteggi prima di fare un altro conteggio
        alfa[j]=0;
    countL (word,wordL,alfa,26);
    printf("\n");

    if(lPari(wordL) == 1)
        {
        if(sepalindromapari(word,wordL)==1)
        printf("\nLa stringa e' di lunghezza pari ed e' palindroma");
        else
        printf("\nLa stringa e' di lunghezza pari e non e' palindroma");
        }
    else
        {
        if(sepalindromadisp(word,wordL)==1)
        printf("\nLa stringa e' di lunghezza dispari ed e' palindroma");
        else
        printf("\nLa stringa e' di lunghezza dispari e non e' palindroma");
        }



    printf("\n");
    printf("Premi un tasto qualunque per analizzare un'altra stringa o ESC per uscire");
    scelta=getch();
    }
    return 0;
}
