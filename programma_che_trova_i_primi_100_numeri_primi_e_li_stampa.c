/*Ex02 - Scrivere Flow-chart e codifica di un programma che trova i
primi 100 numeri primi (e li stampa)
*@author Danilo Cappellino
*@date 22/12/2016
*@version 1.0
*@param cont_tot_numprimi: quanti numeri primi voglio trovare -
numero: il numero di partenza della lista
*@return stampa a schermo dei numeri primi e dei rispettivi indici
*/
#include <stdio.h>
#include <stdlib.h>
int main(int argc, char *argv[])
{
int cont_numprimi_trovati=0;
int cont_tot_numprimi=100;
int numero=2;
while(cont_numprimi_trovati<cont_tot_numprimi)
{
int primo = 0;
int div = 2;
int resto;
while (div < numero/2)
{
resto=numero%div;
if (resto == 0)
{
primo = 1;
}
div++;
}
if (primo == 0)
{
printf("\n%d - %d \n",cont_numprimi_trovati,numero);
cont_numprimi_trovati++;
}
numero++;
}
system("PAUSE");
return 0;
}