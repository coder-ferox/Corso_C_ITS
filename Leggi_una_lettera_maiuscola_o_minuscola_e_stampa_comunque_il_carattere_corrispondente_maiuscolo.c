/*01_Leggi_una_lettera_maiuscola_o_minuscola_e_stampa_comunque_il_cara
ttere_corrispondente_maiuscolo
*@author Danilo Cappellino
*@date 16/12/2016
*@version 1.0
*/
#include <stdio.h>
#include <stdlib.h>
int main()
{
char carattere;
printf("Inserisci una lettera maiuscola o minuscola: ");
carattere = getch();
while ((carattere < 'A' || carattere > 'Z') && (carattere < 'a' ||
carattere > 'z'))
{
carattere = getch();
}
if(carattere >= 'a')
{
printf("\nIl carattere maiuscolo di %c e:
%c\n",carattere,carattere-32);
}
else
{
printf("\nHai premuto: %c\n",carattere);
}
system("PAUSE");
return 0;
}