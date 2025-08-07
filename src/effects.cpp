#include "effects.h"

void displayBytes(ShiftRegister74HC595<2>& sr, DisplayBytes bytes) {
  uint8_t arr[2] = { bytes.left, bytes.right };
  sr.setAll(arr);
}
