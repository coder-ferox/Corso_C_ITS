/*Calcolo della somma dei primi 100 numeri (0 - 99)
*@author Danilo Cappellino
*@version 1.0
*/
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    int c,ctot,somma;
    c=0;
    ctot=100;
    somma=0;
    while(c<ctot)
    {
        somma=somma+c;
        c++;
    }
    printf("Somma da 0 a 99 = %d\n",somma);
    system("PAUSE");
    return 0;
}