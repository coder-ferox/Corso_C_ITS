/*Ex03 - Inserire 10 valori in un array (da utente) e scrivere chi è il massimo e chi il
minimo
*@author Danilo Cappellino
*@version 1.0
*@date 02/02/2017
*@param DIMVETT fissato a 10, numero è la cifra da inserire
*@return ricava max e min dal vettore
*/
#include <stdio.h>
#include <stdlib.h>
#define DIMVETT 10
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
cifra=car-'0';
return(cifra);
}
/**
* funzione che legge un numero naturale (decimale) di max 4 cifre terminato con INVIO (non
accetta altri caratteri)
* @RETURN il valore corrispondente al numero inserito
*/
int Leggi_numero()
{
int num, c, cifra;
num=0;
cifra=Leggi_cifra();
for(c=0; c<4 && cifra>=0; c++)
{
printf("%d", cifra);
num=num*10+cifra;
cifra=Leggi_cifra();
}
return(num);
}

int main()
{
int vettore[DIMVETT];
int i;
int numero;
int max=0;
int min;
printf("Inserisci dieci valori (4 cifre max per numero) e ti diro\' chi e\' il max e chi
il min: \n");
for(i=0;i<DIMVETT;i++)
{
printf("\nInserisci il %d numero: ",i+1);
//scanf("%d",&numero);
numero=Leggi_numero();
vettore[i]=numero;
if(vettore[i] > max)
{
max=vettore[i];
}
if(vettore[i] <= min)
{
min=vettore[i];
}
}
printf("\nHai scritto ");
for(i=0;i<DIMVETT;i++)
{
printf("%d ",vettore[i]);
}
printf("\nIl numero minimo e\' %d mentre il massimo e\' %d\n",min,max);
system("pause");
return 0;
}