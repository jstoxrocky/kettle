#include <Arduino.h>
#include <ShiftRegister74HC595.h>
#include "display.h"
#include "rotary_encoder.h"
#include "effects.h"

// Shift register pins
#define PIN_SR_DATA 11
#define PIN_SR_CLOCK 5
#define PIN_SR_LATCH 6

// Rotary encoder pins
#define ENCODER_CLK 2
#define ENCODER_DT 3

// Create shift register object
ShiftRegister74HC595<2> sr(PIN_SR_DATA, PIN_SR_CLOCK, PIN_SR_LATCH);

// Keep encoder state locally
EncoderState encoder;

void setup() {
  pinMode(ENCODER_CLK, INPUT);
  pinMode(ENCODER_DT, INPUT);

  int minValue = 0;
  int maxValue = 99;
  int initialValue = 0;

  // Initialize the encoder state
  encoder = initEncoder(ENCODER_CLK, ENCODER_DT, initialValue, minValue, maxValue);
  DisplayBytes bytes = numberToBytes(encoder.counter);
  
  // Side effects
  // 1. Display the updated number on the 7-segment display
  uint8_t arr[2] = { bytes.left, bytes.right };
  sr.setAll(arr);
}



void loop() {
  // Update the encoder state
  encoder = updateEncoder(encoder);
  DisplayBytes bytes = numberToBytes(encoder.counter);

  // Side effects
  // 1. Display the updated number on the 7-segment display
  displayBytes(sr, bytes);
  delay(2);
}
