/** Programma per la gestione di una tabella di studenti
* @AUTHOR Cappellino Danilo
* @VERSION 3.1
* @DATE 29/04/2017
*/

#include <iostream>

using namespace std;


const int MAX_ELEMENTS=30;

 struct Studente
    {
        int id;
        string cognome;
        string nome;
        int voto;
    };

    //prototipi
int Leggi_intero(int mi,int ma);
int caricaTabella(Studente vet[], int dim);
void stampaStudenti(Studente vet[], int dim);
void ordinaTabellaAlfabetico(Studente vet[], int dim);
void ordinaTabellaVoti(Studente vet[], int dim);
void votoPeggiore(Studente vet[], int dim);
void votoMigliore(Studente vet[], int totale);
void cercaStudente(Studente vet[], int dim, string cognome);
void aggiungiStudente(Studente vet[], int *totale);
void modificaStudente(Studente v[], int totale, int id);
void cancellaStudente(Studente vet[], int *dim, int queryid);

int main()
{

   Studente tabella[MAX_ELEMENTS];
   int quanti,scelta,totale=0,queryn;
   string query;

   cout<<"Quanti studenti ci sono ? ";
   quanti=Leggi_intero(1,MAX_ELEMENTS);

   totale=caricaTabella(tabella,quanti);
   cout<<"\nHai caricato "<<totale<<" studenti\n";

   scelta=1;
    while(scelta!=0)
    {
         cout<<"\nMENU:\n\n1.Stampa\n";
         cout<<"2.Voto peggiore\n";
         cout<<"3.Voto migliore\n";
         cout<<"4.Ordine alfabetico tabella\n";
         cout<<"5.Ordina per voto\n";
         cout<<"6.Ricerca per cognome\n";
         cout<<"7.Aggiungi un altro studente\n";
         cout<<"8.Modifica studente\n";
         cout<<"9.Cancella studente\n";
         cout<<"0.Uscita\n";

         cout<<"Inserisci scelta: ";
         cin>>scelta;

         switch(scelta)
         {
              case 1:
                   cout<<"\nLISTA STUDENTI\n\n";
                   stampaStudenti(tabella,totale);
                   cout<<"\n";
                   break;
              case 2:
                   cout<<"\nVOTO PEGGIORE:\n\n";
                   ordinaTabellaVoti(tabella,totale);
                   votoPeggiore(tabella,totale);
                   cout<<"\n";
                   break;
              case 3:
                   cout<<"\nVOTO MIGLIORE:\n\n";
                   ordinaTabellaVoti(tabella,totale);
                   votoMigliore(tabella,totale);
                   cout<<"\n";
                   break;
              case 4:
                   cout<<"\nORDINE ALFABETICO\n\n";
                   ordinaTabellaAlfabetico(tabella,totale);
                   stampaStudenti(tabella,totale);
                   cout<<"\n";
                   break;
              case 5:
                   cout<<"\nORDINE PER VOTO CRESCENTE\n\n";
                   ordinaTabellaVoti(tabella,totale);
                   stampaStudenti(tabella,totale);
                   cout<<"\n";
                   break;
              case 6:
                   cout<<"\nRICERCA STUDENTI\n\nIns. cognome: ";
                   cin>>query;
                   cercaStudente(tabella,totale,query);
                   cout<<"\n";
                   break;
              case 7:
                   cout<<"\nAGGIUNGI STUDENTE\n";
                   if(totale<=MAX_ELEMENTS)
                     aggiungiStudente(tabella,&totale);
                   else
                     cout<<"\nFerma tutto, la lista è piena\n";
                   cout<<"\n";
                   break;
              case 8:
                   cout<<"\nMODIFICA STUDENTE\n\nIns. ID: ";
                   cin>>queryn;
                   modificaStudente(tabella,totale,queryn);
                   cout<<"\n";
                   break;
              case 9:
                   cout<<"\nCANCELLA STUDENTE\n\nIns. ID: ";
                   cin>>queryn;
                   cancellaStudente(tabella,&totale,queryn);
                   cout<<"\n";
                   break;
              case 0:
                   return 0;
              default:
                   cout<<"\nScelta sbagliata\n";


         }

    }

    return(0);
}

/**Funzione che legge un numero intero compreso tra due valori minimo e massimo
* @PARAM valmin (int) valore minimo
* @PARAM valmax (int) valore massimo
* @RETURN n (int) valore digitato
*/

