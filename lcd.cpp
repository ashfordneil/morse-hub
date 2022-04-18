#include "lcd.h"
#include <string.h>

Lcd::Lcd(void) {
  lcd.begin(WIDTH, HEIGHT);
  lcd.clear();

  memset(buffer, ' ', sizeof(buffer));
  memset(swapChain, ' ', sizeof(swapChain));
}

void Lcd::init_characters(void) {
  char DOT_MATRIX[8] = {
    0b00000,
    0b00000,
    0b00000,
    0b00000,
    0b00100,
    0b00000,
    0b00000,
    0b00000,
  };

  char DASH_MATRIX[8] = {
    0b00000,
    0b00000,
    0b00000,
    0b00000,
    0b11111,
    0b00000,
    0b00000,
    0b00000,
  };

  lcd.createChar(1, DOT_MATRIX);
  lcd.createChar(2, DASH_MATRIX);
}

void Lcd::flush(void) {
  for (int y = 0; y < HEIGHT; y++) {
    bool isCursorSet = false;
    for (int x = 0; x < WIDTH; x++) {
      if (swapChain[y][x] != buffer[y][x]) { // We need to draw something
	if (!isCursorSet) {
	  lcd.setCursor(x, y);
	  isCursorSet = true;
	}

	buffer[y][x] = swapChain[y][x];
	lcd.write(buffer[y][x]);
      } else {
	isCursorSet = false;
      }
    }
  }

  memset(swapChain, ' ', sizeof(swapChain));
}

void Lcd::write(int x, int y, const char* message) {
  while (x < WIDTH && *message) {
    swapChain[y][x] = *message;

    x++;
    message++;
  }
}
