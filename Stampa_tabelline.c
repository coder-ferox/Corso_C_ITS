/*00 - Scrivere Flow-chart e codifica di un programma che permette di
stampare su righe successive la tabellina del 2, 3, 4... sino al 9.
*@author Danilo Cappellino
*@date 22/12/2016
*@version 1.0
*@param tabellina: il numero di cui verrà calcolata la tabellina -
tabellinafinale: l'ultimo numero di cui voglio la tabellina - ctot:
indica il moltiplicatore massimo della tabellina
*@return stampa a schermo della tabella delle tabelline da 2 a 9 su
righe
*/
#include <stdio.h>
#include <stdlib.h>
int main()
{
int tabellina=2;
int tabellinafinale=9;
int cont=1;
int ctot=10;
int numero;
while(tabellina<=tabellinafinale)
{
numero=tabellina;
while(cont<=ctot)
{
printf("%d\t",numero=cont*numero);
numero=tabellina;
cont++;
}
printf("\n");
tabellina++;
cont=1;
}
return 0;
}