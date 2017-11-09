/*EX01-Trovare i primi tre numeri perfetti
@author Danilo Cappellino
@date 17/01/2017
@version 1.0
@param numeri perfetti da cercare (cNumPerf_totali)
@return stampa i numeri perfetti trovati
*/

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int cNumPerf_trovati=0;
    int cNumPerf_totali=3;
    int VdaVerificare=1;
    while (cNumPerf_trovati < cNumPerf_totali)
    { 
        int divisore=1;
        int somma=0;
        while (divisore < VdaVerificare)
        {
            if (VdaVerificare%divisore==0)
            {
                somma=somma+divisore;
            }
            divisore++;
        }
        if (somma==VdaVerificare)
        {
            printf("\n%do numero perfetto trovato = %d",cNumPerf_trovati+1,VdaVerificare);
            cNumPerf_trovati++;
        }
        somma=0;
        divisore=1;
        VdaVerificare++;
    } 
    return 0;
}