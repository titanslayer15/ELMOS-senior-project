

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  // Serial.write("test");


  long time = micros();
  int voltage = 1000;

  // long time_buf[4] = {time[0], time[1], time[2], time[3]}

  /* String result = String(time + "," + voltage, DEC); */

  
  Serial.write(time);
  Serial.write(time>>4);
  Serial.write(time>>8);
  Serial.write(time>>12);
  
  Serial.write(voltage);
  Serial.write(voltage>>4);
  Serial.write(voltage>>8);
  Serial.write(voltage>>12);
  
}

void loop() {
  // put your main code here, to run repeatedly:
}