int Leggi_intero(int valmin,int valmax)
{
  int n;

  cin>>n;
  while(n<valmin || n>valmax)
  {
     if(n<valmin)
     {
     cout<<"Numero troppo basso, reinseriscilo: ";
     cin>>n;
     }
     else
     {
     cout<<"Numero troppo alto (max "<<MAX_ELEMENTS<<"), reinseriscilo: ";
     cin>>n;
     }
  }

  return(n);
}

/**Funzione che carica il un vettore con i dati della struct studente
* @PARAM v[] (Studente) vettore di struct
* @PARAM dim (int) dimensione del vettore
* @MODIFY v[] viene riempito con i dati inseriti
* @RETURN totale (int) totale reale degli studenti inseriti
*/

int caricaTabella(Studente v[], int dim)
{
    int i,totale=0;

    for(i=0;i<dim;i++)
         {

         v[i].id=i+1;
         cout<<"\nInserisci cognome dello studente che avra' ID "<<v[i].id<<": ";
         cin>>v[i].cognome;

         cout<<"\nInserisci nome dello studente che avra' ID "<<v[i].id<<": ";
         cin>>v[i].nome;

         cout<<"\nInserisci il voto di "<<v[i].cognome<<" "<<v[i].nome<<": ";
         v[i].voto=Leggi_intero(1,30);


         cout<<"\nID di "<<v[i].cognome<<" "<<v[i].nome<<" e' "<<v[i].id<<"\n";
         totale++;
         }
    return totale;
}

/**Funzione che stampa la lista delle struct di studenti con id, cognome, nome e voto
* @PARAM vet[] (Studente) vettore delle struct
* @PARAM dim (int) dimensione del vettore
*/

void stampaStudenti(Studente vet[], int dim)
{
     int i,cont=0;

     for(i=0;i<dim;i++)
     if(vet[i].id!=0){
         cout<<vet[i].id<<" - "<<vet[i].cognome<<" "<<vet[i].nome<<" ~ "<<vet[i].voto<<"/30\n";
         cont++;
        }
     cout<<"\nAbbiamo "<<cont<<" studenti attivi\n";
}

/**Funzione che riordina in ordine alfabetico il vettore delle struct di Studenti
* @PARAM vet[] (Studente) vettore delle struct
* @PARAM dim (int) dimensione del vettore
*/

void ordinaTabellaAlfabetico(Studente vet[], int dim)
{
    int i,j;
    Studente tmp;

    for (i=0;i<dim-1;i++){
     for(j=dim-1;j>i;j--)
        if (vet[j-1].cognome>vet[j].cognome) //cambiare questa condizione per invertire l'ordine
            {
              tmp = vet[j-1];
              vet[j-1] = vet[j];
              vet[j] = tmp;
            }}

}

/**Funzione che riordina in ordine crescente di voto il vettore delle struct di Studenti
* @PARAM vet[] (Studente) vettore delle struct
* @PARAM dim (int) dimensione del vettore
*/

void ordinaTabellaVoti(Studente vet[], int dim)
{
    int i,j;
    Studente tmp;

    for (i=0;i<dim-1;i++){
     for(j=dim-1;j>i;j--)
        if (vet[j-1].voto>vet[j].voto) //cambiare questa condizione per invertire l'ordine
            {
              tmp = vet[j-1];
              vet[j-1] = vet[j];
              vet[j] = tmp;
            }}
}

/**Funzione che riporta il voto peggiore della classe
* @PARAM vet[] (Studente) vettore delle struct
* @PARAM dim (int) dimensione del vettore
*/

void votoPeggiore(Studente vet[], int dim)
{
    cout<<vet[0].cognome<<" ha il voto peggiore: "<<vet[0].voto<<"\n";
}

/**Funzione che riporta il voto migliore della classe
* @PARAM vet[] (Studente) vettore delle struct
* @PARAM dim (int) dimensione del vettore
*/

void votoMigliore(Studente vet[], int totale)
{
    cout<<vet[totale-1].cognome<<" ha il voto migliore: "<<vet[totale-1].voto<<"\n";
}

/**Funzione che ricerca lo studente per cognome dato
* @PARAM vet[] (Studente) vettore delle struct
* @PARAM dim (int) dimensione del vettore
* @PARAM cognome (string) query da ricercare
*/

