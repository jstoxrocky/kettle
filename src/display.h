#pragma once
#include <ShiftRegister74HC595.h>

struct DisplayBytes {
  uint8_t left;
  uint8_t right;
};

DisplayBytes numberToBytes(uint8_t number);
