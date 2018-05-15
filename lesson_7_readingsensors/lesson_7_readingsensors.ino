#include <math.h> 

int leftSensorValue;
int rightSensorValue;
  
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
   *  
   *  
   *  Motor krmiliš preko pinov - bucik. Vklop pina zavrti motor. Dva pina krmilita levi motor (nazaj naprej) in dva pina desni motor (nazaj naprej)
    5         desno naprej
    6         desno nazaj
    9         levo naprej
    10        levo nazaj

      Motor prižgeš z ukazom analogWrite, ki ima dva parametra:
        motorPin  - pin motorja, ki ga želiš spremeniti
        speed     - hitrost motorja, ki je med 0 in 225

        primer:
        analogWrite(5, 150);      //  premakni desni motor naprej s hitrostjo 150 -> avto zavije v levo
        delay(500);               //  počakaj pol sekunde -> motor se bo vrtel pol sekunde
        analogWrite(5,0);         //  postavi hitrost na 0 -> ustavi motor

      Naloga: Naredi funkcije zavijLevo, zavijDesno, pojdiNaprej, pojdiNazaj in jih uporabi v loop zanki. Ne pozabi da vrtenje desnega motorja pomeni zavijLevo in obratno. 
              Motroji se lahko vrtijo z različno hitrostjo, zato za vsak motor uporabi svojo spremenljivko za hitrost. 
              S spreminjanme teh dveh spremenljivk boš lahko dosegel, da bo šel avto naravnost.



      Robot ima spredaj dva senzorja in med njima rdečo diodo. 
      Dioda je na pinu 7. Prižgi jo v setup-u, z naslednjim ukazom
        //Front led
        pinMode(7,OUTPUT);
        digitalWrite(7,HIGH); //FrontLED ON               
      Senzorja sta analogna in imata oznako A6 in A7. Vrednosti iz senzorja prebereš z naslednjim ukazom
        linedata0=analogRead(A6); //left linesensor 
        linedata1=analogRead(A7); //right linesensor 

      Naloga: Prižgi lučko in naredi funkcije: 
        1. readDataLeft
        2. readDataRight
        3. izpisiVrednosti z dvema parametroma. Enim za levi senzor in drugim za desni senzor
      Funkcije pokliči v loop-u, da izpišejo trenutne vrednosti na senzorju
   */

   
   int readDataLeft() {
      return analogRead(A6);
   }

   int readDataRight() {
      return round(analogRead(A7)*1.4);
   }
   
   void izpisiVrednosti(int pLeftValue, int pRightValue) {
      Serial.print(pLeftValue);
      Serial.print(" : ");
      Serial.println(pRightValue);
   }

void setup() {
  // put your setup code here, to run once:
  
  //Front led
  pinMode(7,OUTPUT);
  digitalWrite(7,HIGH); //FrontLED ON               
  Serial.begin(9600);  // Aktivira izpis na konzolo
}

void loop() {
  // put your main code here, to run repeatedly:


  leftSensorValue=readDataLeft();
  rightSensorValue=readDataRight();
  izpisiVrednosti(leftSensorValue, rightSensorValue);
  delay(3000);

}