void cercaStudente(Studente vet[], int dim, string cognome)
{
    int i,trovato=0;
    for(i=0;i<dim;i++){
        if(cognome == vet[i].cognome)
        {
            cout<<"\n"<<vet[i].id<<" - "<<vet[i].cognome<<" "<<vet[i].nome<<" ~ "<<vet[i].voto;
            trovato=1;
        }
    }
        if(trovato==0)
            cout<<"\nNon c'e' nessuno studente con il cognome "<<cognome<<"\n";
}

/**Funzione che permette di aggiungere in un secondo tempo un altro studente
* @PARAM v[] (Studente) vettore delle struct
* @PARAM *totale (int) dimensione del vettore passato per riferimento
* @MODIFY v[] aggiungendo una nuova entry
* @MODIFY *totale aggiornando il numero totale degli studenti
*/

void aggiungiStudente(Studente v[], int *totale)
{

    int i=*totale;

    v[i].id=i+1;
    cout<<"\nInserisci cognome dello studente che avra' ID "<<v[i].id<<": ";
    cin>>v[i].cognome;

    cout<<"\nInserisci nome dello studente che avra' ID "<<v[i].id<<": ";
    cin>>v[i].nome;

    cout<<"\nInserisci il voto di "<<v[i].cognome<<" "<<v[i].nome<<": ";
    v[i].voto=Leggi_intero(1,30);


    cout<<"\nID di "<<v[i].cognome<<" "<<v[i].nome<<" e' "<<v[i].id<<"\n";
    *totale=v[i].id;
    cout<<"\nAdesso ci sono in tutto "<<*totale<<" studenti\n";



}

/**Funzione che permette di modificare uno studente inserito
* @PARAM vet[] (Studente) vettore delle struct
* @PARAM dim (int) dimensione del vettore
* @PARAM queryid (int) id da ricercare
* @MODIFY vet[] cambiando a scelta i valori della struct legata al id
*/

void modificaStudente(Studente vet[], int dim, int queryid)
{
    int i,trovato=0,cosamodifico=1;
    for(i=0;i<dim;i++){
        if(queryid == vet[i].id)
        {

            trovato=1;
            while(cosamodifico!=0)
            {
                cout<<"\n"<<vet[i].id<<" - "<<vet[i].cognome<<" "<<vet[i].nome<<" ~ "<<vet[i].voto<<"\n";
                cout<<"\nCOSA MODIFICO:\n";
                cout<<"1.Cognome\n";
                cout<<"2.Nome\n";
                cout<<"3.Voto\n";
                cout<<"0.Finito\n";

                cout<<"Inserisci scelta: ";
                cin>>cosamodifico;

                switch(cosamodifico)
                {
                    case 1:
                        cout<<"\nScrivi il nuovo cognome: ";
                        cin>>vet[i].cognome;
                        cout<<"\nIl nuovo cognome e': "<<vet[i].cognome<<"\n";
                        break;
                    case 2:
                        cout<<"\nScrivi il nuovo nome: ";
                        cin>>vet[i].nome;
                        cout<<"\nIl nuovo nome e': "<<vet[i].nome<<"\n";
                        break;
                    case 3:
                        cout<<"\nScrivi il nuovo voto: ";
                        vet[i].voto=Leggi_intero(1,30);
                        cout<<"\nIl nuovo voto e': "<<vet[i].voto<<"\n";
                        break;
                    case 0:
                        break;

                }
            }
        }
    }
        if(trovato==0)
            cout<<"\nNon c'e' nessuno studente con ID "<<queryid<<"\n";
}

/**Funzione che permette di cancellare uno studente
* @PARAM vet[] (Studente) vettore delle struct
* @PARAM *dim (int) dimensione del vettore passato per riferimento
* @PARAM queryid (int) dimensione del vettore passato per riferimento
* @MODIFY v[] rimuovendo il record
* @MODIFY *dim riducendolo di valore
*/

void cancellaStudente(Studente vet[], int *dim, int queryid)
{
    int i,trovato=0;
    for(i=0;i<*dim;i++){
        if(queryid == vet[i].id)
        {
            trovato=1;
            cout<<"\n"<<vet[i].id<<" - "<<vet[i].cognome<<" "<<vet[i].nome<<" --> CANCELLATO\n";
            vet[i].id=0;
            vet[i].cognome="";
            vet[i].nome="";
            vet[i].voto=0;
            //*dim=*dim-1;
            //cout<<"\nAbbiamo perso uno studente, adesso siamo a "<<*dim<<" studenti\n";;

        }
    }
        if(trovato==0)
            cout<<"\nNon c'e' nessuno studente con ID "<<queryid<<"\n";
}

