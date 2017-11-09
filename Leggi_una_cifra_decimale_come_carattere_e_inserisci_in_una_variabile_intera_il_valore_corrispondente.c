/*
*@ Esercizio 2 - Leggi una cifra decimale come carattere e inserisci
in una variabile intera il valore corrispondente.
*@ author Danilo Cappellino
*@ date 16/12/2016
*@ version 1.0
*/

#include <stdio.h>
#include <conio.h>

int main(int argc, char*argv[])
{
    char carattere;
    int valoredec;
    printf("Inserisci una cifra decimale [0-9]: ");
    carattere = getch();
    while (carattere < '0' || carattere > '9')
    {
        carattere = getch();
    }
    printf("\nMagic Number di %c: %d",carattere,carattere);
    valoredec = carattere + 0;
    printf("\n\nValore intero di %c convertito in interi %d\n",carattere,valoredec);
    system("PAUSE");
    return 0;
}