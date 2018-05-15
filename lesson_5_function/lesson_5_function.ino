  int globalMaxStevilo;

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
   * for ( int a=; condition; increment ) {
   *   statement(s);
   * }
   * 
   * Arduino za izpis uporablja conzolo na katero izpisuje z ukazom Serial.print, Arduino sicer podpira printf z lepim formatiranjem ampak ta izpisuje na ekran, ki ga Arduino nima.
   * Bypass je izpis preko formatiranega bufferja, ki ga potem podtakneš ukazu Serial.print
   *  char buffer [50];
      i=sprintf (buffer, "Vse je ok %d", cnt);
   */

  /* Naloga 1:  V setup desetkrat izpiši "Vse je ok" 
     Naloga 2:  V loop desetkrat izpiši  "Vse je ok z zaporedno številko izvedbe" -> dodaj lepo formatiran izpis 
     Vse je ok 1
     Vse je ok 2
     ...
     Naloga 3:  
  */   

  /*
   * Včasih je program prevelik, da bi ga v celoti napisal v loop, ali pa bi lahko dele programa uporabili večkrat. V takšnih primerih delčke programa opredelimo kot funkcije.  
   *  return_type function_name( parameter list ) {
   *    body of the function
   *  }
   *  
   *  int sestej(int prviParamter, int drugiParameter ) {
   *    int sestevek;
   *    sestevek=prviParameter + drugiParameter;
   *    
   *    return sestevek;    
   *  }
   *  
   *  Naloga 1: Naredi funkcijo maxNumber, ki ima dva parametra. Funkcija vrne večje število. Funkcijo pokliči v setup
   */

int maxNumber (int prvoStevilo, int drugoStevilo) {
  int maxStevilo;
  if (prvoStevilo>drugoStevilo) {
    maxStevilo=prvoStevilo;
  }
  else {
    maxStevilo=drugoStevilo;
  }
  return maxStevilo;
}

void setup() {
  Serial.begin(9600);  // Aktivira izpis na konzolo
  globalMaxStevilo=maxNumber(5,3);
  Serial.println(globalMaxStevilo);
}

void loop() {
  // put your main code here, to run repeatedly:
  
}
