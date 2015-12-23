#ifndef FADE_ANIMATION_H
#define FADE_ANIMATION_H

#include "animations.h"

class FadeAnimation : public NeoPixelAnimation {
  public:
    FadeAnimation(Adafruit_NeoPixel *strip);
    FadeAnimation(Adafruit_NeoPixel *strip, uint8_t r, uint8_t g, uint8_t b);
    void nextFrame();
    void setColor(uint8_t r, uint8_t g, uint8_t b);

  private:
    uint8_t r, g, b;
};

#endif
