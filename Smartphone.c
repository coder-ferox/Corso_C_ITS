/**Programma con menu con svariate funzioni su vettori rel. tabella prezzi di uno smartphone
* @AUTHOR Danilo Cappellino
* @VERSION 1.0
* @DATE 19/02/2017
*/



#include <stdio.h>
#include <stdlib.h>
#include <windows.h> //serve alla funzione Sleep

#define DIMV 5

/**Funzione di carico per il vettore prezzi
* @PARAM vettore di interi e dimensione dello stesso
* @MODIFY carica il vettore con dati dell'utente
*/


void carica(int v[], int dim)
{
    int i;

    for(i=0;i<dim; i++)
        {
            printf("Introduci il prezzo per il distributore di ID %d: ",i);
            scanf("%d",&v[i]);
            printf("\n");
        }
}


/**Funzione che stampa il vettore prezzi
* @PARAM vettore di interi e dimensione dello stesso
*/


void stampa (int v[], int dim)
{
    int i;
    printf("Lista prezzi per distributore: \n");
    for(i=0;i<dim; i++)
        printf("%d - EUR %d\n",i,v[i]);
}


/**Funzione che calcola la media dei prezzi
* @PARAM vettore di interi e dimensione dello stesso
* @RETURN media (prezzo medio)
*/

float media (int v[], int dim)
{
    float media;
    int i;
    int somma=0;
    for (i=0;i<dim;i++)
        somma+=v[i];
    media=(float)somma/(float)dim;
    return (media);
}

/**Funzione che dato in input un prezzo, stampa elenco contenente il numero del distributore e il prezzo dello smartphone per tutti i distributori dove costa meno del valore fornito in input con ricerca su tutto il vettore
* @PARAM (v) vettore di interi, (dim) dimensione dello stesso, (input) valore intero di ricerca
*/

void idbyprezzominore (int v[], int dim, int input)
{
    int i;
    int differenza;
    int pPiuBasso=0;
    printf("\nRICERCA DEI DISTRIBUTORI CON UN PREZZO PIU\' BASSO DI %d\n",input);
    for(i=0;i<dim;i++)
    {
        if (v[i]<input)
            {
            differenza=input-v[i];
            printf("\nIl distributore n. %d ha lo smart a: EUR %d con uno scontone di EUR %d \n\n",i,v[i],differenza);
            pPiuBasso=1;
            }
    }
    if(pPiuBasso==0)
            printf("\nIl prezzo inserito e\' gia\' il piu\' basso\n");
}

/**Funzione che calcola e stampa: numero del distributore prezzo dello smartphone che costa meno
* @PARAM (v) vettore di interi e (dim) sua dimensione
*/

void prezzominimo(int v[], int dim)
{
    int i;
    int min=v[0];
    int id_min=0;
    for(i=0;i<dim;i++)
    {
        if(v[i]<min)
        {
           min=v[i];
           id_min=i;
        }
    }
    printf("\n5) PREZZO MINIMO: Il distributore n. %d ha lo smart al prezzo piu\' basso: %d EUR\n",id_min,min);
}

/**Funzione che dato in input un prezzo, di coloro che costano meno ne indica il maggiore
* @PARAM (v) vettore di interi, (dim) sua dimensione, (input) valore intero sul quale basare la ricerca
*/

void prezzomaxtrainfainput(int v[], int dim, int input)
{
    int i,j;
    int min=v[0];
    int max=0;
    int id_max=0;
    for(j=0;j<dim;j++)
    {
        if(v[j]<min)
            min=v[j];
    }
    if(min==input)
       {
       printf("\n6)Questo prezzo e\' il minimo, non ha senso continuare la ricerca\n");
       }
    else
        {
        for(i=0;i<dim;i++)
        {
            if(v[i]<input && max<v[i])
            {
                max=v[i];
                id_max=i;
            }
        }
        printf("\n6)Degli smart con il prezzo inferiore a %d EUR lo smart del distributore %d e\' quello piu\' caro a %d EUR\n",input,id_max,max);
        }

}



