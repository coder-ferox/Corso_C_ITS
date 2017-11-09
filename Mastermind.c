/**Gioco del Mastermind con supporto partita vs il pc
*  @AUTHOR Danilo Cappellino
*  @VERSION 2.0
*  @DATE 19/03/2017
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>

#define DIM 4
#define FALSE 0
#define TRUE 1

#define random(x) rand() % x
#define randomize srand((unsigned)time(NULL))

char Leggi_scelta();
char Maiuscolizza(char lettera);
char Leggi_colore();
void GeneratoreRandom(char cod[], int dim);
int ReadWord (char cod[], int dim, int segreto);
void CopiaVettore (char cod[],char codc[], int dim);
int O(char codc[],char tentc[], int dim);
int o(char codc[], char tentc[], int dim);

int main()
{
    char segreto[DIM];
    char segretoC[DIM];
    char word[DIM];
    char wordC[DIM];


    char scelta;
    int vite;
    int vittoria = FALSE;
    int corrispondenzeO = 0;
    int corrispondenzeo = 0;
    int tentativo = 0;


    printf("MASTERMIND Vers. 2.0\n\n1.\tGioca contro un umano\n2.\tGioca contro il PC\n0.\tEsci\n\nDigita la tua scelta: ");
    scelta=Leggi_scelta();

    if(scelta == '1'){
            printf("\n\nGioca contro un umano");
            printf("\n\nQuanti tentativi vuoi concedere ? ");
            scanf("%d",&vite);
            printf("\nDigita la combinazione segreta di 4 lettere [BGRV - bgrv]: ");
            ReadWord(segreto,DIM,1);
            CopiaVettore(segreto,segretoC,DIM);
    }
    else if(scelta=='2'){
            printf("\n\nGioca contro il PC:");
            printf("\n\nQuanti tentativi vuoi concedere ? ");
            scanf("%d",&vite);
            GeneratoreRandom(segreto,DIM);
            CopiaVettore(segreto,segretoC,DIM);
    }
    else if(scelta=='0'){
            printf("\n\nBye Bye\n");
            return 0;
    }
    else
        printf("\nErrore");


    while(vite>0 && vittoria != TRUE )
    {
    tentativo++;
    printf("\n\nIntroduci il tentativo %d: ",tentativo);
    ReadWord(word,DIM,0);
    CopiaVettore(word,wordC,DIM);
    printf("\t");
    corrispondenzeO=O(segretoC,wordC,DIM);
    corrispondenzeo=o(segretoC,wordC,DIM);
    CopiaVettore(segreto,segretoC,DIM);
    CopiaVettore(word,wordC,DIM);
    if(corrispondenzeO==0 && corrispondenzeo==0)
        printf("\nStai sbagliando tutto");
    if(corrispondenzeO==DIM) vittoria = TRUE;
    vite--;
    }


    if(vite==0 && vittoria == FALSE){
        printf("\n\nGnurant hai pers !\n\nLa parola segreta era: ");
        int i;
        for(i=0;i<DIM;i++)
            printf("%c",segreto[i]);
        printf("\n");
    }
    else
        printf("\n\nHAI VINTO !\n");
    printf("\n");
    system("pause");
    return 0;
}

/**Funzione che leggete un numero tra 0,1,2 ad uso nel menu di gioco
*  @RETURN (num) numero come carattere
*/

char Leggi_scelta(){
    char num;

    num=getch();
    while(num != '0' && num != '1' && num != '2')
  		num=getch();
  		printf("%c",num);

    return num;
 }

/**
 *Funzione che maiuscolizza una lettera se minuscola altrimenti lascia invariato il carattere
 *@PARAM lettera, qualsiasi lettera dell'alfabeto minuscola
 *@RETURN lettera, maiuscola corrispondente
 */

char Maiuscolizza(char lettera){
	int distanzaMinMau='a'-'A';

	if(lettera>='a' && lettera<='z')
		lettera=lettera-distanzaMinMau;

    return lettera;
 }

/**
 *Funzione che legge solo una delle 4 lettere previste consentendo l'invio
 *@RETURN lettera, il valore corrispondente alla lettera inserita
 */
