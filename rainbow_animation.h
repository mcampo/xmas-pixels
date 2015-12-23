#ifndef RAINBOW_ANIMATION_H
#define RAINBOW_ANIMATION_H

#include "animations.h"

class RainbowAnimation : public NeoPixelAnimation {

  public:
    RainbowAnimation(Adafruit_NeoPixel *strip);
    void nextFrame();
};

#endif
