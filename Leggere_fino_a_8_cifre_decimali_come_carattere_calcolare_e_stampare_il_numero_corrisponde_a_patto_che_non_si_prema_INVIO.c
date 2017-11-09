/*EX03-Leggere fino a 8 cifre decimali come carattere, calcolare e stampare il numero corrispon
dente sempre che non venga premuto INVIO prima
@author Danilo Cappellino
@date 17/01/2017
@version 1.0
@param cifra [0-9]+13, contatore totale cifre (contTotCifre)
@return stampa delle cifre inserite
@notes il tasto invio riporta come cifra in main il valore 13
*/
#include <stdio.h>
#include <stdlib.h>
int Leggi_cifra_wINVIO()
{i
nt numero;
char carattere;
carattere=getch();
if (carattere != 13)
{
while(carattere<'0' || carattere>'9')
{
carattere=getch();
}
}e
lse
{
numero=13;
return(numero);
} n
umero=carattere-'0';
return(numero);
}
int main()
{
int contCifra=0;
int contTotCifre=8;
int cifra;
int somma=0;
printf("Metti numero DEC da 8 cifre o premi INVIO per uscire: ");
for(contCifra=0;(contCifra<contTotCifre) && (cifra != 13);contCifra++)
{
cifra=Leggi_cifra_wINVIO();
if (cifra == 13)
{
cifra=0;
break;
} p
rintf("%d",cifra);
somma=somma*10+cifra;
}p
rintf("\n\nCifra digitata: %d",somma);
return 0;
}