#include <stdio.h>
#include <stdlib.h>

#define DIMV 500 // dimensione della sala

/** Funzione che capitalizza le lettere minuscole
*   @PARAM (car) char, carattere
*   @RETURN (car) char, carattere trasformato
*/

char Capitalizza_lettera(char car)
{
	// Se la lettera � minuscola, la trasformo in minuscola
	if (car >= 'a' && car <= 'z')
      car = car - ('a' - 'A');

	return (car);
}

/** Funzione che legge una cifra numerica intera e chiude con INVIO
*   @RETURN (cifra) int
*/

int Leggi_cifra()
{
  int cifra;
  char car;

  car=getch();

  while((car<'0' && car!=13) || car>'9' )
      {
         system("cls");
         printf("Inserisci dei numeri e chiudi con INVIO: ");
         car=getch();
      }
  printf("%c", car);
  cifra=car-'0';
  return(cifra);

}

/** Funzione che legge una lettera
*   @RETURN (lettera) char a sua volta capitalizzata
*/

char Leggi_lettera()
{
    char lettera;
    lettera = Capitalizza_lettera(getche());
    while ((lettera < 'A' || lettera > 'Z') && (lettera < 'a' || lettera > 'z'))
        {
            system("cls");
            printf("Scrivi UNA lettera: ");
            lettera = Capitalizza_lettera(getche());
        }



    return(lettera);
}

/** Funzione che legge un numero naturale (decimale) terminato con INVIO (non accetta altri caratteri)
 *  @RETURN il valore corrispondente al numero inserito
 */

int Leggi_numero()
{
    int num, c, cifra;
    num=0;

    cifra=Leggi_cifra();

    for(c=0;cifra>=0; c++)
    {
        num=num*10+cifra;
        cifra=Leggi_cifra();
    }
    return(num);
}




/** Funzione che crea lista degli invitati caricando diversi vettori
*   @PARAM  (vnome) vettore di caratteri
*   @PARAM  (vcognome) vettore di caratteri
*   @PARAM  (veta) vettore di interi
*   @PARAM  (vcostume) vettore di caratteri
*   @PARAM  (dim) dimensione intera dei precedenti vettori
*   @MODIFY Vengono modificare i vettori vnome,vcognome,veta,vcostume
*/

void crealista(char vnome[], char vcognome[], int veta[], char vcostume[], int dim)
{
    int i;

    for(i=0;i<dim; i++)
        {
            printf("\nInvitato %d di %d\n=================",i+1,dim);
            printf("\nIntroduci il nome (digita una lettera): ");
            vnome[i]=Leggi_lettera();
            printf("\nIntroduci il cognome (digita una lettera): ");
            vcognome[i]=Leggi_lettera();
            printf("\nIntroduci l'eta' (digita numero e premi invio): ");
            veta[i]=Leggi_numero();
            printf("\nIntroduci il costume (digita una lettera): ");
            vcostume[i]=Leggi_lettera();
            printf("\n");
        }
}


/** Funzione che stampa la lista degli invitati leggendo da diversi vettori
*   @PARAM  (vnome) vettore di caratteri
*   @PARAM  (vcognome) vettore di caratteri
*   @PARAM  (veta) vettore di interi
*   @PARAM  (vcostume) vettore di caratteri
*   @PARAM  (dim) dimensione intera dei precedenti vettori
**/

void stampalista(char vnome[], char vcognome[], int veta[], char vcostume[], int dim)
{
    int i;
    printf("Lista degli invitati: \n");
    for(i=0;i<dim; i++)
        printf("%do Inv. - Nome: %c, Cognome: %c, Eta\': %d, Costume: %c\n",i+1,vnome[i],vcognome[i],veta[i],vcostume[i]);

}


/** Funzione che dato un costume per query, stampa la lista dei nomi degli invitati che lo indosseranno
*   @PARAM  (vnome) vettore di caratteri
*   @PARAM  (vcognome) vettore di caratteri
*   @PARAM  (veta) vettore di interi
*   @PARAM  (vcostume) vettore di caratteri
*   @PARAM  (dim) dimensione intera dei precedenti vettori
*   @PARAM  (queryc) valore in carattere da cercare
**/

