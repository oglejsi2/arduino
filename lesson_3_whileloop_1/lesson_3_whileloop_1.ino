char spremenljivkaVidnaPovsod[]="Pozdravljen";
int numLoops=0;
int ostanek;

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
   * Ukazi znotraj for zanke se ponovijo za navedeno število korakov
   * 
   */

  // Naloga: Izpisuj Tekst "Se delujem" dokler se loop ne ponovi 10-krat. Potem samo enkrat izpiši "Nehal sem delovati"

  int motorPin = 10; /* levo nazaj*/
  
 Serial.begin(9600);  // Aktivira izpis na konzolo

/*
    while (numLoops<=10) {
        Serial.print("Se delujem ");
        Serial.println(numLoops);
        numLoops++;
        delay(1000);
    }

    if (numLoops==11) {
      Serial.println("Prenehal sem delati");
    }

    numLoops++;  


*/


while (numLoops<=10){
  Serial.print("delam ");
  Serial.println(numLoops);
  numLoops++;
  delay(1000);
}
if (numLoops==11){
  Serial.println("ne delam");
}
}


void loop() { 
    
}



