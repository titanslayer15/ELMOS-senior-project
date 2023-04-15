
#define TRANSMITTER_RELAY_PIN 10
#define RECEIVER_RELAY_PIN 11
#define BUTTON_PIN 12 // TEMP VALUE

// TEMP VALUES
#define TRANSMITTER_ON_TIME 100 // Pulse length in microseconds 
#define RECORD_SOUNDING_TIME 100 // Recording duration in microseconds

#define SAMPLE_TIME_INTERVAL_MICROSEC 100 // Delay between each sample in microseconds

struct sounding {
  unsigned long time;
  int voltage;
};

sounding* recordSounding(unsigned long mu_s) {
  unsigned long t1 = micros();
  unsigned long t2 = micros() + mu_s;

  int numSamples = (int)(mu_s / SAMPLE_TIME_INTERVAL_MICROSEC) + 10;

  sounding s[numSamples];

  int i = 0;
  
  while (micros() < t2) {
    delayMicroseconds(SAMPLE_TIME_INTERVAL_MICROSEC);

    s[i].time = micros() - t1;
    s[i].voltage = analogRead(RECEIVER_RELAY_PIN);
    
    i++;
  }

  return s;
}

sounding* executeTEM() {

  // Trigger relay ON
  digitalWrite(TRANSMITTER_RELAY_PIN, HIGH);
  digitalWrite(TRANSMITTER_RELAY_PIN, LOW);

  delayMicroseconds(TRANSMITTER_ON_TIME);

  // Trigger relay OFF
  digitalWrite(TRANSMITTER_RELAY_PIN, HIGH);
  digitalWrite(TRANSMITTER_RELAY_PIN, LOW);

  return recordSounding(RECORD_SOUNDING_TIME);
}


void setup() {
  // put your setup code here, to run once:
  // Define pin numbers for transmitter and receiver

  digitalWrite(TRANSMITTER_RELAY_PIN, LOW);
  digitalWrite(RECEIVER_RELAY_PIN, LOW);
  
  
  
  /*
  double times[NUM_SAMPLES];
  double voltages[NUM_SAMPLES];

  // Conduct TEM survey
  for (int i = 0; i < NUM_SAMPLES; i++) {
    // Turn on transmitter
    digitalWrite(TRANSMITTER_PIN, HIGH);

    // Wait for delay time
    delayMicroseconds(DELAY_TIME_US);

    // Read receiver voltage
    voltages[i] = analogRead(RECEIVER_RELAY_PIN);

    // Record time
    times[i] = (double)i * SAMPLE_TIME_US;

    // Turn off transmitter
    digitalWrite(TRANSMITTER_PIN, LOW);

    // Wait for sample time
    delayMicroseconds(SAMPLE_TIME_US);
  }
  */

}

void loop() {

  if (digitalRead(BUTTON_PIN) == LOW) {
    executeTEM();
  }
}
