/*Ex03 - Leggi 10 num con Leggi numero e stampa chi maggiore e chi minore
*@author Danilo Cappellino
*@version 1.0
*@date 26/01/2017
*@param n cifre fino a max 4
*@return stampa numero max e min
*/
#include <stdio.h>
#include <stdlib.h>
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
printf("%c", car);
cifra=car-'0';
return(cifra);
} /
**
* funzione che legge un numero naturale (decimale) di max 4 cifre terminato con INVIO (non accetta altri caratteri)
* @RETURN il valore corrispondente al numero inserito
*/
int Leggi_numero()
{
int num, c, cifra;
num=0;
cifra=Leggi_cifra();
for(c=0; c<4 && cifra>=0; c++)
{
num=num*10+cifra;
cifra=Leggi_cifra();
} r
eturn(num);
} i
nt main()
{
int numero;
int min;
int max=0;
int c=0;
printf("Min Max - Inserisci dieci numeri:\n ");
while (c<10)
{
numero=Leggi_numero();
system("cls");
printf("Min Max - Inserisci dieci numeri:\n ");
if (numero > max)
{m
ax=numero;
}
if (numero <= min)
{m
in=numero;
}
//else
//numero=0;
c++;
}p
rintf("\nIl numero minimo e\' %d mentre il massimo e\' %d\n",min,max);
system("pause");
return 0;
}