#include "lcd.h"
#include "input.h"

class Scroll {
  public:
    Scroll(const char* message, bool loop);

    void print(int y, Lcd& screen);

    virtual void tick(void);

  protected:
    virtual int get_scroll(void);
    int length;
    const char* message;

  private:
    bool loop;
};

class TimerScroll: public Scroll {
  public:
    TimerScroll(const char* message, int frameRate);

    void tick(void) override;

  protected:
    int get_scroll(void) override;

  private:
    int frameRate;
    int lastTime;
    int scroll;
};

class ButtonScroll: public Scroll {
  public:
    ButtonScroll(const char* message);

    void tick(void) override;

  protected:
    int get_scroll(void) override;

  private:
    enum Button lastButton;
    int scroll;
};
