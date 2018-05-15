char spremenljivkaVidnaPovsod[]="Pozdravljen";
int numLoops=0;
int ostanek=1;

void setup() {
  // tukaj vpiši kodo, ki se izvede samo enkrat
  /*
   * Kaj je spremenljivka?
   * V spremenljivko sharnimo vrednosti. Vrednosti so lahko različnih tipov:
   * char           shrani znake
   * int            shrani celo število od -2147483648 do 2147483647
   * unsigned int   shrani celo število od           0 do 4294967295
   * 
   * if (ostanek==0) {
   *  izpiši Lep pozdrav. Izvedel sem se za mnogokratnik števila pet
   * }
   * else
   *  izpiši ...
   * end if
   */

  // Naloga: Če se je loop izvedel petkrat ali za mnogokratnik števila 5 potem izpiši "Lep pozdrav. Izvedel sem se za mnogokratnik števila pet". Če se loop ni izvedel petkrat izpiši ...
  Serial.begin(9600);
  Serial.println("setup");
}




void loop(){
 numLoops=numLoops+1;
 ostanek=numLoops % 5;
 Serial.println(ostanek);

  if (ostanek==0){
  Serial.println("V redu");
  }
  else  {
    Serial.println("Ni v redu");
  }

  delay(2000);
}