char Leggi_colore(){
    char lettera;

    lettera=getch();
    while(lettera != 'B' && lettera != 'G' && lettera != 'R' && lettera != 'V' && lettera != 'b' && lettera != 'g' && lettera != 'r' && lettera != 'v' && lettera != 13)
  		lettera=getch();
    lettera=Maiuscolizza(lettera);

    return lettera;
 }

 /**Funzione che popola il vettore segreto con una serie di lettere scelte casualmente da un vettore di riferimento
 *  @PARAM (cod) vettore di caratteri che sarà riempito
 *  @PARAM (dim) dimensione del vettore cod
 *  @MODIFY (cod) verrà riempito con i caratteri del vettore di riferimento scelti casualmente
 */


 void GeneratoreRandom(char cod[], int dim){

    char rndmenu[DIM]={'B','G','R','V'}; //nel qual caso verrà aumentata la quantita DIM bisognerà aumentare il numero di lettere qui dentro
    int rndi;
    int rndround=dim;

    int cod_idx=0;

    printf("\nGenerazione della parola segreta in corso...");
    randomize;
    while(rndround>0)
        {
        rndi=random(dim);
        cod[cod_idx]=rndmenu[rndi];
        cod_idx++;
        rndround--;
        }

 }


 /**Funzione che legge (carica) un vettore cod con l'input (terminato con invio) restituendo la sua dimensione
 *  @PARAM (cod) vettore di caratteri da riempire
 *  @PARAM (dim) dimensione del vettore
 *  @PARAM (segreto), intero: se uguale a 1 restituisce a schermo un asterisco per ogni carattere digitato altrimenti stampa il carattere
 *  @MODIFY cod[], vettore con l'input inserito
 *  @RETURN (i) dimensione della frase
 */

int ReadWord (char cod[], int dim, int segreto) {
	int i;
	char lettera;


	lettera = Leggi_colore();
	for(i=0; i<dim && lettera != 13; i++) {
		cod[i] = lettera;
		if(segreto)
            printf("*");
        else
            printf("%c",lettera);
		lettera = Leggi_colore();
	}

    return i;
 }

 /**Funzione che copia il contenuto di un vettore in un altro
 *  @PARAM (cod) vettore di caratteri origine
 *  @PARAM (codc) vettore di caratteri di destinazione della copia
 *  @PARAM (dim) dimensione (sostanzialemente) del vettore d'origine
 *  @MODIFY (codc) viene riempito con gli stessi caratteri negli stessi indici di (cod)
 */

 void CopiaVettore (char cod[],char codc[], int dim)
 {
     int i;
     for(i=0;i<dim;i++)
        codc[i]=cod[i];
 }

/**Funzione che cerca all'interno dei vettori passati le corrispondenze dirette indice/carattere, ne riporta il risultato a schermo, ritorna il risultato delle corrispondenze, infine sanittizza il vettore per poter così passare alla funzione di ricerca successiva
*  @PARAM (codc) vettore di caratteri con il codice di riferimento
*  @PARAM (tentc) vettore di caratteri con il codice da controllare
*  @PARAM (dim) dimensione dei due vettori
*  @MODIFY (codc) ove vengono trovate delle corrispondenze con il carattere X
*  @MODIFY (tentc) ove vengono trovate delle corrispondenze con il carattere Y
*  @RETURN (trovati) valore intero che ritorna il punteggio relativo alle corrispondenze trovate
*/


 int O(char codc[],char tentc[], int dim)
{
    int i;
    int trovati=0;
    for(i=0;i<dim;i++)
        if(tentc[i] == codc[i])
        {
            printf("O ");
            codc[i] = 'X';
            tentc[i] = 'Y';
            trovati++;
        }


    return trovati;
}

/**Funzione che cerca all'interno dei vettori passati tutte le corrispondenze tra indici e caratteri, stampando a schermo quando ne trova qualcuna e ritornando il valore di quante ne ha trovate
*  @PARAM (codc) vettore di caratteri con codice di riferimento eventualmente modificato dalla funzione "O"
*  @PARAM (tentc) vettore di caratteri con il codice da controllare eventualmente modificato dalla funzione "O"
*  @PARAM (dim) dimensione dei due vettori
*  @RETURN (trovati) valore intero che ritorna il punteggio relativo alle corrispondenze trovate
*/

int o(char codc[], char tentc[], int dim)
{
    int i,j;
    int trovati=0;
    for(i=0;i<dim;i++)
        for(j=0;j<dim;j++)
            if(tentc[i]==codc[j])
                {
                    printf("o ");
                    trovati++;
                }
    printf("\n");
    return trovati;
}
