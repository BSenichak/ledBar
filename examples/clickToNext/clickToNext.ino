#include <LedBar.h>

int pins[] = {2, 3, 4, 5, 6, 7, 8, 9};
int colorPins[] = {10, 11, 12};
LedBar led;
int led = 0;

void setup() {
  led.begin(pins, colorPins);
  pinMode(13, INPUT);
}

void loop() {
 if(digitalRead(2)){
    led.setLed(led, 'R');
    led++;
    delay(200);
 }
}