void querynomibycostume (char vnome[], char vcognome[], int veta[], char vcostume[], int dim, char queryc)
{
    int i;
    int queryriuscita=0;
    printf("\nI seguenti invitati portano il costume %c\n",queryc);
    for (i=0;i<dim;i++)
    {
        if(queryc == vcostume[i])
        {
        printf("Inv. %d - Nome: %c, Cognome: %c\n",i+1,vnome[i],vcognome[i]);
        queryriuscita=1;
        }
    }

    if(queryriuscita==0)
        printf("\nNessun invitato veste il costume %c\n",queryc);
}

/** Funzione che dato un costume per query, calcola e stampa l'età media degli invitati che lo indosseranno
*   @PARAM  (vnome) vettore di caratteri
*   @PARAM  (vcognome) vettore di caratteri
*   @PARAM  (veta) vettore di interi
*   @PARAM  (vcostume) vettore di caratteri
*   @PARAM  (dim) dimensione intera dei precedenti vettori
*   @PARAM  (queryc) valore in carattere da cercare
**/

float calcoloetamediabycostume (char vnome[], char vcognome[], int veta[], char vcostume[], int dim, char queryc)
{
    float media;
    int i;
    int somma=0;
    int queryriuscita=0;
    int dimparziale=0;

    for (i=0;i<dim;i++)
    {
        if(queryc == vcostume[i])
        {
        somma+=veta[i];
        dimparziale++;
        queryriuscita=1;
        }
    media=(float)somma/(float)dimparziale;
    }

    if(queryriuscita==0)
        return -100;
    else
        return (media);

}


/** Funzione per calcolare il minimo
*   @PARAM  (veta) vettore di interi
*   @PARAM  (dim) dimensione intera del vettore
*   @RETURN (min) valore intero minimo
**/


int minimo (int veta[], int dim)
{
    int i;
    int min=veta[0];
    for(i=0;i<dim;i++)
    {
        if(veta[i]<min)
        {
           min=veta[i];
        }
    }
    return(min);
}

/** Funzione per calcolare il massimo
*   @PARAM  (veta) vettore di interi
*   @PARAM  (dim) dimensione intera del vettore
*   @RETURN (max) valore intero massimo
**/

int massimo (int veta[], int dim)
{
    int i;
    int max=veta[0];
    for(i=0;i<dim;i++)
    {
        if(veta[i]>max)
        {
           max=veta[i];
        }
    }
    return(max);
}

/** Funzione per calcolare e stampare la fascia d'età degli invitati
*   @PARAM  (min) valore intero minimo ritornato dalla funzione minimo
*   @PARAM  (max) valore intero massimo ritornato dalla funzione massimo
**/

void fasciadeta (int min, int max)
{
    printf("\nLa fascia d'eta' degli invitati va da %d a %d\n",min,max);
}



/** Funzione che dato un costume per query, ne stampa l'indossatore più vecchio
*   @PARAM  (vnome) vettore di caratteri
*   @PARAM  (vcognome) vettore di caratteri
*   @PARAM  (veta) vettore di interi
*   @PARAM  (vcostume) vettore di caratteri
*   @PARAM  (dim) dimensione intera dei precedenti vettori
*   @PARAM  (queryc) valore in carattere da cercare
**/

void piuvecchiowcostume (char vnome[], char vcognome[], int veta[], char vcostume[], int dim, char queryc)
{
    int queryriuscita=0;
    int i;
    int max=veta[0];
    int id_max=0;
    char nome=' ';
    char cognome=' ';
    char costume=' ';
    for(i=0;i<dim;i++)
    {
        if(queryc == vcostume[i])
        {
            queryriuscita=1;
            if(veta[i]>max)
            {
            max=veta[i];
            id_max=i;
            }
        }
    }
    if(queryriuscita==0)
        printf("\nNessun invitato veste il costume %c\n",queryc);

    else
    {
     nome=vnome[id_max];
     cognome=vcognome[id_max];
     costume=vcostume[id_max];
     printf("\n%c.%c. di anni %d e' il piu' vecchio ad indossare il costume %c\n",nome,cognome,max,costume);
    }
}


/** Funzione che dato un nome per query, ne stampa tutti i dati o un msg d'errore se il nome non esiste
*   @PARAM  (vnome) vettore di caratteri
*   @PARAM  (vcognome) vettore di caratteri
*   @PARAM  (veta) vettore di interi
*   @PARAM  (vcostume) vettore di caratteri
*   @PARAM  (dim) dimensione intera dei precedenti vettori
*   @PARAM  (queryc) valore in carattere da cercare
**/

