#include <Arduino.h>

// Include Emon Library
#include "EmonLib.h"
// Create an instance
EnergyMonitor emon;
int sensor = A0;

void setup()
{
  Serial.begin(115200);
  pinMode(sensor, INPUT);
  // Current: input pin, calibration. 1.2625
  emon.current(sensor, 1.2625);
}

void loop()
{
  // Calculate Irms only
  // Number of Samples : 4096
  double Irms = emon.calcIrms(4096);
  // Apparent power
  // Serial.print(Irms*230.0);
  Serial.print(Irms,3);
  Serial.println(" A");
  delay(1000);
}