/*Ex02 - Inserire 10 valori in un array (da utente) e, successivamente, stamparli a ritroso
*@author Danilo Cappellino
*@version 1.0
*@date 02/02/2017
*@param DIMVETT fissato a 10, numero è la cifra da inserire
*@return stampa a ritroso dei numeri inseriti
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
    int salto=DIMVETT-1;
    printf("Inserisci dieci valori (lung. max per valore 4 cifre) che verranno stampati a ritroso: ");
    for(i=0;i<DIMVETT;i++)
    {
        printf("\nInserisci il %d numero: ",i+1);
        //scanf("%d",&numero);
        numero=Leggi_numero();
        vettore[salto]=numero;
        salto--;
    }
    for(i=0;i<DIMVETT;i++)
    {
        printf("\n%d",vettore[i]);
    }
    printf("\n");
    system("pause");
    return 0;
}