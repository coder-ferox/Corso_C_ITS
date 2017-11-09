/*Ex04 - Inserire in un array 10 valori (da utente) e, successivamente, stampare la somma
totale e la media
*@author Danilo Cappellino
*@version 1.0
*@date 02/02/2017
*@param DIMVETT fissato a 10, numero è la cifra da inserire
*@return stampa somma e media
*/

#include <stdio.h>
#include <stdlib.h>
#define DIMVETT 10

/**
* funzione che legge una cifra decimale o INVIO (non accetta altri caratteri)
* @RETURN il valore intero corrispondente alla cifra oppure un valore negativo se inserito
INVIO
*/

int Leggi_cifra()
{
    int cifra;
    char car;
    car=getch();
    while((car<'0' && car!=13) || car>'9')
    car=getch();
    cifra=car-'0';
    return(cifra);
}

/**
* funzione che legge un numero naturale (decimale) di max 4 cifre terminato con INVIO (non
accetta altri caratteri)
* @RETURN il valore corrispondente al numero inserito
*/

int Leggi_numero()
{
    int num, c, cifra;
    num=0;
    cifra=Leggi_cifra();
    for(c=0; c<4 && cifra>=0; c++)
    {
        printf("%d", cifra);
        num=num*10+cifra;
        cifra=Leggi_cifra();
    }
    return(num);
}

int main()
{
    int vettore[DIMVETT];
    int i;
    int numero;
    int somma=0;
    int media;
    int resto;
    printf("Inserisci dieci valori (max 4 cifre per numero) che ti stampo somma e media by vettori: ");
    for(i=0;i<DIMVETT;i++)
    {
        printf("\nInserisci il %d numero: ",i+1);
        //scanf("%d",&numero);
        numero=Leggi_numero();
        vettore[i]=numero;
        somma=somma+vettore[i];
    }
    media=somma/DIMVETT;
    resto=somma%DIMVETT;
    printf("\nHai scritto ");
    for(i=0;i<DIMVETT;i++)
    {
        printf("%d ",vettore[i]);
    }
    if(resto == 0)
        printf("\nLa somma e\' %d mentre la media e\' %d\n",somma,media);
    else
        printf("\nLa somma e\' %d mentre la media e\' %d,%d\n",somma,media,resto);
    system("pause");
    return 0;
}