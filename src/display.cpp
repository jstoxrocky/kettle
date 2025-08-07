#include <Arduino.h>
#include <ShiftRegister74HC595.h>
#include "display.h"

// Your pin definitions and shift register object
#define DATA 11
#define CLOCK 5
#define LATCH 6

ShiftRegister74HC595<2> sr(DATA, CLOCK, LATCH);

// Segment patterns for common anode 7-segment display
const uint8_t digits[10] = {
  B11000000, // 0
  B11111001, // 1
  B10100100, // 2
  B10110000, // 3
  B10011001, // 4
  B10010010, // 5
  B10000010, // 6
  B11111000, // 7
  B10000000, // 8
  B10010000  // 9
};

void displayTwoDigits(uint8_t leftDigit, uint8_t rightDigit) {
  uint8_t displayBytes[2] = {
    digits[leftDigit],   // ← first = left digit now
    digits[rightDigit]   // ← second = right digit
  };
  sr.setAll(displayBytes);
}

void displayNumber(uint8_t number) {
  uint8_t left = (number / 10) % 10;
  uint8_t right = number % 10;
  displayTwoDigits(left, right);
}
