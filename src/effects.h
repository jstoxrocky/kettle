#pragma once
#include <ShiftRegister74HC595.h>
#include "display.h"

void displayBytes(ShiftRegister74HC595<2>& sr, DisplayBytes bytes);
