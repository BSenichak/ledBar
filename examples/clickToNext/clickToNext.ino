#include <LedBar.h>

int pins[] = {2, 3, 4, 5, 6, 7, 8, 12};
int colorPins[] = {9, 10, 11};
LedBar ledbar;

int pin = 0;
int c = 0;
char color = 'R';

void setup() {
  ledbar.begin(pins, colorPins);
  pinMode(13, INPUT);
  pinMode(1, INPUT);
}

void loop() {
  if(digitalRead(13)){
    pin++;
    if(pin > 7) pin = 0;
    delay(200);
  }
  if(analogRead(0)>512){
    c++;
    if(c > 2) c = 0;
    delay(200);
    if(c == 0) color = 'R';
    if(c == 1) color = 'G';
    if(c == 2) color = 'B';
  }
    ledbar.setLed(pin, color);
}