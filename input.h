
enum Button {
  RIGHT,
  UP,
  DOWN,
  LEFT,
  SELECT,
  NONE,
};

void input_setup(void);

enum Button read_button(void);
