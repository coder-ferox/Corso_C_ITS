/*Ex04 - Funzione che legge un numero binario e stampa la sua rappresentazione decimale.
*@author Danilo Cappellino
*@version 1.0
*@date 31/01/2017
*@param n cifre fino a max 8
*@return numero naturale in decimale
*/
#include <stdio.h>
#include <stdlib.h>
int Leggi_cifra()
{
int cifra;
char car;
car=getch();
while((car<'0' && car!=13) || car>'1')
{c
ar=getch();
}
cifra=car-'0';
return(cifra);
} i
nt Leggi_numero()
{
int num, c, cifra;
num=0;
cifra=Leggi_cifra();
for(c=0; c<8 && cifra>=0; c++) // Leggi e stampa a schermo fino a 8 cifre
{
printf("%d",cifra);
num=num*2+cifra;
cifra=Leggi_cifra();
} return(num);
} 

int main(int argc, char *argv[])
{
int numero;
printf("Inserisci un valore binario di massimo 8 cifre: ");
numero=Leggi_numero();
printf("\nIl numero in base decimale e': %d\n", numero);
system("PAUSE");
return 0;
}