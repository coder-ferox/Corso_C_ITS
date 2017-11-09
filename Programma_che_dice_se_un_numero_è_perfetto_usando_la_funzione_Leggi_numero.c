/*EX02 - Programma che dice se un numero è perfetto usando la funzione Leggi_numero
*@author Danilo Cappellino
*@version 1.0
*@date 26/01/2017
*@param n cifre fino a max 4
*@return responso se il numero è perfetto oppure no
*/

#include <stdio.h>
#include <stdlib.h>

/**
 * funzione che legge una cifra decimale o INVIO (non accetta altri caratteri)
 * @RETURN il valore intero corrispondente alla cifra oppure un valore negativo se inserito INVIO
 */
int Leggi_cifra()
{
  int cifra;
  char car;

  car=getch();

  while((car<'0' && car!=13) || car>'9')
    car=getch();

  printf("%c", car);

  cifra=car-'0';

  return(cifra);

}

/**
 * funzione che legge un numero naturale (decimale) di max 4 cifre terminato con INVIO (non accetta altri caratteri)
 * @RETURN il valore corrispondente al numero inserito
 */


int Leggi_numero()
{
    int VdaVerificare, c, cifra;
    VdaVerificare=0;

    cifra=Leggi_cifra();

    for(c=0; c<4 && cifra>=0; c++)
    {

        VdaVerificare=VdaVerificare*10+cifra;
        cifra=Leggi_cifra();

    }

    return(VdaVerificare);

}

// Leggi_numero modificata per leggere più di quattro cifre
/*
int Leggi_numero()
{
    int VdaVerificare, cifra;
    VdaVerificare=0;

    cifra=Leggi_cifra();

    while(cifra >=0)
    {
        VdaVerificare=VdaVerificare*10+cifra;
        cifra=Leggi_cifra();
    }

    return(VdaVerificare);

}
*/


int main()
{
    int VdaVerificare;
    int divisore=1;
    int somma=0;

    printf("Inserisci il numero da verificare: ");
    VdaVerificare=Leggi_numero();

    while (divisore < VdaVerificare)
    {
        if (VdaVerificare%divisore==0)
        {
            somma=somma+divisore;

        }
        divisore++;
    }
        if (somma==VdaVerificare)
        {
            printf("\n%d e\' un numero perfetto\n",VdaVerificare);
        }
        else
        {
            printf("\n%d non e\' un numero perfetto\n",VdaVerificare);
        }

    system("pause");
    return 0;

}
