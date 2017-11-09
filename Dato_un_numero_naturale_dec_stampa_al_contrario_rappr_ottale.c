/*04 - Scrivere Flow-chart e codifica di un programma che dato un
numero (Naturale) in decimale stampa (all'incontrario) la
rappresentazione ottale
*@version 1.0
*@author Danilo Cappellino
*@date 22/12/2016
*@param numerodec: valore intero del numero primo
*@return stampa al contrario conversione in binario di numerodec
*/
#include <stdio.h>
#include <stdlib.h>
int base=8;
int main()
{
int numerodec;
int resto;
printf("Inserisci un numero decimale naturale: ");
scanf("%d",&numerodec);
while (numerodec < 0)
{
system("cls");
printf("Inserisci un numero decimale naturale: ");
scanf("%d",&numerodec);
}
while(numerodec>0)
{
resto=numerodec%base;
printf("%d",resto);
numerodec=numerodec/base;
}
return 0;
}