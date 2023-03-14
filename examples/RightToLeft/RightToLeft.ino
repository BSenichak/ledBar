#include <LedBar.h>

int pins[] = {2, 3, 4, 5, 6, 7, 8, 9};
int colorPins[] = {10, 11, 12};
LedBar led;


void setup() {
  led.begin(pins, colorPins);
}

void loop() {
  led.runToLeft(500);
}