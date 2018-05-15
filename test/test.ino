char buffer [50];
char sprem;
int  spremInt;
int  spremIntArray[50];

void setup() {
    Serial.begin(9600);  // Aktivira izpis na konzolo
  // put your setup code here, to run once:

  sprem='ab';
  buffer[0]='a';
  buffer[1]='b';
  buffer[2]='c';
  Serial.println(buffer);
  for (int i=0; i<=2; i++) {
    Serial.println(buffer[i]);
  }
  Serial.println(buffer[1]);
}

void loop() {
  // put your main code here, to run repeatedly:
  
}