void infoinvitato (char vnome[], char vcognome[], int veta[], char vcostume[], int dim, char queryc)
{
    int queryriuscita=0;
    int i;

    for(i=0;i<dim;i++)
    {
        if(queryc == vnome[i])
        {
            queryriuscita=1;
            printf("\nInvitato n. %d:\nNome: %c\nCognome: %c\nEta': %d\nCostume: %c\n\n",i,vnome[i],vcognome[i],veta[i],vcostume[i]);
        }
    }

    if(queryriuscita==0)
        printf("\nNessuno si chiama %c\n",queryc);

}

/** Funzione che controlla quale valore in un array di caratteri è minore - Se ci sono piu' valori con lo stesso numero il programma usa il primo che incontra
 *  @PARAM (vnome) vettore di caratteri che sara' verificatyo
 *  @PARAM (dim) valore intero della dimensione del vettore
 *  @PARAM (start) indice da cui inziare a ciclare l'array per il controllo
 *  @RETURN (id_min) id relativo al valore minimo
 */

int minimo_char(char vnome[], int dim, int start)
{
   int i=0;
   int min=vnome[start];
   int id_min=start;

    for(i=start; i<dim; i++)
    {
    	if(min>vnome[i])
    	{
    		min=vnome[i];
    		id_min=i;
		}
	}
   return(id_min);
}

/** Funzione che dati due indici effettua lo scambio dei valori dei due corrispettivi indici in un array di caratteri
 * @PARAM v, vettore generico che sara' esaminato
 * @PARAM i primo indice i >=0 e <dim
 * @PARAM j secondo indice j >=0 e <dim
 * @MODIFY modifica il vettore con i valori corrispondenti agli indici scambiati
*/

void swap_idchar(char v[], int i, int j)
{
     int tmp;

     tmp=v[i];
     v[i]=v[j];
     v[j]=tmp;
}

/** Funzione che dati due indici effettua lo scambio dei valori dei due corrispettivi indici in un array di interi
 * @PARAM v, vettore generico che sara' esaminato
 * @PARAM i primo indice i >=0 e <dim
 * @PARAM j secondo indice j >=0 e <dim
 * @MODIFY modifica il vettore con i valori corrispondenti agli indici scambiati
*/

void swap_idint(int v[], int i, int j)
{
     int tmp;

     tmp=v[i];
     v[i]=v[j];
     v[j]=tmp;
}

/** Funzione che ordina in maniera crescente i 3 vettori basandosi al primo valore passato da un array di caratteri
 * @PARAM (vnome) vettore di caratteri che sara' riordinato e che farà anche da riferimento per l'ordine
 * @PARAM (vcognome) vettore di caratteri che sara' riordinato
 * @PARAM (veta) vettore di interi che sara' riordinato
 * @PARAM (vcostume) vettore di caratteri che sara' riordinato
 * @PARAM (dim) dimensione dei vettori
 */

void ordinaAlfabetoASC(char vnome[], char vcognome[], int veta[], char vcostume[], int dim)
{
     int i,i_min;

     for(i=0; i<dim; i++)
     {
       i_min=minimo_char(vnome, dim, i);
       swap_idchar(vnome, i, i_min);
       swap_idchar(vcognome, i, i_min);
       swap_idint(veta, i, i_min);
       swap_idchar(vcostume, i, i_min);
     }
}

/** Funzione che crea un elenco in base ai costumi di quante persone lo indosseranno - Ogni costume verra' elencato una volta solo con il numero corrispettivo delle persone che lo indosseranno
 * @PARAM (vcostume) vettore di caratteri che sara' esaminato
 * @PARAM (dim) dimensione del vettore
 */

