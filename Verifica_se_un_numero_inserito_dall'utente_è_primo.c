/*
*@Verifica se un numero inserito dall'utente è primo
*@author Danilo Cappellino
*@version 1.0
*/

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    int numero;
    int c=2;
    int modulo;
    int trovato=1;
    printf("\nInserire il numero da verificare: ");
    scanf("%d",&numero );
    while (c < numero)
    {
        modulo=numero%c;
        if (modulo==0)
        {
            trovato=0;
            printf("\nIl numero inserito non e primo\n");
            system("PAUSE");
            return 0;
        }
        if (modulo==1)
        {
            trovato=1;
        }
    c=c+1;
    }
    if (trovato==1)
        printf("\nIl numero inserito e primo\n");
    system("PAUSE");
    return 0;
}