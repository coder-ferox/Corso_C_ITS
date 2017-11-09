/*05 - Scrivere Flow-chart e codifica di un programma che permette
l'inserimento di un numero (Naturale) e stampa se è "perfetto"
*@author Danilo Cappellino
*@date 02/01/2017
*@version 1.0
*@param numeronat: numero naturale da verificare
*@return stampa se numeronat è perfetto oppure no
*@notes Un numero è perfetto se è uguale alla somma dei suoi divisori
*/

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int numeronat;
    int divisore=1;
    int somma=0;
    printf("Introdurre un numero naturale: ");
    scanf("%d",&numeronat);
    while (numeronat <= 0)
    {
        system("cls");
        printf("Introdurre un numero naturale: ");
        scanf("%d",&numeronat);
    }
    while (divisore < numeronat)
    {
        if (numeronat%divisore==0)
        {
            somma=somma+divisore;
        }
        divisore++;
    }
    if (somma==numeronat)
    {
        printf("\nNumero perfetto\n");
    }
    else
    {
        printf("\nNumero non perfetto\n");
    }
    return 0;
}