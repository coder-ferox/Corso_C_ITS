/*Calcolo della media di 10 numeri inseriti dall'utente.
*@author Danilo Cappellino
*@version 1.0
*/

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char*argv[])
{
    int c,ctot,addendo,somma,media,resto;
    c=0;
    ctot=10;
    while(c<ctot)
    {
        printf("\nInserisci il numero %d: ",c+1);
        scanf("%d",&addendo);
        somma=somma+addendo;
        c++;
    }
    media=somma/ctot;
    resto=somma%ctot;
    printf("\nLa media dei %d numeri dati corrisponde a: %d,%d\n",ctot,media,resto);
    system("PAUSE");
    return 0;
}