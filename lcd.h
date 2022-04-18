#pragma once
#include <LiquidCrystal.h>

class Lcd {
  public:
    static const int WIDTH = 16, HEIGHT = 2;

    Lcd(void);

    void init_characters(void);

    void flush(void);

    void write(int x, int y, const char* message);
    
    LiquidCrystal lcd = LiquidCrystal(8, 9, 4, 5, 6, 7);
  private:
    char buffer[HEIGHT][WIDTH];
    // Is this a good name? No. But I needed a term for "buffer that isn't
    // currently reflecting what's on screen" and I remembered this term from
    // GPU programming
    char swapChain[HEIGHT][WIDTH];
};
