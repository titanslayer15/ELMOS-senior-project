

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  // Serial.write("test");

  pinMode(15, OUTPUT);

  // digitalWrite(5, LOW);

  // digitalWrite(5, HIGH);

  // delay(3000);

  // digitalWrite(5, LOW);

  
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(15, LOW);

  delay(3000);

  digitalWrite(15, HIGH);

  delay(3000);

}
