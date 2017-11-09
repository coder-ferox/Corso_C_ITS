/*Calcolo della media dei primi 100 numeri (0 - 99)
*@author Danilo Cappellino
*@version 1.0
*/
#include <stdio.h>
#include <stdlib.h>
int main(int argc, char *argv[])
{
int c,ctot,somma,media,resto;
c=0;
ctot=100;
somma=0;
while(c<ctot)
{
somma=somma+c;
c++;
}
media=somma/ctot;
resto=somma%ctot;
printf("Media della somma da 0 a 99 = %d,%d\n",media,resto);
system("PAUSE");
return 0;
}