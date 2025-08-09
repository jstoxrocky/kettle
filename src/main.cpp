#include <Arduino.h>
#include <ShiftRegister74HC595.h>
#include <RotaryEncoder.h>
#include "shift_registry.h"
#include "rotary_encoder.h"

// Shift register pins
#define PIN_SR_DATA 11
#define PIN_SR_CLOCK 5
#define PIN_SR_LATCH 6

// Rotary encoder pins
#define PIN_ENC_CLOCK 2
#define PIN_ENC_DATA 3

ShiftRegister74HC595<2> sr(PIN_SR_DATA, PIN_SR_CLOCK, PIN_SR_LATCH);

// Choose latch mode to match your encoder detents.
// Try FOUR3 first; if counts feel doubled/halved, try FOUR0 or TWO03.
// Swap pin order if direction is backwards.
RotaryEncoder enc(PIN_ENC_DATA, PIN_ENC_CLOCK, RotaryEncoder::LatchMode::FOUR3);

void setup()
{
  pinMode(PIN_ENC_CLOCK, INPUT_PULLUP);
  pinMode(PIN_ENC_DATA, INPUT_PULLUP);

  useEncoderSetPosition(enc, 0);
  useShiftRegistryDisplayBytes(sr, numberToBytes(0));
}

void loop()
{
  // Get encoder position and clamp to 0-99
  int rawPos = useEncoderGetPosition(enc);
  int pos = clampPosition(rawPos, 0, 99);
  if (pos != rawPos)
  {
    useEncoderSetPosition(enc, pos);
  }

  // Update display if position changed
  static int lastShown = -1;
  if (pos != lastShown)
  {
    useShiftRegistryDisplayBytes(sr, numberToBytes(pos));
    lastShown = pos;
  }

  // Keep loop snappy so we don't miss steps
  delay(1);
}