/**Funzione che dato in input un prezzo, stampa ID del distributore che ha quel prezzo. Se il distributore non esiste stampa allora un messaggio di errore.
* @PARAM (v) vettore di interi (dim) dimensione del vettore (input) valore intero da ricercare
*/

void cercaprezzopreciso(int v[], int dim, int input)
{
    int i;
    int pUguale=0;
    for(i=0;i<dim && pUguale==0;i++)
        {
        if(input == v[i])
            {
            printf("\nIl distributore n. %d ha lo smart al prezzo ricercato EUR %d\n",i,v[i]);
            pUguale=1;
            }
        }
    if(pUguale==0)
            printf("\nQuery Fallita: nessun distributore ha lo smart a quel prezzo\n");
}



/**Funzione che dati in input il numero del distributore e il nuovo prezzo dello smartphone, modifica del prezzo del distributore fornito in origine con il nuovo prezzo fornito
* @PARAM (v) vettore di interi (dim) dimensione del vettore, (nuovoprezzo) intero prezzo da modificare, (iddist) id del distributore
*/

void modificaprezzo(int v[], int dim, int iddist, int nuovoprezzo)
{
   v[iddist]=nuovoprezzo;
}

/**Data in input una percentuale, aumento dei prezzi di tutti i distributori della percentuale fornita in input
* @PARAM (v) vettore di interi (dim) dimensione del vettore (percentuale) int della percentuale da caricare sui prezzi
*/

void uppercentuale(int v[], int dim, int percentuale)
{
    int i;
    float prezzo;

    for (i=0;i<dim;i++)
    {
        prezzo=(float)v[i]/100*percentuale+(float)v[i];
        v[i]=prezzo;
    }
}

/**Splashscreen con scomparsa a tempo*/

void splashscreen()
{
    printf("\n");
    printf("     #     #                            #     #  #####  #####  #####    ###\n");
    printf("     #     # ##### #     #      ####    ##   ## #     #   #   #     #   ###\n");
    printf("     #     # #     #     #     #    #   # # # # #     #   #   #     #   ###\n");
    printf("     ####### ####  #     #     #    #   #  #  # #     #   #   #     #    # \n");
    printf("     #     # #     #     #     #    #   #     # #     #   #   #     #      \n");
    printf("     #     # #     #     #     #    #   #     # #     #   #   #     #   ###\n");
    printf("     #     # ##### ##### #####  ####    #     #  #####    #    #####    ###\n");
    printf("\n");
    Sleep(3500);
    system("cls");
}

/**Schermata che compare in chiusura del programma*/

void endscreen()
{
    printf("\n");
    printf("#### #   # ####  #### #   # ####   ## ## #### ##### ####   ####\n");
    printf("#  # #   # #     #  # #   # #      # # # #  #   #   #  #   ####\n");
    printf("###   # #  ###   ###   # #  ###    # # # #  #   #   #  #    ## \n");
    printf("#  #   #   #     #  #   #   #      #   # #  #   #   #  #       \n");
    printf("####   #   ####  ####   #   ####   #   # ####   #   ####    ## \n");
    printf("\n");
}

/**Set di azioni ripetitive da presentarsi quando si tenta di accedere a det. funzione con il vettore "vuoto"*/

void novettore()
{
        system("cls");
        printf("CARICA PRIMA IL VETTORE\n\n");
        system("pause");
        system("cls");
}

/**Set di azioni ripetitive per fare pulizia e ordine sullo schermo*/

void acapo()
{
    system("pause");
    system("cls");
}

/**Menu di selezione*/

