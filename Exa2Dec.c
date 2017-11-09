/*Ex01 - Utilizzare (e trasformare) la leggi_numero_base() per eseguire la codifica da Esadecimale a Decimale
*@author Danilo Cappellino
*@version 1.0
*@date 02/02/2017
*@param n cifre fino a max 8
*@return numero naturale in decimale
*/

#include <stdio.h>
#include <stdlib.h>

int Leggi_cifra()
{
  char input, lettera;
  int cifra;


  input=getch();

  while((input<'0' && input!=13) || input>'f' || (input>'F' && input<'a') || (input>'9' && input<'A'))
    {
    input=getch();
    }
  printf("%c", input);

  lettera=input;

  if (lettera<='F' && lettera>='A')
  {
  	cifra=lettera-'A'+10;
  }
  else if (lettera<='f' && lettera>='a')
  {
  	cifra=lettera-'a'+10;
  }
  else
  {
  	cifra=lettera-'0';
  }
  return(cifra);

}

/**
 * funzione che legge un numero naturale (in una certa base) di max 6 cifre terminato con INVIO (non accetta altri caratteri)
 * @PARAM base, base in cui si deve computare il numero (2 per binario, 8 per ottale, etc)
 * @RETURN il valore corrispondente al numero inserito in decimale
 */
int Leggi_numero(int base)
{
    int num, c, cifra;
    num=0;

    char limiteBase= (base-1)+'0';
    cifra=Leggi_cifra();

    for(c=0; c<6 && cifra>=0; c++)
    {

        num=num*base+cifra;
        cifra=Leggi_cifra();
    }
    return(num);
}




int main(int argc, char *argv[])
{
  int num;
  printf("Inserisci un num. di 6 cifre nella base esadecimale\n(ti sara' possibile utilizzare solo i relativi tasti): ");

  num= Leggi_numero(16);

  printf("\nIl numero inserito e': %d\n", num);


  system("PAUSE");
  return 0;
}
