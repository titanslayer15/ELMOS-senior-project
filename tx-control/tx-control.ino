#include <AD9850SPI.h>
#include <SPI.h>

const int W_CLK_PIN = 52;
const int FQ_UD_PIN = 48;
const int RESET_PIN = 49;

double freq = 80000;
double trimFreq = 124999000;

int phase = 0;

void setup(){
  DDS.begin(W_CLK_PIN, FQ_UD_PIN, RESET_PIN);
  DDS.calibrate(trimFreq);
  delay(1000);
  DDS.setfreq(freq, phase);



}

void loop() {
  delay(1000);    

}
