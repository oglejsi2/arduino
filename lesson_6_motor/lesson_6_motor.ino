int rightForwardMotorPin = 5; /* bucika za desno naprej*/
int rightReverseMotorPin = 6; /* bucika za desno nazaj*/
int leftForwardMotorPin = 9; /*  bucika za levo naprej*/
int leftReverseMotorPin = 10; /* bucika za levo nazaj*/
int leftSpeed=150;
int rightSpeed=150;
unsigned int lineData[2];

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
   */

void setup() {
  // put your setup code here, to run once:

  // Ta koda deklarira pine motorja kot output pine
  pinMode(rightForwardMotorPin, OUTPUT);
  pinMode(rightReverseMotorPin, OUTPUT);
  pinMode(leftForwardMotorPin, OUTPUT);
  pinMode(leftReverseMotorPin, OUTPUT);
  Serial.begin(9600);  // Aktivira izpis na konzolo

  // 
}

void zavijLevo(int speed) {
      // put your main code here, to run repeatedly:
     analogWrite(rightForwardMotorPin, speed);        //  poženi motor
     delay(1000);                                     //  počakaj sekundo -> motor se bo vrtel pol sekunde
     analogWrite(rightForwardMotorPin,0);             //  postavi hitrost na 0 -> ustavi motor
     delay(1000);                                     //  počakaj sekundo -> sicer bi se pri klicu v loopu motor spet takoj zavrtel
}

void zavijDesno(int speed) {
      // put your main code here, to run repeatedly:
     analogWrite(leftForwardMotorPin, speed);        //  poženi motor
     delay(1000);                                     //  počakaj sekundo -> motor se bo vrtel pol sekunde
     analogWrite(leftForwardMotorPin,0);             //  postavi hitrost na 0 -> ustavi motor
     delay(1000);                                     //  počakaj sekundo -> sicer bi se pri klicu v loopu motor spet takoj zavrtel
}

void pojdiNaprej(int lspeed,int rspeed) {
      // put your main code here, to run repeatedly:
     analogWrite(rightForwardMotorPin, rspeed);
     analogWrite(leftForwardMotorPin,  lspeed);        //  poženi motor
     delay(1000);                                     //  počakaj sekundo -> motor se bo vrtel pol sekunde
     analogWrite(leftForwardMotorPin,0);             //  postavi hitrost na 0 -> ustavi motor
     analogWrite(rightForwardMotorPin, 0);
     delay(1000);                                     //  počakaj sekundo -> sicer bi se pri klicu v loopu motor spet takoj zavrtel
}

void pojdiNazaj(int lspeed,int rspeed) {
      // put your main code here, to run repeatedly:
     analogWrite(rightReverseMotorPin, rspeed);
     analogWrite(leftReverseMotorPin,  lspeed);        //  poženi motor
     delay(1000);                                     //  počakaj sekundo -> motor se bo vrtel pol sekunde
     analogWrite(leftReverseMotorPin,0);             //  postavi hitrost na 0 -> ustavi motor
     analogWrite(rightReverseMotorPin, 0);
     delay(1000);                                     //  počakaj sekundo -> sicer bi se pri klicu v loopu motor spet takoj zavrtel
}


void loop() {
    zavijLevo(leftSpeed);
    zavijDesno(rightSpeed);
    pojdiNaprej(leftSpeed, rightSpeed);
    pojdiNazaj(leftSpeed, rightSpeed);
}
