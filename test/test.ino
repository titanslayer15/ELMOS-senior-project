#define OUTPIN 54

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  // Serial.write("test");

  pinMode(OUTPIN, OUTPUT);

  // digitalWrite(5, LOW);

  // digitalWrite(5, HIGH);

  // delay(3000);

  // digitalWrite(5, LOW);

  
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(OUTPIN, LOW);
  /* analogWrite(9, LOW); */
  
  delay(1000);

  digitalWrite(OUTPIN, HIGH);
  /* analogWrite(9, HIGH); */
  
  delay(1000);

}
