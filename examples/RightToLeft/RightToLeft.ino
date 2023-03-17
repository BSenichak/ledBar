#include <LedBar.h>

int pins[] = {2, 3, 4, 5, 6, 7, 8, 12};
int colorPins[] = {9, 10, 11};
LedBar led;


void setup() {
  led.begin(pins, colorPins);
}

void loop() {
  led.runToLeft(500);
}