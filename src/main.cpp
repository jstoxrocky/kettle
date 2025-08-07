#include <Arduino.h>
#include "display.h"

void setup() {
  // displayNumber(44);
}

void loop() {
  for (int i = 0; i < 100; i++) {
    displayNumber(i);
    delay(500);
  }
}