void menu()
{
  int scelta=1;
  int vettorecarico=0;

  int prezzi[DIMV]={0};
  float mediaprezzi;
  int queryprezzo;
  int iddist;
  int nuovoprezzo;
  int percentuale;


  while(scelta!=0)
  {
    printf("1. Caricamento dei prezzi dello smartphone nel vettore\n");
    printf("2. Stampa dei prezzi dello smartphone\n");
    printf("3. Calcolo e stampa del prezzo medio dello smartphone\n");
    printf("4. Ricerca prezzi minori di input\n");
    printf("5. Stampa prezzo minore\n");
    printf("6. Dato un prezzo in input, dei minori trova quello maggiore\n");
    printf("7. Ricerca un prezzo preciso\n");
    printf("8. Modifica un prezzo preciso\n");
    printf("9. Carica una percentuale su tutto il listino\n");
    printf("0. USCITA\n");

    printf("\nIntroduci la scelta: ");
    scanf("%d", &scelta);

    switch(scelta)
    {
      case 1:

                printf("\n1) CARICO PREZZI DISTRIBUTORI:\n");
                carica(prezzi,DIMV);
                vettorecarico=1;
                acapo();
                break;
      case 2:
                if(vettorecarico==0)
                {
                    novettore();
                    break;
                }
                printf("\n2) STAMPA PREZZI DISTRIBUTORI:\n");
                stampa(prezzi,DIMV);
                acapo();
                break;
      case 3:
                if(vettorecarico==0)
                {
                    novettore();
                    break;
                }
                mediaprezzi=media(prezzi,DIMV);
                printf("\n3) MEDIA PREZZI DISTRIBUTORI: %g\n",mediaprezzi);
                acapo();
                break;
      case 4:
                if(vettorecarico==0)
                {
                    novettore();
                    break;
                }
                printf("\n4) PREZZO MINORE DI INPUT - Quale prezzo vuoi ricercare: ");
                scanf("%d",&queryprezzo);
                printf("");
                idbyprezzominore(prezzi,DIMV,queryprezzo);
                acapo();
                break;
      case 5:
                if(vettorecarico==0)
                {
                    novettore();
                    break;
                }
                prezzominimo(prezzi,DIMV);
                acapo();
                break;
      case 6:
                if(vettorecarico==0)
                {
                    novettore();
                    break;
                }
                printf("\n6) DEI PREZZI MINORI DI INPUT TI DICO IL PIU\' CARO - Quale prezzo vuoi ricercare: ");
                scanf("%d",&queryprezzo);
                printf("");
                prezzomaxtrainfainput(prezzi,DIMV,queryprezzo);
                //prezzomassimo(prezzi,DIMV);
                acapo();
                break;
      case 7:
                if(vettorecarico==0)
                {
                    novettore();
                    break;
                }
                printf("\n7) RICERCA PER PREZZO - Quale prezzo vuoi ricercare: ");
                scanf("%d",&queryprezzo);
                printf("");
                cercaprezzopreciso(prezzi,DIMV,queryprezzo);
                acapo();
                break;
      case 8:
                if(vettorecarico==0)
                {
                    novettore();
                    break;
                }
                printf("\n\n8) MODIFICA PREZZO BY ID\nIndica ID del distributore e nuovo prezzo dello smart separati da una virgola (id,prezzo):");
                scanf("%d,%d",&iddist,&nuovoprezzo);
                while(iddist>DIMV-1 || iddist < 0)
                {
                    printf("ERRORE - Stai uscendo dal vettore, riscrivi un ID accettabile ID[0-%d],prezzo: ",DIMV-1);
                    scanf("%d,%d",&iddist,&nuovoprezzo);
                }
                printf("\nPrezzo originale: EUR %d\n",prezzi[iddist]);
                modificaprezzo(prezzi,DIMV,iddist,nuovoprezzo);
                printf("\nPrezzo modificato: EUR %d\n",prezzi[iddist]);
                acapo();
                break;
      case 9:
                if(vettorecarico==0)
                {
                    novettore();
                    break;
                }
                printf("\n\n9) CARICO PERCENTUALE SUL PREZZO DI TUTTI I DISTRIBUTORI - Quanto carico sul listino in percentuale (solo valori interi): ");
                scanf("%d",&percentuale);
                printf("\nListino originale:\n");
                stampa(prezzi,DIMV);
                uppercentuale(prezzi,DIMV,percentuale);
                printf("\nListino aggiornato:\n");
                stampa(prezzi,DIMV);
                acapo();
                break;
      case 0:
                endscreen();
                break;
      default:
                printf("Opzione errata\n");

    }
  }
}

int main()
{
    splashscreen();

    menu();

    return 0;
}
