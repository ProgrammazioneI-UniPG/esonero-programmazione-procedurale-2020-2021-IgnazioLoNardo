//Esonero Programmazione Procedurale Ignazio Lo Nardo
#include <stdio.h>
#include <stdlib.h>
#include <time.h>                  //setup per la chiave randomica
#include <string.h>               //usato per leggere la lunghezza delle stringhe

int main () {
  //array e char utilizzati durante il programma

  char PlainText[128];
  char Key[128];
  char CodedText[128];
  char DeCodedText[128];
  char RCodedText[128];      //Random Coded Text
  char RDeCodedText[128];   //Random DeCoded Text
  char RandomKey[128];
  char N[128];

  //int usati per lunghezze o scelte

  int PTlenght;
  int scelta1;
  int scelta2;
  int scelta3;

  //int usati come contatori per cicli for

  int l; //ciclo CodedText
  int d; //ciclo DeCodedText
  int b; //ciclo RCodedText
  int y; //ciclo RDeCodedText
  int n; //ciclo Randomizzatore
  int i; //ciclo Randomizzatore

  //setup per la generazione randomica della chiave

  time_t t;
  srand((unsigned) time(&t));

  //inizializzazione variabili

  scelta1=0;
  n=0;
  i=0;

  printf ("\nProgramma per codifica RC4\n");
  printf("----------------------------------------------------------------------------\n");

  printf("\nImmeti il testo da cifrare (max 128 caratteri)\n");
  fgets(PlainText, 128, stdin);
  PTlenght=strlen(PlainText);
  printf("\n");
  printf("Scegli se preferisci:\nInserire una chiave personalizzata inserendo 1\nCreare una chiave randomica inserendo 2\nScelta: ");

  while ( scelta1!=1 && scelta1!=2 ){     //Uso il ciclo while per far reinserire la scelta se non è un carattere valido
  scanf("%d", &scelta1);
  printf("\n");
  getchar();
  if (scelta1!=1 && scelta1!=2){
    printf("hai selezionato un carattere non valido per la scelta,inserirlo di nuovo\n");
  }
}

  if ( scelta1==1 ) {
  printf("Inserire una chiave di lunghezza maggiore o uguale al testo originale\n");
  fgets(Key, 128, stdin);
  while (strlen(Key)<strlen(PlainText)) {           //il ciclo while è usato per far reinserire la chiave se risulta troppo corta
    if (strlen(Key)< strlen(PlainText)) {printf("la chiave è troppo corta inserirne un altra\n");}
    fgets(Key, 128, stdin);
  }



  printf("\n");
  printf("Il testo cifrato è:\n");

  for (l=0; l<PTlenght; ++l)             //eseguo lo XOR
  {
  CodedText[l]=PlainText[l]^Key[l];
     }
     fwrite(CodedText, PTlenght,1,stdout); //utilizzo fwrite poichè printf verrebbe interrotto nel caso di uno XOR di 2 caratteri uguali che restituisce il carattere terminatore
     printf("\n");

     printf("Per rivedere il testo originale digitare 1, digitare qualsiasi altro carattere per chiudere il programma\n");
     scanf("%d", &scelta2);
     printf("\n");
     getchar();

     if ( scelta2==1 ){
       printf("il testo originale è:");
       for ( d=0; d<PTlenght; ++d )         //XOR per decodifica
     {
       DeCodedText[d]=CodedText[d]^Key[d];

     }
     fwrite(DeCodedText, PTlenght,1,stdout);  //stesso motivo di prima
     printf("\n");
     printf("\nOperazione completata\n");
   }
     else {
     printf("operazione completata\n");
   }
 }
    else {
    n++;

    for (n=1; n!=PTlenght; n++)            //ciclo for per generare caratteri casuali
     {
       N[i]=(rand() % 96 + 32);
       i++;
             }
    printf("la key generata randomicamente è:\n");
    strncpy(RandomKey, N , 128);          //utilizzo strncpy per trasformare l'array di valori randomici in una stringa di testo
    N[128] = '\0';
    printf("%s\n", RandomKey);

    for (b=0; b<PTlenght; b++) {          //XOR nel caso della chiave randomica
      RCodedText[b]= PlainText[b]^RandomKey[b];
    }
      printf("\nIl testo cifrato risulta:\n");
      fwrite(RCodedText, PTlenght,1,stdout);
      printf("\nPer rivedere il testo originale digitare 1, digitare qualsiasi altro carattere per chiudere il programma\n");
      scanf("%d", &scelta3);
      getchar();

      if ( scelta3==1 ){
        printf("\nil testo originale è:\n");
        for ( y=0; y<PTlenght; ++y )      //XOR per decodifica con chiave randomica
      {
        RDeCodedText[y]=RCodedText[y]^RandomKey[y];

      }
      fwrite(RDeCodedText, PTlenght,1,stdout);
      printf("\nOperazione completata\n");
    }
      else {
      printf("operazione completata\n");
    }

      }

   }
