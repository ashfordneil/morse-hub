#include "scroll.h"
#include <string.h>
#include <Arduino.h>

Scroll::Scroll(const char* m, bool l) {
  message = m;
  loop = l;
  length = strlen(m);
}

void Scroll::print(int y, Lcd& screen) {
  int offset = get_scroll();
  if (offset < 0) {
    screen.write(-offset, y, message);
  } else if (offset < length) {
    screen.write(0, y, message + offset);
  }

  int writtenLength = length - abs(offset);
  if (loop) {
    screen.write(writtenLength, y, message);
  } else {
    if (writtenLength >= Lcd::WIDTH) {
      screen.write(Lcd::WIDTH - 1, y, ">");
    }

    if (offset > 0) {
      screen.write(0, y, "<");
    }
  }
}

TimerScroll::TimerScroll(const char* message, int fr) : Scroll(message, true) {
  frameRate = fr;
  lastTime = millis();
  scroll = 0;
}

void TimerScroll::tick(void) {
  int newTime = millis();
  int diff = newTime - lastTime;

  scroll += (diff / frameRate);
  lastTime = newTime - (diff % frameRate);

  if (scroll >= length) {
    scroll = 0;
  }
}

int TimerScroll::get_scroll(void) {
  return scroll;
}

ButtonScroll::ButtonScroll(const char* message) : Scroll(message, false) {
  lastButton = NONE;
  scroll = 0;
}

void ButtonScroll::tick(void) {
  enum Button pressed = read_button();
  if (pressed == lastButton) {
    return;
  }

  delay(5); // "debounce"
  enum Button confirm = read_button();
  if (confirm != pressed) {
    return;
  }

  switch (pressed) {
    case LEFT:
      scroll -= 1;
      break;
    case RIGHT:
      scroll += 1;
      break;
    default:
      break;
  }
  lastButton = pressed;
}

int ButtonScroll::get_scroll(void) {
  return scroll;
}
