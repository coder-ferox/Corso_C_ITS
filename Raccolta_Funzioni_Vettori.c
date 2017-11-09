/**Raccolta di funzioni + programma di test con esperimenti su vettori
 * @PARAM (per i dettagli vedere le singole funzioni)
 * @RETURN (per i dettagli vedere le singole funzioni)
 * @AUTHOR Danilo Cappellino
 * @VERSION 1.0
 * @DATE 12/02/2017
 */



#include <stdio.h>
#include <stdlib.h>


#define DIMVETT 10

int vettore[DIMVETT]={0};



/**Funzione per fare un po' d'ordine nella funzione test */

void acapo()
{
    printf("\n");
    system("pause");
    system("cls");
    printf("\n");
}

/**Funzione per caricare un vettore con dei valori interi dati in input
 * @PARAM input utente
 */

void carico_vettore()
{
    int i;


    for(i=0;i<DIMVETT;i++)
        {
            printf("\nIl vettore e\' da %d posizioni, inserisci la posizione %d: ",DIMVETT,i+1);
            scanf("%d",&vettore[i]);
        }

}

/**Funzione per stampare il vettore precedentemente caricato
 * @PARAM vettore caricato
 */


void stampa_vettore()
{
  int i;
  for(i=0;i<DIMVETT;i++)
    printf("\nvettore[%d] ovvero il num. %d = %d\n",i,i+1,vettore[i]);


}

/**Funzione per conoscere l'id della cella contenente il valore massimo di tutto il vettore
 * @PARAM vettore caricato
 * @RETURN idx (indice max)
 */


int restituisci_idxmax()
{
    int idx;
    int max=0;
    int i;

    for(i=0;i<DIMVETT;i++)
    {
        if(vettore[i] > max)
        {
            max=vettore[i];
            idx=i;
        }
    }
    return idx;
}

/**Funzione per conoscere l'id della cella contenente il valore minimo di tutto il vettore
 * @PARAM vettore caricato
 * @RETURN idx (indice min)
 */


int restituisci_idxmin()
{
    int idx=0;
    int min=vettore[0];
    int i;

    for(i=0;i<DIMVETT;i++)
    {
        if(vettore[i] < min)
        {
            min=vettore[i];
            idx=i;
        }
    }
    return idx;

}

/**Funzione per sommare tutti gli elementi del vettore
 * @PARAM vettore caricato
 * @RETURN somma dei valori del vettore
 */


int somma_elementi()
{
    int i;
    int somma=0;
    for(i=0;i<DIMVETT;i++)
    {
        somma=somma+vettore[i];
    }
    return somma;



}

/**Funzione per scambiare di posizione due elementi del vettore
 * @PARAM a,b (indici degli elementi da scambiare di posizione)
 * @RETURN vettore con gli elementi indicati scambiati di posto
 */


void swap_contents(int a, int b)
{
    int tmp;
    tmp=vettore[a];
    vettore[a]=vettore[b];
    vettore[b]=tmp;
    }

/**Funzione che riordina un vettore disordinato
 * @PARAM vettore caricato
 * @RETURN vettore con i valori ordinati in modo crescente
 */



void ordinatore_vettore()
{
    int i,j,tmp;

    for (i=0; i<DIMVETT-1; i++)
        {
        for (j=DIMVETT-1; j>i; j--)
            if (vettore[j-1] > vettore[j])
                {
                tmp = vettore[j-1];
                vettore[j-1] = vettore[j];
                vettore[j] = tmp;
                }
        }
}

/**Funzione di test delle funzioni sopra scritte
 * @PARAM variabili di supporto ai test laddove necessarie per stampare risultati (testC, testD, testE) o passare parametri (testFa,testFb)
 * @RETURN stampa di vettori e indicazione di valori su richiesta
 */


void test()
{

    int testC;
    int testD;
    int testE;
    int testFa,testFb;

    printf("Test di carico vettore:");
    carico_vettore();
    acapo();

    printf("Test di stampa vettore:");
    stampa_vettore();
    acapo();

    printf("Test di restituzione indice max:");
    stampa_vettore();
    testC=restituisci_idxmax();
    printf("\nL'indice del valore max e\': %d",testC);
    acapo();

    printf("Test di restituzione indice min:");
    stampa_vettore();
    testD=restituisci_idxmin();
    printf("\nL'indice del valore min e\': %d",testD);
    acapo();

    printf("Test di restituzione della somma:");
    testE=somma_elementi();
    printf("\nLa somma e\': %d",testE);
    acapo();

    printf("Test swap vettore:");
    printf("\nInserisci i due indici da scambiare nella forma a,b: ");
    scanf("%d,%d",&testFa,&testFb);
    printf("\nStampa vettore originale:");
    stampa_vettore();
    swap_contents(testFa,testFb);
    printf("\nStampa vettore swappato:");
    stampa_vettore();

    acapo();
    printf("Test di vettore ordinato con sua stampa:");
    printf("\nVettore originale:");
    stampa_vettore();
    printf("\nVettore ordinato:");
    ordinatore_vettore();
    stampa_vettore();

}

int main()
{
    test();
    return 0;
}
