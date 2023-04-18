
#define TRANSMITTER_RELAY_PIN 10
#define RECEIVER_RELAY_PIN 11
#define BUTTON_PIN 12 // TEMP VALUE

#define VOLTAGE_INPUT_PIN 9

#define TRANSMITTER_ON_TIME 100 // Pulse length in microseconds 
#define RECORD_SOUNDING_TIME 8000 // Recording duration in microseconds

#define SAMPLE_TIME_INTERVAL_MICROSEC 100 // Delay between each sample in microseconds

struct sounding {
  unsigned long time;
  int voltage;
};

/*
sounding* recordSounding(unsigned long mu_s) {
  unsigned long t1 = micros();
  unsigned long t2 = t1 + mu_s;

  int numSamples = (int)(mu_s / SAMPLE_TIME_INTERVAL_MICROSEC) + 10;

  sounding s[numSamples];

  int i = 0;
  
  while (micros() < t2) {
    delayMicroseconds(SAMPLE_TIME_INTERVAL_MICROSEC);

    s[i].time = micros() - t1;
    s[i].voltage = analogRead(VOLTAGE_INPUT_PIN);
    
    i++;
  }
  
  return s;
}

void sendData(sounding s[]) {

  int len = sizeof(s) / sizeof(sounding);
  
  for (int i = 0; i < len; i++) {
    Serial.write(s[i].time);
    Serial.write(s[i].time>>4);
    Serial.write(s[i].time>>8);
    Serial.write(s[i].time>>12);
  
    Serial.write(s[i].voltage);
    Serial.write(s[i].voltage>>4);
    Serial.write(s[i].voltage>>8);
    Serial.write(s[i].voltage>>12);
  }
}
*/

void setup() {

  digitalWrite(TRANSMITTER_RELAY_PIN, LOW);
  digitalWrite(RECEIVER_RELAY_PIN, LOW);

  Serial.begin(9600);  
  /*  
  digitalWrite(TRANSMITTER_RELAY_PIN, HIGH);
  digitalWrite(TRANSMITTER_RELAY_PIN, LOW);

  delayMicroseconds(TRANSMITTER_ON_TIME);

  // Trigger relay OFF
  digitalWrite(TRANSMITTER_RELAY_PIN, HIGH);
  digitalWrite(TRANSMITTER_RELAY_PIN, LOW);
  */    
  
  // Record sounding
  unsigned long t1 = micros();
  unsigned long t2 = t1 + RECORD_SOUNDING_TIME;

  int numSamples = (int)(RECORD_SOUNDING_TIME / SAMPLE_TIME_INTERVAL_MICROSEC) + 10;

  sounding s[numSamples];

  int i = 0;
  
  while (micros() < t2) {
    delayMicroseconds(SAMPLE_TIME_INTERVAL_MICROSEC);

    s[i].time = micros() - t1;
    s[i].voltage = analogRead(VOLTAGE_INPUT_PIN);
    
    i++;
  }


  // Send data
  int len = sizeof(s) / sizeof(sounding);

  for (int i = 0; i < len; i++) {
    Serial.write(s[i].time);
    Serial.write(s[i].time>>4);
    Serial.write(s[i].time>>8);
    Serial.write(s[i].time>>12);
    
    Serial.write(s[i].voltage);
    Serial.write(s[i].voltage>>4);
    Serial.write(s[i].voltage>>8);
    Serial.write(s[i].voltage>>12);
  }
}

void loop() {

  // Holding the button will repeat TEM sounding measurements
  /* if (digitalRead(BUTTON_PIN) == LOW) { */

    // Trigger relay ON
  /* } */
}
