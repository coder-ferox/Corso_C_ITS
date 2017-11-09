/*Ex05 - Funzione che legge un numero esadecimale e stampa la sua rappresentazione decimale.
*@author Danilo Cappellino
*@version 1.0
*@date 31/01/2017
*@param n cifre fino a max 6
*@return numero naturale in decimale
*/
#include <stdio.h>
#include <stdlib.h>
int Leggi_cifra()
{
char input, lettera;
int cifra;
input=getch();
while((input<'0' && input!=13) || input>'f' || (input>'F' && input<'a') || (input>'9' &&
input<'A'))
{i
nput=getch();
}
printf("%c", input);
lettera=input;
if (lettera<='F' && lettera>='A')
{
cifra=lettera-'A'+10;
}e
lse if (lettera<='f' && lettera>='a')
{
cifra=lettera-'a'+10;
}e
lse
{
cifra=lettera-'0';
}r
eturn(cifra);
} i
nt Leggi_numero()
{
int num, c, cifra;
num=0;
cifra=Leggi_cifra();
for(c=0; c<6 && cifra>=0; c++)
{
num=num*16+cifra;
cifra=Leggi_cifra();
}r
eturn(num);
}i
nt main(int argc, char *argv[])
{
int numero;
printf("Inserisci un numero binario di max 6 cifre: ");
numero= Leggi_numero();
printf("\nIl tuo numero in base decimale e': %d\n", numero);
system("PAUSE");
return 0;
}