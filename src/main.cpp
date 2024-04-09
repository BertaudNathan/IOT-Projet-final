#include "irrigationSystem.h"
#include <Adafruit_Sensor.h>

IrrigationSystem mySystem;

void setup() {
  mySystem = IrrigationSystem();
}

void loop() {
  mySystem.irrigate();
  return;
}

