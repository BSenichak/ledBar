#ifndef LedBar_h
#define LedBar_h

#include <Arduino.h>

class LedBar {
  public:
    void begin(int pins[], int colorPins[]);
    void setLed(int led, char color);
    void colorWave(int t);
    void runToRight(int t);
    void runToLeft(int t);

  private:
    int _colorPins[3];
    int _pins[8];
    unsigned long _timer;
    unsigned long _timer1;
    int _currentLed = 1;
    int _currentLedRun = 0;
};

#endif
