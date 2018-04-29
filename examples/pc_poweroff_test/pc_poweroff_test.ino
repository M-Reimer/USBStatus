#include "USBStatus.h"

const int PIN_GREEN_LED = 14;
const int PIN_RED_LED = 7;

void setup() {
  pinMode(PIN_GREEN_LED, OUTPUT);
  pinMode(PIN_RED_LED, OUTPUT);
}

void loop() {
  digitalWrite(PIN_GREEN_LED, USBStatus.isActive());
  digitalWrite(PIN_RED_LED, USBStatus.isShutDown());
}

