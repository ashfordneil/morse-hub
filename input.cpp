#include "input.h"
#include <Arduino.h>

const char INPUT_PIN = A0;

void input_setup(void) {
  pinMode(INPUT_PIN, INPUT);
}

enum Button read_button(void) {
  int k = analogRead(A0);
  if (k > 1000) {
    return NONE;
  } else if (k < 50) {
    return RIGHT;
  } else if (k < 195) {
    return UP;
  } else if (k < 380) {
    return DOWN;
  } else if (k < 555) {
    return LEFT;
  } else if (k < 790) {
    return SELECT;
  } else {
    // Fallback
    return NONE;
  }
}