void conta_costumi(char vcostume[], int dim)
{
	int i=0;
	char verifica=vcostume[i];
	int count=0;

	for(i=0;i<dim;i++)
	{
		if(verifica==vcostume[i])
		{
			count++;
		}
		else
		{
			printf("\n%d persone vestono il costume %c",count,verifica);
			verifica=vcostume[i];
			count=1;
		}
	}
	printf("\n%d persone vestono il costume %c",count,verifica);
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

/** Gestione lista invitati alla festa in maschera basato su vettori paralleli e con ausilio di un menu
*   @AUTHOR Danilo Cappellino
*   @DATE 27/02/2017
*   @VERSION 1.0
*/

int main()
{
    int scelta=1;
    int vettorecarico=0;

    char nome[DIMV];
    char cognome[DIMV];
    int eta[DIMV];
    char costume[DIMV];
    int invitatireali;
    char querycar;
    float etamediabycostume;
    int etaminima;
    int etamassima;

    printf("Quanti sono gli invitati ? (metti numero e premi invio) ");
    invitatireali = Leggi_numero();
    system("cls");

    while(scelta!=0)
    {
        printf("1) Carica la lista degli invitati\n");
        printf("2) Stampa la lista degli invitati\n");
        printf("3) Dato un costume, stampa i nomi degli indossatori\n");
        printf("4) Dato un costume, calcolo e stampa dell'eta' media degli indossatori\n");
        printf("5) Calcolo e stampa della fascia d'eta' degli invitati\n");
        printf("6) Dato un costume, stampa dell'indossatore piu' vecchio\n");
        printf("7) Dato il nome di un invitato, stampa di tutti i suoi dati\n");
        printf("8) Ordinamento lista in ordine alfabetico per nome\n");
        printf("9) Elenco contenente tutti i costumi che saranno indossati con rispettive quantita'\n");
        printf("0) Uscita\n");

        printf("\nIntroduci la scelta: ");
        scelta=Leggi_numero();

        switch(scelta)
        {
        case 1:
                printf("\n1) CARICO LISTA INVITATI:\n");
                crealista(nome,cognome,eta,costume,invitatireali);
                vettorecarico=1;
                acapo();
                break;
        case 2:
                if(vettorecarico==0)
                {
                    novettore();
                    break;
                }
                printf("\n2) STAMPA LISTA INVITATI:\n");
                stampalista(nome,cognome,eta,costume,invitatireali);
                acapo();
                break;
        case 3:
                if(vettorecarico==0)
                {
                    novettore();
                    break;
                }
                printf("\n3) RICERCA NOMI ATTRAVERSO IL COSTUME: ");
                querycar=Leggi_lettera();
                querynomibycostume(nome,cognome,eta,costume,invitatireali,querycar);
                acapo();
                break;
        case 4:
                if(vettorecarico==0)
                {
                    novettore();
                    break;
                }
                printf("\n4) CALCOLO ETA' MEDIA ATTRAVERSO RICERCA REL. IL COSTUME: ");
                querycar=Leggi_lettera();
                etamediabycostume=calcoloetamediabycostume(nome,cognome,eta,costume,invitatireali,querycar);
                if(etamediabycostume==-100)
                    printf("\nNessun invitato veste il costume %c\n",querycar);
                else
                    printf("\nL'eta' media degli invitati con il costume %c e' %g\n",querycar,etamediabycostume);
                acapo();
                break;
        case 5:
                if(vettorecarico==0)
                {
                    novettore();
                    break;
                }
                printf("\n5) STAMPA DELLA FASCIA D'ETA' DEI PARTECIPANTI:");
                etaminima=minimo(eta,invitatireali);
                etamassima=massimo(eta,invitatireali);
                fasciadeta(etaminima,etamassima);
                acapo();
                break;
        case 6:
                if(vettorecarico==0)
                {
                    novettore();
                    break;
                }
                printf("\n6) IL PIU VECCHIO CON IL COSTUME:\nDigita la query: ");
                querycar=Leggi_lettera();
                piuvecchiowcostume (nome,cognome,eta,costume,invitatireali,querycar);
                acapo();
                break;
        case 7:
                if(vettorecarico==0)
                {
                    novettore();
                    break;
                }
                printf("\n7) RICERCA INVITATI PER NOME:\nDigita la query: ");
                querycar=Leggi_lettera();
                infoinvitato (nome,cognome,eta,costume,invitatireali,querycar);
                acapo();
                break;
        case 8:
                if(vettorecarico==0)
                {
                    novettore();
                    break;
                }
                printf("\n8) RIORDINAMENTO LISTA IN ORDINE ALFABETICO IN CORSO...");
                ordinaAlfabetoASC(nome,cognome,eta,costume,invitatireali);
                printf("\nFATTO\n");
                stampalista(nome,cognome,eta,costume,invitatireali);
                acapo();
                break;
        case 9:
                if(vettorecarico==0)
                {
                    novettore();
                    break;
                }
                printf("\n9) ELENCO CON TUTTI I COSTUMI PRESENTI ALLA FESTA E RISPETTIVE QUANTITA'");
                conta_costumi(costume,invitatireali);
                printf("\n");
                acapo();
                break;
        case 0:
                printf("Bye Bye");
                break;
        default:
                printf("Opzione Errata\n");

        }

    }
    return 0;
}
