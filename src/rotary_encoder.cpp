#include "rotary_encoder.h"

EncoderState initEncoder(uint8_t clkPin, uint8_t dtPin, int initialValue, int minValue, int maxValue) {
  EncoderState state;
  state.lastClk = digitalRead(clkPin);
  state.counter = initialValue;
  state.min = minValue;
  state.max = maxValue;
  state.clkPin = clkPin;
  state.dtPin = dtPin;
  return state;
}

EncoderState updateEncoder(EncoderState state) {
  int currentClk = digitalRead(state.clkPin);
  if (currentClk != state.lastClk && currentClk == HIGH) {
    boolean turningClockwise = digitalRead(state.dtPin) != currentClk;
    if (turningClockwise) {
      state.counter = min(state.counter + 1, state.max);
    } else {
      state.counter = max(state.counter - 1, state.min);
    }
  }
  state.lastClk = currentClk;
  return state;
}
