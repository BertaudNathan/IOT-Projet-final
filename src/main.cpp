#include "irrigationSystem.h"

IrrigationSystem system;

void setup() {
  system = IrrigationSystem();
}

void loop() {
  system.irrigate();
  return;
}

