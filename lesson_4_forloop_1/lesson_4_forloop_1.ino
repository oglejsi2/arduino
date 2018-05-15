#include <stdio.h>

char spremenljivkaVidnaPovsod[]="Pozdravljen";
int numLoops=0;
int ostanek;
int i=0;
int cnt=0;

void setup() {
  // tukaj vpiši kodo, ki se izvede samo enkrat
  /*
   * Kaj je spremenljivka?
   * V spremenljivko sharnimo vrednosti. Vrednosti so lahko različnih tipov:
   * char           shrani znake
   * int            shrani celo število od -2147483648 do 2147483647
   * unsigned int   shrani celo število od           0 do 4294967295
   * 
   * Poseben tip spremenljivke je array, v katerem so shranjeni nizi števil ali črk. primer je spremenljivkaVidnaPovsod. Array ima za imenom [] ali npr [5].
   * Če ima array za imenom oklepaj s številko (npr 5) potem pomeni, da gre za spremenljivko z dolžino označeno s številko (npr. 5)
   * 
    * 
   * Zanke (loops)
   * Ukazi znotraj zanke (loop) se ponavljajo dokler je pogoj resničen. 
   * while (true) {
   *    Serial.print("ok");
   * }
   * Ukazi znotraj for zanke se ponovijo za navedeno število korakov
   * for ( init; condition; increment ) {
   *   statement(s);
   * }
   * 
   * for ( int i=1; a<=10; 1 ) {
   *   statement(s);
   * }
   * 
   * Arduino za izpis uporablja conzolo na katero izpisuje z ukazom Serial.print, Arduino sicer podpira printf z lepim formatiranjem ampak ta izpisuje na ekran, ki ga Arduino nima.
   * Bypass je izpis preko formatiranega bufferja, ki ga potem podtakneš ukazu Serial.print
   *  char buffer [50];
      i=sprintf (buffer, "Vse je ok %d", numLoops);
   */

  /* Naloga 1:  V setup desetkrat izpiši "Vse je ok" 
     Naloga 2:  V loop desetkrat izpiši  "Vse je ok z zaporedno številko izvedbe" -> dodaj lepo formatiran izpis 
     Vse je ok 1
     Vse je ok 2
     ...
     Naloga 3:  
  */   
  
  Serial.begin(9600);  // Aktivira izpis na konzolo
for (int i=1; i<=10; i++){
  Serial.println(i);
 
  }

}


void loop() { 
      //tukaj vpiši ukaze, ki se ponavljajo
/*      
      cnt++;
      int a=5, b=3;
      char buffer [50];
      i=sprintf (buffer, "Vse je ok %d", cnt);
      for(int l= 0; l<=i; l++) 
        Serial.print(buffer[l]);
      Serial.println("");
      delay(5000);
      */
}

