#include "rotary_encoder.h"

int clampPosition(int rawPos, int minVal, int maxVal)
{
  if (rawPos < minVal)
    return minVal;
  if (rawPos > maxVal)
    return maxVal;
  return rawPos;
}

int useEncoderGetPosition(RotaryEncoder& enc)
{
  enc.tick();
  return enc.getPosition();
}

void useEncoderSetPosition(RotaryEncoder& enc, int pos) { enc.setPosition(pos); }