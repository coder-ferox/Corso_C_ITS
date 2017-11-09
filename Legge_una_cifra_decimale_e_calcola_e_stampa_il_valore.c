/*
*@ Esercizio 0 - Legge una cifra decimale e calcola e stampa il valore
intero corrispondente
*@ author Danilo Cappellino
*@ date 16/12/2016
*@ version 1.0
*/
#include <stdio.h>
#include <stdlib.h>
int main()
{
int cifra;
printf("Inserisci una cifra decimale [0-9]: ");
cifra = getch();
while (cifra < '0' || cifra > '9')
{
cifra = getch();
}
printf("\nValore intero: %d\n",cifra);
system("PAUSE");
return 0;
}