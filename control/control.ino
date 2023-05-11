
#define TRANSMITTER_RELAY_PIN 10
#define RECEIVER_RELAY_PIN 11
#define BUTTON_PIN 12 // TEMP VALUE

#define VOLTAGE_TX_INPUT_PIN A0
#define VOLTAGE_RX_INPUT_PIN A1

#define TRANSMITTER_ON_TIME 100 // Pulse length in microseconds 
#define RECORD_SOUNDING_TIME 8000 // Recording duration in microseconds

#define SAMPLE_TIME_INTERVAL_MICROSEC 100 // Delay between each sample in microseconds

struct sounding {
  unsigned long time;
  int voltageT;
  int voltageR;
};

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
  
  // delay(5000);

  // Record sounding
  unsigned long t1 = micros();
  unsigned long t2 = t1 + RECORD_SOUNDING_TIME;

  int numSamples = (int)(RECORD_SOUNDING_TIME / SAMPLE_TIME_INTERVAL_MICROSEC) + 10;

  sounding s[numSamples];

  int i = 0;
  
  while (micros() < t2) {
    delayMicroseconds(SAMPLE_TIME_INTERVAL_MICROSEC);

    s[i].time = micros() - t1;
    s[i].voltageT = analogRead(VOLTAGE_TX_INPUT_PIN);
    s[i].voltageR = analogRead(VOLTAGE_RX_INPUT_PIN);
    
    i++;
  }


  // Send data

  for (int j = 0; j < numSamples; j++) {

    Serial.write(s[j].time);
    Serial.write(s[j].time>>8);
    Serial.write(s[j].time>>16);
    Serial.write(s[j].time>>24);
    
    Serial.write(s[j].voltageT);
    Serial.write(s[j].voltageT>>8);

    Serial.write(s[j].voltageR);
    Serial.write(s[j].voltageR>>8);
  }

  Serial.write("_");
}

void loop() {

  // Holding the button will repeat TEM sounding measurements
  /* if (digitalRead(BUTTON_PIN) == LOW) { */

    // Trigger relay ON
  /* } */
}
