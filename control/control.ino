
#define TRANSMITTER_RELAY_PIN 10
#define RECEIVER_RELAY_PIN 11
#define BUTTON_PIN 12 // TEMP VALUE

#define VOLTAGE_INPUT_PIN 10

#define TRANSMITTER_ON_TIME 100 // Pulse length in microseconds 
#define RECORD_SOUNDING_TIME 8000 // Recording duration in microseconds

#define SAMPLE_TIME_INTERVAL_MICROSEC 100 // Delay between each sample in microseconds

struct sounding {
  unsigned long time;
  int voltage;
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

  // TEST
  pinMode(54, OUTPUT);
  digitalWrite(54, HIGH);
  
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

  for (int j = 0; j < numSamples; j++) {

    Serial.print(s[j].time);
    Serial.write(" ");
    
    /*
    Serial.write(s[j].time);
    Serial.write(s[j].time>>4);
    Serial.write(s[j].time>>8);
    Serial.write(s[j].time>>12);
    
    Serial.write(s[j].voltage);
    Serial.write(s[j].voltage>>4);
    Serial.write(s[j].voltage>>8);
    Serial.write(s[j].voltage>>12);
    */
  }

  Serial.write("_");
}

void loop() {

  // Holding the button will repeat TEM sounding measurements
  /* if (digitalRead(BUTTON_PIN) == LOW) { */

    // Trigger relay ON
  /* } */
}
