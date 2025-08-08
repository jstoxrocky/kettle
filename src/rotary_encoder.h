#pragma once
#include <RotaryEncoder.h>

// Pure function to clamp a position to a range
int clampPosition(int rawPos, int minVal, int maxVal);

// Encoder side-effects
// 1) Tick the encoder (read pins) and return the current position snapshot
int useEncoderGetPosition(RotaryEncoder& enc);

// 2) Write a bounded/normalized position back into the encoder
void useEncoderSetPosition(RotaryEncoder& enc, int pos);
