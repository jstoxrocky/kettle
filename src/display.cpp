#include "display.h"

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

DisplayBytes numberToBytes(uint8_t number) {
  DisplayBytes bytes;
  bytes.left = digits[(number / 10) % 10];
  bytes.right = digits[number % 10];
  return bytes;
}
