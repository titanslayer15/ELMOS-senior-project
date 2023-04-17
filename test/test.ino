

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  // Serial.write("test");


  unsigned long time = micros();
  int voltage = 1000;

  /* String result = String(time + "," + voltage, DEC); */

  
  Serial.write(time);
  // Serial.write(voltage);
  
}

void loop() {
  // put your main code here, to run repeatedly:
}
