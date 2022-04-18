# Morse hub

Firmware from my morse code display project. I'm not really a C++ programmer,
and I did this over two days, so try not to take too much inspiration from how
I put this together.

## What is it?

I put together a little treasure hunt for my sister's birthday, this was
designed to be one of the clues. The display has two rows: the first one just
displays a message that will scroll across the screen forever, and the second
one shows some morse code that you can scroll across the screen using the left
and right buttons built into the display.

## Hardware?

I plugged [one of these 2x16 character displays with some
buttons](https://www.jaycar.com.au/arduino-compatible-2-x-16-lcd-controller-module/p/XC4454)
directly into an [Arduino
Leonardo](https://www.arduino.cc/en/Main/Arduino_BoardLeonardo) because those
parts were in stock and I didn't need to deal with wires. In theory, you can
buy the same parts, plug them together and into your computer, and then run
"make" and it'll work. In practice, I make no guarantees.
