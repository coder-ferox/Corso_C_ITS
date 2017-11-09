/*EX02-Leggere 8 cifre decimali come carattere, calcolare e stampare il numero corrispondente
@author Danilo Cappellino
@date 17/01/2017
@version 1.0
@param cifra [0-9], contatore totale cifre (contTotCifre)
@return stampa delle cifre inserite
*/
#include <stdio.h>
#include <stdlib.h>
int Leggi_cifra()
{i
nt numero;
char carattere;
carattere=getch();
while(carattere<'0' || carattere>'9')
carattere=getch();
numero=carattere-'0';
return(numero);
}
int main()
{
int contCifra=0;
int contTotCifre=8;
int cifra;
int somma=0;
printf("Metti numero DEC da 8 cifre: ");
for(contCifra=0;contCifra<contTotCifre;contCifra++)
{
cifra=Leggi_cifra();
printf("%d",cifra);
somma=somma*10+cifra;
}p
rintf("\n\nCifra digitata: %d",somma);
return 0;
}