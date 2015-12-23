#ifndef THEATERCHASE_ANIMATION_H
#define THEATERCHASE_ANIMATION_H

#include "animations.h"

class TheaterChaseAnimation : public NeoPixelAnimation {

  public:
    TheaterChaseAnimation(Adafruit_NeoPixel *strip);
    TheaterChaseAnimation(Adafruit_NeoPixel *strip, uint8_t r, uint8_t g, uint8_t b);
    void nextFrame();
    void setColor(uint8_t r, uint8_t g, uint8_t b);

  private:
    uint8_t r, g, b;
};

#endif
