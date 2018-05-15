char spremenljivkaVidnaPovsod[]="Pozdravljen";
int numLoops=0;

void setup() {
  // tukaj vpiši kodo, ki se izvede samo enkrat
  /*
   * Kaj je spremenljivka?
   * V spremenljivko sharnimo vrednosti. Vrednosti so lahko različnih tipov:
   * char           shrani znake
   * int            shrani celo število od -2147483648 do 2147483647
   * unsigned int   shrani celo število od           0 do 4294967295
   */
  
   char greeting[] = "Hello";

   Serial.begin(9600);  // Aktivira izpis na konzolo
   while (! Serial);
   Serial.print("greeting: "); Serial.println(greeting);   
   Serial.print("spremenljivkaVidnaPovsod : "); Serial.println(spremenljivkaVidnaPovsod);
}


void loop() {
  // koda vpisana tukaj se bo izvajala v neskončnost.
  
  numLoops++;
  // tukaj vpiši kodo, ki se izvede večkrat
  Serial.print("loop : "); 
  Serial.print(spremenljivkaVidnaPovsod);
  Serial.print("loop se je izvedel : "); 
  Serial.println(numLoops);
  //Serial.print(" loop : "); Serial.println(greeting);                  //Če tole odkomentiraš dobiš error 'greeting' was not declared in this scope, ker je greeting spremenljivka deklarirana v setup
  delay(5000);
}

