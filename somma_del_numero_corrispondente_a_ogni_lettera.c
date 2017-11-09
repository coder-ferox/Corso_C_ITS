/*EX01 - Scrivere il Programma legge un Nome e stampa il numero caratteristico (calcolato nel
seg. modo: somma del numero corrispondente a ogni lettera A=1, B=2, C=3... es. ADA stampa 6, infatti 1(A) +4(D) +1(A) = 6)
*@author Danilo Cappellino
*@version 1.0
*@date 26/01/2017
*@param cifra
*@return stampa della somma delle cifre
*/
/*Funzione Leggi_lettera
*param lettera maiuscola, minuscola o INVIO
*return conversione della lettera in numero secondo questa logica: A/a=1 B/b=2...
*/
#include <stdio.h>
#include <stdlib.h>
int Leggi_lettera()
{
int cifra;
char lettera;
lettera=getch();
while ((lettera<'a' || lettera>'z') && ((lettera<'A' && lettera !=13) || lettera >'Z'))
{l
ettera=getch();
}
printf("%c", lettera);
if (lettera >= 'a' && lettera <= 'z')
{
cifra=lettera-96;
}
else
{
cifra=lettera-64;
}
return(cifra);
} i
nt main()
{
int cifra;
int somma=0;
cifra=Leggi_lettera();
while (cifra>0)
{
somma=somma+cifra;
cifra=Leggi_lettera();
}p
rintf("\nLa somma dei numeri digitati e\': %d",somma);
return 0;
}