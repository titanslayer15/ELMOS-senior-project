#define OUTPIN 54
#define VOLTAGE_INPUT_PIN 10

uint16_t v;
unsigned long t;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  // Serial.write("test");

  pinMode(OUTPIN, OUTPUT);

  pinMode(VOLTAGE_INPUT_PIN, INPUT);
  
  // digitalWrite(5, LOW);

  // digitalWrite(5, HIGH);

  // delay(3000);

  // digitalWrite(5, LOW);

}

void loop() {

  t = micros();
  v = analogRead(A0);
  
  Serial.write(t);
  Serial.write(t>>8);
  Serial.write(t>>16);
  Serial.write(t>>24);

  Serial.write(v);
  Serial.write(v>>8);
  
  /* delayMicroseconds(1000); */
  delay(1000);
}
