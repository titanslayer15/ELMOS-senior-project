#define TRANSMITTER_PIN 10
#define RECEIVER_PIN 11

// Define timing parameters
#define DELAY_TIME_US 1000 // Delay between transmitter and receiver
#define SAMPLE_TIME_US 100 // Time to sample the receiver

// Define data arrays
#define NUM_SAMPLES 1000


#define SAMPLE_TIME_INTERVAL_MICROSEC 100 // Delay between each sample

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
    s[i].voltage = analogRead(RECEIVER_PIN);
    
    i++;
  }

  return s;
}



void setup() {
  // put your setup code here, to run once:
  // Define pin numbers for transmitter and receiver

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
    voltages[i] = analogRead(RECEIVER_PIN);

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
  // put your main code here, to run repeatedly:
  
}
