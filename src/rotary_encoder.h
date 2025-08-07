#pragma once
#include <Arduino.h>

struct EncoderState {
  uint8_t clkPin;
  uint8_t dtPin;
  int lastClk;
  int counter;
  int min;
  int max;
};

EncoderState initEncoder(uint8_t clkPin, uint8_t dtPin, int initialValue, int minValue, int maxValue);
EncoderState updateEncoder(EncoderState state);
