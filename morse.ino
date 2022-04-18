#include "lcd.h"
#include "scroll.h"

static Lcd screen;
static TimerScroll message("MESSAGE GOES HERE", 1000);

// Use \1 for dots, and \2 for dashes
static ButtonScroll morse("CLUE GOES HERE");

void setup(void) {
  // Make sure to re-initialize once the IO is ready
  screen = Lcd();
  screen.init_characters();
}


void loop(void) {
  message.tick();
  morse.tick();
  
  message.print(0, screen);
  morse.print(1, screen);

  screen.flush();
}
