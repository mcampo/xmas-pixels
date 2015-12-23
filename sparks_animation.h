#ifndef SPARKS_ANIMATION_H
#define SPARKS_ANIMATION_H

#include "animations.h"

class SparksAnimation : public NeoPixelAnimation {

  public:
    SparksAnimation(Adafruit_NeoPixel *strip);
    void nextFrame();

  private:
    uint8_t r, g, b;
};

#endif
