#include "LedBar.h"

void LedBar::begin(int pins[], int colorPins[])
{
    for (int i = 0; i < 3; i++)
    {
        _colorPins[i] = colorPins[i];
        pinMode(_colorPins[i], OUTPUT);
    }

    for (int i = 0; i < 8; i++)
    {
        _pins[i] = pins[i];
        pinMode(_pins[i], OUTPUT);
    }
    _timer = millis();
    _timer1 = millis();
}

void LedBar::setLed(int led, char color)
{
    for (int i = 0; i < 8; i++)
    {
        digitalWrite(i, HIGH);
    }
    digitalWrite(_pins[led], LOW);
    switch (color)
    {
    case 'R':
        digitalWrite(_colorPins[0], LOW);
        digitalWrite(_colorPins[1], HIGH);
        digitalWrite(_colorPins[2], HIGH);
        break;
    case 'G':
        digitalWrite(_colorPins[0], HIGH);
        digitalWrite(_colorPins[1], LOW);
        digitalWrite(_colorPins[2], HIGH);
        break;
    case 'B':
        digitalWrite(_colorPins[0], HIGH);
        digitalWrite(_colorPins[1], HIGH);
        digitalWrite(_colorPins[2], LOW);
        break;
    default:
        digitalWrite(_colorPins[0], HIGH);
        digitalWrite(_colorPins[1], HIGH);
        digitalWrite(_colorPins[2], HIGH);
        break;
    }
}

void LedBar::colorWave(int t)
{
    if (millis() - _timer >= t)
    {
        _currentLed++;
        if (_currentLed > 3)
        {
            _currentLed = 1;
        }
        _timer = millis();
    }
    if (_currentLed == 1)
    {
        digitalWrite(_colorPins[0], LOW);
        digitalWrite(_colorPins[1], HIGH);
        digitalWrite(_colorPins[2], HIGH);
    }
    else if (_currentLed == 2)
    {
        digitalWrite(_colorPins[0], HIGH);
        digitalWrite(_colorPins[1], LOW);
        digitalWrite(_colorPins[2], HIGH);
    }
    else
    {
        digitalWrite(_colorPins[0], HIGH);
        digitalWrite(_colorPins[1], HIGH);
        digitalWrite(_colorPins[2], LOW);
    }
}

void LedBar::runToRight(int t){
    if(millis()-_timer1 >= t){
        digitalWrite(_pins[_currentLedRun], LOW);
        digitalWrite(_pins[_currentLedRun-1], HIGH);
        _currentLedRun++;
        if(_currentLedRun > 7){
            _currentLedRun = 0;
        }
    }
}

void LedBar::runToLeft(int t){
    if(millis()-_timer1 >= t){
        digitalWrite(_pins[_currentLedRun], LOW);
        digitalWrite(_pins[_currentLedRun+1], HIGH);
        _currentLedRun--;
        if(_currentLedRun < 0){
            _currentLedRun = 7;
        }
    }
}
