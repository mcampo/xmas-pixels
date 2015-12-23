#ifndef ANIMATIONS_H
#define ANIMATIONS_H

#include "Arduino.h"
#include <Adafruit_NeoPixel.h>

class NeoPixelAnimation {
  public:
    NeoPixelAnimation(Adafruit_NeoPixel *strip);
    virtual void nextFrame() = 0;
    void reset();

  protected:
    int frame;
    Adafruit_NeoPixel *strip;
};

uint32_t Wheel(byte WheelPos);


#endif
